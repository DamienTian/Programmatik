/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Solution 1: dfs
class SolutionDFS {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        dfs(result, current, n, n);
        return result;
    }

    void dfs(vector<string>& result, string& current, int left, int right){
        if(left == 0 && right == 0){
            result.push_back(current);
            return;
        }

        if(left){
            current += '(';
            dfs(result, current, left - 1, right);
            current.pop_back();
        }
        if(right && right > left){
            current += ')';
            dfs(result, current, left, right - 1);
            current.pop_back();
        }
    }
};
// @lc code=end

