// Ref: 1) https://blog.csdn.net/happyaaaaaaaaaaa/article/details/50897809
//      2) http://zxi.mytechroad.com/blog/searching/leetcode-39-combination-sum/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Pruning the list to save searching time
        sort(candidates.begin(), candidates.end());
        
        // Stores the final answer
        vector<vector<int>> answer;
        
        // Stores the each possible combination
        vector<int> current;
        
        // DFS search to get the each current answer   
        dfs(answer, current, 0, candidates, target);
        
        return answer;
    }
    
    void dfs(vector<vector<int>>& answer, vector<int>& current, int index, vector<int>& candidates, int target){
        if(target == 0){
            answer.push_back(current);
            return;
        }
        
        // can only starts from the given index in order to save time of searching
        //  (since everything behind the index is lower than the number at the index)
        for (int i = index; i < candidates.size(); ++i){
            if (candidates[i] <= target){
                current.push_back(candidates[i]);
                // Since we can use the duplicated number in a combination
                // the index can still be the same
                dfs(answer, current, i, candidates, target - candidates[i]);
                current.pop_back();
            }
        }
    }
};