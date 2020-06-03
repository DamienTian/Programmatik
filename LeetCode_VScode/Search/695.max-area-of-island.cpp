/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Solution 1: DFS
// ref: https://zxi.mytechroad.com/blog/graph/leetcode-695-max-area-of-island/
// class Solution {
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         for(int i = 0; i < m; ++i){
//             for(int j = 0; j < n; ++j){
//                 result = max(result, dfs(grid, i, j, m, n));
//             }
//         }

//         return result;
//     }

// private:
//     int result = 0;

//     int dfs(vector<vector<int>>& grid, int y, int x, int m, int n){
//         if(x < 0 || y < 0 || x >= n || y >= m || grid[y][x] == 0)
//             return 0;

//         grid[y][x] = 0;
//         return dfs(grid, y - 1, x, m , n) +
//             dfs(grid, y + 1, x, m , n) +
//             dfs(grid, y, x - 1, m , n) +
//             dfs(grid, y, x + 1, m , n) + 1;
//     }
// };

// Solution 2: BFS
// ref: https://www.cnblogs.com/grandyang/p/7712724.html
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int result = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // only push the val of 1 into the q
                if(grid[i][j] != 1) continue;
                queue<pair<int, int>> q{{{i,j}}};

                // update the visited
                visited[i][j] = 1;
                int temp = 0;
                while (!q.empty())
                {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    // visited[y][x] = 1;
                    result = max(result, ++temp);

                    // add new pos to search
                    for(auto d : dir){
                        int newY = y + d.first;
                        int newX = x + d.second;

                        // only add the qualified pos into the queue
                        if(newX < 0 || newY < 0 || newX >= n || newY >= m || grid[newY][newX] == 0|| visited[newY][newX] == 1) 
                            continue;
                        visited[newY][newX] = 1;
                        q.push({newY, newX});
                    }
                } 
            }
        }

        return result;
    }
private:
    vector<pair<int, int>> dir {{-1,0}, {1,0}, {0,-1}, {0,1}};
};
// @lc code=end
