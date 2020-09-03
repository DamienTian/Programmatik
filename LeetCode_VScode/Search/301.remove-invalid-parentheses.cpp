/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 */

// @lc code=start

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

// Solution 1: BFS
//  ref: https://www.cnblogs.com/grandyang/p/4944875.html
class SolutionBFS {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> visited {{s}};
        queue<string> q {{s}};
        bool found = false;

        while(!q.empty()){
            string t = q.front();
            q.pop();
            if(isValid(t)){
                result.push_back(t);
                found = true;
            }
            if(found)   continue;

            // remove each ( ) and put them into visited set
            for(int i = 0; i < t.length(); ++i){
                if(t[i] != '(' && t[i] != ')')  continue;
                string newT = t.substr(0, i) + t.substr(i + 1);
                if(!visited.count(newT)){
                    visited.insert(newT);
                    q.push(newT);
                }
            }
        }

        return result;
    }

    bool isValid(string s){
        int left = 0, right = 0;
        for(char c : s){
            if(c == '(')
                ++left;
            else if(c == ')')
                ++right;
            if(right > left)
                return false;
        }
        return left == right ? true : false;
    }
};

// Solution 2: DFS
//  ref: https://zxi.mytechroad.com/blog/searching/leetcode-301-remove-invalid-parentheses/
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {

        // count how many parenphase need to remove
        int left = 0, right = 0;
        for(char c : s){
            left += (c == '(');
            if(left == 0)
                right += (c == ')');
            else
                left -= (c == ')');
        }

        // the index that dfs start to start to search
        int start = 0;
        dfs(s, start,left, right);

        return result;
    }

private:
    vector<string> result;

    void dfs(string& s, int start, int left, int right){
        if(left == 0 && right == 0){
            if(isValid(s))  result.push_back(s);
            return;
        }

        for(int i = start; i < s.size(); ++i){
            // remove duplicated answer
            if(i != start && s[i] == s[i-1])    continue;
            
            if(s[i] == ')' || s[i] == '('){
                string curr = s.substr(0, i) + s.substr(i + 1);
                // remove right
                if(right > 0 && s[i] == ')')
                    dfs(curr, i, left, right - 1);
                if(left > 0 && s[i] == '(')
                    dfs(curr, i, left - 1, right);
            }
        }
    }
    bool isValid(string s){
        int left = 0, right = 0;
        for(char c : s){
            if(c == '(')
                ++left;
            else if(c == ')')
                ++right;
            if(right > left)
                return false;
        }
        return left == right ? true : false;
    }
};

// @lc code=end