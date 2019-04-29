// Reference: http://bangbingsyb.blogspot.com/2014/11/leetcode-generate-parentheses.html
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        string combination;
        // 
        helper(combination, 0, 0, n, results);
        return results;
    }
    
    void helper(string &combination, int nleft, int nright, int n, vector<string> &results){
        if (nleft == n && nright == n){
            results.push_back(combination);
            cout << "Adding: " << combination << endl;
            return;
        }
        
        if (nleft < n){
            combination+='(';
            cout << combination << endl;
            helper(combination, nleft+1, nright, n, results);
            cout << "Pop at first if: " << combination.back() << "     current level: " << nleft << "  " << nright << endl;
            combination.pop_back();
        }
        
        if (nright < nleft){
            combination+=')';
            cout << combination << endl;
            helper(combination, nleft, nright+1, n, results);
            cout << "Pop at second if: " << combination.back() << "     current level: " << nleft << "  " << nright << endl;
            combination.pop_back();
        }
    }
};

void printStringVector(vector<string> res)
{
    for (int j = 0; j < res.size(); ++j)
    {
        cout << res[j] << "\t";
    }
    cout << endl;
}

int main(){
    Solution s;
    vector<string> r = s.generateParenthesis(3);
    printStringVector(r);
}