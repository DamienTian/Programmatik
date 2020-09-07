#include "MinHeapSource.h"
#include <iostream>

template<class T>
MinHeap<T>::MinHeap(int maxSize) {
    _maxSize = maxSize;
    _minheap = new T[_maxSize];
    if (_minheap == nullptr) {
        std::cerr << "MinHeap Memory allocation failed" << std::endl;
        exit(-1);
    }
    _currentSize = 0;
}

template<class T>
MinHeap<T>::MinHeap(T* arr, int size) {
    _maxSize = size;
    _minheap = new T[_maxSize];
    if (_minheap == nullptr) {
        std::cerr << "MinHeap Memory allocation failed" << std::endl;
        exit(-1);
    }
    // 逐个赋值
    _currentSize = size;
    for (int i = 0; i < _currentSize; ++i) {
        _minheap[i] = arr[i];
    }

    // 利用下滑算法形成最小堆
    // NOTE: 以为curPos指向的时下标，所以要减2
    int curPos = (_currentSize - 2) / 2;
    while (curPos >= 0) {
        shiftDown(curPos, _currentSize - 1);
        --curPos;
    }
}

template<class T>
MinHeap<T>::MinHeap(MinHeap& m) {
    _minheap = new T[_maxSize]; // 申请新的空间
    if (_minheap == nullptr) {
        std::cerr << "MinHeap Memory allocation failed" << std::endl;
            exit(-1);
    }
    for (int i = 0; i < _maxSize; ++i)
        *_minheap[i] = *m._minheap[i];
    _currentSize = m._currentSize;
    _maxSize = m._maxSize;
}

template<class T>
MinHeap<T>::~MinHeap() {
    if(_minheap != nullptr)
        delete []_minheap;
}

template<class T>
bool MinHeap<T>::isEmpty() {
    return _currentSize == 0;
}

template<class T>
bool MinHeap<T>::isFull() {
    return _currentSize == _maxSize;
}

template<class T>
T* MinHeap<T>::getMinHeap() {
    return _minheap;
}

template<class T>
void MinHeap<T>::insert(const T& t) {
    if (isFull()) {
        std::cerr << "the MinHeap is full, can't insert more element" << std::endl;
        return;
    }
    _minheap[_currentSize] = t;
    shiftUp(_currentSize);    // 自下而上调整最小堆
    ++_currentSize;
}

template<class T>
bool MinHeap<T>::pop(T& result) {
    if (_currentSize > _maxSize) {
        std::cerr << "the MinHeap is empty, no element to pop" << std::endl;
        return false;
    }
    result = _minheap[0];
    // 将当前的第一个元素替换为最后一个元素，然后自上而下调整为最小堆
    _minheap[0] = _minheap[_currentSize - 1];
    _currentSize--;
    shiftDown(0, _currentSize - 1);  // 自上而下调整为最小堆
    return true;
}

// 自下而上调整最小堆（修复 insert）
template<class T>
void MinHeap<T>::shiftUp(int index) {
    if (isEmpty()) return;

    int current = index;
    int parentC = parent(current);
    // 若抵达顶点，返回
    if (current <= 0)    return;
    // 若父节点大于当前节点时，递归交换
    if (_minheap[parentC] > _minheap[current]) {
        int temp = _minheap[parentC];
        _minheap[parentC] = _minheap[current];
        _minheap[current] = temp;
        shiftUp(parentC);
    }
}

// 自上而下调整最小堆（修复 pop）
template<class T>
void MinHeap<T>::shiftDown(const int index, const int end) {
    if (isEmpty()) return;

    int current = index;    // 保留当前索引
    int leftC = left(current);

    // 若左子节点或右子节点超出范围，返回
    if (leftC > end)
        return;

    // 比较左右子节点（主要和左子节点作比较）
    if (leftC < end && _minheap[leftC] > _minheap[leftC + 1]) 
        ++leftC;

    // 若当现结点大于左子节点时，递归交换
    if (_minheap[current] > _minheap[leftC]) {
        int temp = _minheap[current];
        _minheap[index] = _minheap[leftC];
        _minheap[leftC] = temp;
        shiftDown(leftC, end);
    }
}

template<class T>
void MinHeap<T>::print() {
    for (int i = 0; i < _currentSize; ++i) {
        std::cout << _minheap[i] << "\t";
    }
    std::cout << std::endl;
}




