// MinHeap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "MinHeapSource.h"
#include "MinHeapSource.cpp"    // include source file because the template class has to include definition explict in the main
#include <iostream>

using namespace std;

int main() {

	int a[] = { 9, 6, 5, 4, 3, 2, 1 };
    MinHeap<int> heap(a, 7);

    cout << "Init the heap" << endl;
    heap.print();

    int p;
    heap.pop(p);
    cout << "Pop smallest element: " << p << endl;
    heap.print();

    cout << "Insert 10" << endl;
	heap.insert(10);
	heap.print();

    return 0;
}

/*
运行结果：
Init the heap
1       3       2       4       6       9       5
Pop smallest element: 1
2       3       5       4       6       9
Insert 10
2       3       5       4       6       9       10
*/