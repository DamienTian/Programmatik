/*
 * @lc app=leetcode id=943 lang=cpp
 *
 * [943] Find the Shortest Superstring
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// prototypes
void constructCostTable(vector<string> &A, vector<vector<int>> &cost);

// ref: https://zxi.mytechroad.com/blog/searching/leetcode-943-find-the-shortest-superstring/

// Solution 1: dfs
//  NOTE: this problem will very likely be TLE,
//        becasue this porblem is more suitable to be solved by DP
class Solution1
{
public:
    string shortestSuperstring(vector<string> &A)
    {
        // first, construct the cost_ table;
        constructCostTable(A, cost_);

        // then do DFS search
        int currentLen = 0;                // the current len of superstring
        int currentIndex = 0;              // the current search index of superstring
        int used = 0;                      // use this int to record the usage of each word (binary operation)
        vector<int> currentPath(A.size()); // NOTE: need to assign this before run dfs OR nothing will be assigned
        dfs(A, currentLen, currentIndex, used, currentPath);

        // after dfs, construct the answer
        string result = A[bestPath_[0]];
        for (int i = 1; i < bestPath_.size(); ++i)
        {
            int first = bestPath_[i - 1];
            int second = bestPath_[i];
            result += A[second].substr(A[second].length() - cost_[first][second]);
        }

        return result;
    }

private:
    // a vector which records the extra length of each word connect with another word
    vector<vector<int>> cost_;
    // the current best len
    int bestLen_ = INT_MAX;
    // the best path (int represents the index of word in the A)
    vector<int> bestPath_;

    void dfs(const vector<string> A, int len, int index, int used, vector<int> &path)
    {
        if (len >= bestLen_)
            return;
        if (index == A.size())
        {
            bestLen_ = len;
            bestPath_ = path;
            return;
        }

        for (int i = 0; i < A.size(); ++i)
        {
            // this means the word has been used
            if (used & (2 << i))
                continue;
            // if not, record this word index in to path (let word A[i] be index of current superstring)
            path[index] = i;
            // recursive call;
            dfs(A,
                // len depends on the index of the search
                index == 0 ? A[i].length() : len + cost_[path[index - 1]][i],
                index + 1,
                used | (2 << i), // mark this position as searched
                path);
        }
    }

    
// a common function for constructiong cost table.
// the cost table a vector which records the extra
// length of each word connect with another word
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
};


// Solution 2: DP
// NOTE: OneNote 里有详细的演算与笔记，需要可随时翻阅
class Solution2
{
public:
    string shortestSuperstring(vector<string> &A)
    {
        // as DFS solution, the cost table need to be calculated
        vector<vector<int>> cost(A.size(), vector<int>(A.size()));
        for (int i = 0; i < A.size(); ++i)
        {
            for (int j = 0; j < A.size(); ++j)
            {
                cost[i][j] = A[j].length();
                for (int x = 1; x <= min(A[i].length(), A[j].length()); ++x)
                {
                    if (A[i].substr(A[i].size() - x) == A[j].substr(0, x))
                    {
                        cost[i][j] = A[j].length() - x;
                    }
                }
            }
        }

        // dp[s][i]: shortest path that travels s and end with word i.
        //  s: the word index that has been traveled (use binary to represent)
        //  i: end with word of index i
        // NOTE: use INT_MAX/2 to prevent overflow
        vector<vector<int>> dp(1 << A.size(), vector<int>(A.size(), INT_MAX / 2));

        // parent[s][i]: the parent that word i in path s
        vector<vector<int>> parent(1 << A.size(), vector<int>(A.size(), -1));

        // first assign the length of for each word that the superstring starts from it
        for (int i = 0; i < A.size(); ++i)
            dp[1 << i][i] = A[i].length();

        // loop through all path (combination method)
        for (int s = 1; s < (1 << A.size()); ++s)
        {
            for (int i = 0; i < A.size(); ++i)
            {
                // if the current position i is not in current combination, pass
                if (!(s & (1 << i)))
                    continue;
                // take the previous path (delete the current search index)
                int prevS = s & ~(1 << i);
                // go over each word (i) that could be in front of the word j
                for (int j = 0; j < A.size(); ++j)
                {
                    // take the smallest superstring len and update dp and parent
                    if (dp[prevS][j] + cost[j][i] < dp[s][i])
                    {
                        dp[s][i] = dp[prevS][j] + cost[j][i];
                        parent[s][i] = j;
                    }
                }
            }
        }

        // after the dp search, format the result:
        // 1) find the word index that is the end of shortest superstring from dp[1 << Asize() - 1]
        auto smallestIter = min_element(begin(dp.back()), end(dp.back()));
        int j = smallestIter - begin(dp.back()); // the word index

        // 2) init the search map (this is a int indicates all word has been searched)
        int searchMap = (1 << A.size()) - 1;

        // 3) constructing answer
        string result = "";
        // while there still exist word to search
        while (searchMap)
        {
            // find j's parent
            int i = parent[searchMap][j];
            // if j has no parent
            if (i < 0)
                result += A[j];
            else
                result += A[j].substr(A[j].length() - cost[i][j]);
            // update j and searchMap after find them
            searchMap &= ~(1 << j);
            j = i;
        }
        return result;
    }
};


class Solution {
public:
  string shortestSuperstring(vector<string>& A) {        
    const int n = A.size();
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        g[i][j] = A[j].length();
        for (int k = 1; k <= min(A[i].length(), A[j].length()); ++k)
          if (A[i].substr(A[i].size() - k) == A[j].substr(0, k)) 
            g[i][j] = A[j].length() - k;
      }
    
    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX / 2));
    vector<vector<int>> parent(1 << n, vector<int>(n, -1));
    
    for (int i = 0; i < n; ++i) dp[1 << i][i] = A[i].length();
    
    for (int s = 1; s < (1 << n); ++s) {
      for (int j = 0; j < n; ++j) {
        if (!(s & (1 << j))) continue;
        int ps = s & ~(1 << j);
        for (int i = 0; i < n; ++i) {
          if (dp[ps][i] + g[i][j] < dp[s][j]) {
            dp[s][j] = dp[ps][i] + g[i][j];
            parent[s][j] = i;
          }
        }
      }
    }
    
    auto it = min_element(begin(dp.back()), end(dp.back()));
    int j = it - begin(dp.back());
    int s = (1 << n) - 1;
    string ans;
    while (s) {
      int i = parent[s][j];
      if (i < 0) ans += A[j];
      else ans += A[j].substr(A[j].length() - g[i][j]);
      s &= ~(1 << j);
      j = i;
    }
    return ans;
  } 
};
// @lc code=end
