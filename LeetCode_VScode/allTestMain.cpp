#include <iostream>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;


void printVectorOfVectorInt(vector<vector<int>> vv);
void printVectorInt(vector<int> v);

// Author: Huahua, running time: 4 ms, 8.8 MB
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        preprocess = vector<vector<int>>(m, vector<int>(n));

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                preprocess[i][j] = (j == 0) ? matrix[i][j] : (preprocess[i][j - 1] + matrix[i][j]);
            }
        }

        cout << "The preprocess table: " << endl;
        printVectorOfVectorInt(preprocess);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == row2 && col1 == col2)    return 0;

        int result = 0;

        for(int i = row1; i <= row2; ++i){
            result += (col1 == 0) ? preprocess[i][col2] : (preprocess[i][col2] - preprocess[i][col1 - 1]);
        }

        return result;
    }

private:
    // this 2D vector stores the preprocessed matrix
    // which each row represents the sum from pos 0 to n
    // each position = sum(0 : this position)
    vector<vector<int>> preprocess;
};

int main()
{
    vector<int>m1 {3,0,1,4,2};
    vector<int>m2 {5,6,3,2,1};
    vector<int>m3 {1,2,0,1,5};
    vector<int>m4 {4,1,0,1,7};
    vector<int>m5 {1,0,3,0,5};
    vector<vector<int>> m{m1, m2, m3, m4, m5};
    NumMatrix nm(m);

    return 0;
}

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

void constructCostTable(vector<string> &A, vector<vector<int>> &cost)
{
    const int m = A.size();
    cost = vector<vector<int>>(m, vector<int>(m));

    // construct the cost table
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            // pruning: if i == j, pass
            if (i == j)
                continue;

            cost[i][j] = A[j].length();
            // NOTE:
            /* Q1: why x = 1? 
                   A1: because A[i].size() - x cannot be 0, 
                        OR A[i].substr(A[i].size() - x) can't be reached.
    
                   Q2: why pick the minimum len among A[i] and A[j]
                   A2: becasue the maximum overlap depends on the shorter word.
                */
            for (int x = 1; x < min(A[i].length(), A[j].length()); ++x)
            {
                if (A[i].substr(A[i].size() - x) == A[j].substr(0, x))
                {
                    cost[i][j] = A[j].size() - x;
                }
            }
        }
    }
}