/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

// Solution 1: BFS:
// ref: https://zxi.mytechroad.com/blog/graph/leetcode-1162-as-far-from-land-as-possible/
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        int result = -1;
        queue<pair<int, int>> q;
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>> dirs {{-1,0},{1,0},{0,-1},{0,1}};
        // stores the current farthest water area
        int currentFarthest = 0;

        // bfs all water areas
        while(!q.empty()){
            int currentSize = q.size();
            while(currentSize){
                auto p = q.front();
                q.pop();
                int y = p.first;
                int x = p.second;
                // if the area is water AND has been visited, update result
                if(grid[y][x] == 2){
                    result = max(result, currentFarthest);
                }

                // search 4 directions
                for(auto d : dirs){
                    int newY = y + d[0];
                    int newX = x + d[1];
                    // if the area is:
                    //   not water OR 
                    //   has been visited OR 
                    //   out of bound           ---> skip
                    if(newX < 0 || newX >= n || newY < 0 || newY >= m || grid[newY][newX] != 0){
                        continue;
                    }
                    // else, mark the area as visited water area
                    grid[newY][newX] = 2;
                    q.push({newY, newX});
                }

                --currentSize;
            }

            // Q: why increase at here?
            // A: becasue the logic behind this method is to let every land area expeands
            //    search the four directions in each round. So after each current size search, the
            //    expand size for every land area expand + 1.
            //    The search progress that last longer will enlarge this number as well.
            ++currentFarthest;
        }

        return result;
    }
};
// @lc code=end

