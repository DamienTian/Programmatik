// Follows the similar rule of no.39

/* Time Complexity: O(2^n) 
    Note: since we use the sorting to pruning, the actural performance will be much better than theory.
   Space Comlexity: O(kn) -> O(n)
    Note: k is the number of combination
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Solution 1: Cheat version
// This solution use 'set' to prevent any duplicated answer
class Solution1 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // use set to prevent the duplication answer
        set<vector<int>> answer;
        vector<int> current;
        
        // Pruning the list by sorting
        sort(candidates.begin(), candidates.end());
        
        dfs(candidates, target, 0, answer, current);
        
        return vector<vector<int>>(answer.begin(), answer.end());
    }
    
    void dfs(vector<int>& candidates, int target, int index, set<vector<int>>& answer, vector<int>& current){
        if (target == 0){
            answer.insert(current);
            return;
        }
        
        for (int i = index; i < candidates.size(); ++i){
            // if the number is bigger than target, that means everything behind 
            // that number is larger than the number, we can just skip them
            if (candidates[i] > target){
                return;
            }
            
            current.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, answer, current);
            current.pop_back();
        }
    }
};

// Solution 2
// This use a if statement to check if the number should be added into the combination
class Solution2 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // use set to prevent the duplication answer
        vector<vector<int>> answer;
        vector<int> current;
        
        // Pruning the list by sorting
        sort(candidates.begin(), candidates.end());
        
        dfs(candidates, target, 0, answer, current);
        
        return answer;
    }
    
    void dfs(vector<int>& candidates, int target, int index, vector<vector<int>>& answer, vector<int>& current){
        if (target == 0){
            answer.push_back(current);
            return;
        }
        
        for (int i = index; i < candidates.size(); ++i){
            // if the number is bigger than target, that means everything behind 
            // that number is larger than the number, we can just skip them
            if (candidates[i] > target){
                return;
            }

            // detect if we should add the number into the answer,
            // this step prevents the redundent answer
            if (i > index && candidates[i] == candidates[i - 1]){
                continue;
            }

            current.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, answer, current);
            current.pop_back();
        }
    }
};