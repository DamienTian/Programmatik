#pragma once
#ifndef MINHEAPSOURCE_H
#define MINHEAPSOURCE_H

template<class T> // 可使用多种数据类型作为模板
class MinHeap {
public:
    MinHeap(int maxSize);   // 构造空最小堆
    MinHeap(T* arr, int size);   // 从数组中构造堆
    MinHeap(MinHeap& m);    // 从其他最小堆构造
    ~MinHeap();

    // 节点位置计算
    inline int left(int index) { return 2 * index + 1; }
    inline int right(int index) { return 2 * index + 2; }
    inline int parent(int index) { return (index - 1) / 2; }

    // 返回目前MinHeap大小
    inline int size(){ return _currentSize + 1 ;}
    bool isEmpty();
    bool isFull();
    void insert(const T& t);
    bool pop(T& result);    // 推出第一个最小元素

    T* getMinHeap();
    // 显式数组
    void print();
private:
    T* _minheap = nullptr;  // 堆本体
    int _currentSize; // 目前大小
    int _maxSize;   // 最大容量
    void shiftDown(const int index, const int end); // 向下调整堆以维持堆的层级
    void shiftUp(int index); // 向上调整堆以维持堆的层级
};

#endif