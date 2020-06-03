/*
 * @lc app=leetcode id=996 lang=cpp
 *
 * [996] Number of Squareful Arrays
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ref: https://zxi.mytechroad.com/blog/searching/leetcode-996-number-of-squareful-arrays/

// Solution 1: DFS
// class Solution1
// {
// public:
//     int numSquarefulPerms(vector<int> &A)
//     {
//         // sort to deal with duplicated element
//         sort(A.begin(), A.end());

//         // vector<vector<int>> result;
//         int result = 0;
//         vector<int> current;
//         vector<bool> visited(A.size(), false);
//         dfs(A, result, current, visited);
//         return result;
//     }

// private:
//     bool isPrefectSquare(int x, int y)
//     {
//         int s = sqrt(x + y);
//         return s * s == x + y;
//     }

//     void dfs(const vector<int> A, int &result, vector<int> &current, vector<bool> &visited)
//     {
//         if (current.size() == A.size())
//         {
//             ++result;
//             return;
//         }

//         // dfs each number by indices
//         for (int i = 0; i < A.size(); ++i)
//         {
//             // if the index has been visited in this level, skip
//             if (visited[i])
//                 continue;

//             // if duplicate exist, skip
//             // NOTE: the idea of skipping the duplicated:
//             //      1) if this is not the first element of array
//             //  AND 2) if the previous SAME element has not been used for search before
//             if (i > 0 && !visited[i - 1] && A[i - 1] == A[i])
//                 continue;

//             // if the permutation with new element is not perfect square, skip
//             if (!current.empty() && !isPrefectSquare(current.back(), A[i]))
//                 continue;

//             visited[i] = true;
//             current.push_back(A[i]);
//             dfs(A, result, current, visited);
//             visited[i] = false;
//             current.pop_back();
//         }
//     }
// };

// Solution 2: DP
// NOTE: see this problem as a hamiltonian path problem
class Solution
{
public:
    int numSquarefulPerms(vector<int> &A)
    {
        int n = A.size();
        sort(begin(A), end(A));
        int result = 0;
        // use a 2d array to store if each pair of number is perfect square
        vector<vector<int>> squareTable(n, vector<int>(n));
        // dp[s][i]: number of way to reach state s which end with int A[i]
        vector<vector<int>> dp(1 << n, vector<int>(n));

        // build up the squareTable
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i == j)  continue;
                int r = sqrt(A[i] + A[j]);
                if (r * r == A[i] + A[j]){
                    squareTable[i][j] = 1;
                }
            }
        }

        // preprocess the dp table 
        for(int i = 0; i < n; ++i){
            // remove duplicated
            if(i == 0 || A[i] != A[i - 1]){
                dp[(1 << i)][i] = 1;
            }
        }

        // search through each state
        for(int s = 0; s < (1 << n); ++s){
            // for each possible last int i
            for(int i = 0; i < n; ++i){
                // if we can't reach i from state s, skip
                // ex. s = 001 (1 << 0), i = 1;
                if(!dp[s][i])   continue;
                // search all the possible pair
                for(int j = 0; j < n; ++j){
                    // if not perfect square, skip
                    if(!squareTable[i][j])  continue;
                    // if this int has been visited, skip
                    if(s & (1 << j))    continue;
                    // if the previous int A[j-1] has not been used and A[j] == A[j-1], skip (remove duplicate)
                    if(j > 0 && !(s & (1 << (j - 1))) && A[j - 1] == A[j])  continue;

                    dp[s | (1 << j)][j] += dp[s][i];
                }
            }
        }

        // contruct answer
        for(int i = 0; i < n; ++i)
            result += dp[(1 << n) - 1][i];

        return result;
    }
};


// @lc code=end
