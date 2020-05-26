#include <iostream>
#include "sort.h"
#include "../helper.h"

int main(){
    vector<int> test {1,5,3,4,2,0,6};
    cout << "Before Sort: ";
    printVectorInt(test);
    cout << endl;

    Sort s;

    cout << "After Bubble Sort: ";
    printVectorInt(s.bubbleSort(test));
    cout << endl;

    cout << "After Selection Sort: ";
    printVectorInt(s.selectionSort(test));
    cout << endl;

    cout << "After Insertion Sort: ";
    printVectorInt(s.selectionSort(test));
    cout << endl;

    cout << "After Merge Sort: ";
    printVectorInt(s.mergeSort(test));
    cout << endl;

    cout << "After Quick Sort: ";
    printVectorInt(s.quickSort(test, 0, test.size() - 1));
    cout << endl;

    printVectorInt(test);

    return 0;
}