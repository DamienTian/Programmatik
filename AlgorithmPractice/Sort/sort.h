#ifndef SORT_H
#define SORT_H

#include <vector>

using namespace std;

// Sort algorithm for vector
// ref: https://www.cnblogs.com/onepixel/p/7674659.html
class Sort{
public:
    Sort();
    ~Sort();

    vector<int> bubbleSort(vector<int>);
    vector<int> selectionSort(vector<int>);
    vector<int> insertionSort(vector<int>);
    vector<int> mergeSort(vector<int>);
    vector<int> quickSort(vector<int>&, int, int);
    vector<int> heapSort(vector<int>);
};

#endif