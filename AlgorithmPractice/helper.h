#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <vector>

using namespace std;

void printVectorOfVectorInt(vector<vector<int>> vv)
{
    cout << "--- a vector of vector<int> ---" << endl;
    for (auto v : vv)
    {
        cout << "[";
        for (int n : v)
        {
            cout << n << ", ";
        }
        cout << "]" << endl;
    }
    cout << "-------------------------------" << endl;
}

void printVectorInt(vector<int> v)
{
    cout << " [";
    for (int n : v)
    {
        cout << n << ", ";
    }
    cout << "] ";
}

#endif