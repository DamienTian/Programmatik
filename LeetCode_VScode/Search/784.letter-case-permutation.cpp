/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

// Solution 1: dfs
//  ref: https://zxi.mytechroad.com/blog/searching/leetcode-784-letter-case-permutation/
class Solution1
{
public:
    vector<string> letterCasePermutation(string S)
    {
        if (S == "")
            return {};

        // second parameter is the position that 
        dfs(S, 0);
        return result;
    }

private:
    vector<string> result;
    // string *visited;
    // string current;

    void dfs(string& s, int pos)
    {
        if (pos == s.size())
        {
            result.push_back(s);
            return;
        }

        // move to the very end of the string
        dfs(s, pos + 1);

        if(s[pos] - '0' > 9){
            s[pos] = islower(s[pos]) ? toupper(s[pos]) : tolower(s[pos]);
            dfs(s, pos + 1);
        }
    }
};

// Solution 2: iterative
class Solution
{
public:
    vector<string> letterCasePermutation(string S)
    {
        vector<string> result{""};
        for(char c : S){
            for(int k = result.size(); k > 0; --k){
                string temp = result.front();
                result.erase(result.begin());
                if(isalpha(c)){
                    char tc = c;
                    for(int i = 0; i <= 1; ++i){
                        string t = temp;
                        tc = isupper(tc) ? tolower(tc) : toupper(c);
                        t += tc;
                        result.push_back(t);
                    }
                }
                else{
                    string t = temp + c;
                    result.push_back(t);
                }
            }
        }
        return result;
    }
};
// @lc code=end
