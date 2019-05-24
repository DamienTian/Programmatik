#include "../includes.h"

// ref: http://zxi.mytechroad.com/blog/searching/leetcode-200-number-of-islands/
// Time complexity: O(mn)
// Running time: 6 ms

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // do the empty check first
        if(grid.empty()){
            return 0;
        }
        
        // find the size of the grid map
        int height = grid.size();
        int width = grid[0].size();
        
        // answer
        int ans = 0;
        
        // loop through all the grid
        for (int x = 0; x < width; ++x){
            for (int y = 0; y < height; ++y){
                // Trick: use ASCII code to find the difference
                ans += grid[y][x] - '0';
                // search recursively until no adjacent 1's
                dfs(grid, x, y, width, height);
            }
        }
        
        return ans;
    }
    
    void dfs(vector<vector<char>>& grid, int x, int y, int width, int height){
        // if the gird position is out of map OR the grid is 0, return
        if (x < 0 || y < 0 || x >= width || y >= height || grid[y][x] == '0'){
            return;
        }
        
        // else, change it to '0'
        grid[y][x] = '0';
        
        // continue search other four directions
        dfs(grid, x - 1, y, width, height);
        dfs(grid, x, y - 1, width, height);
        dfs(grid, x + 1, y, width, height);
        dfs(grid, x, y + 1, width, height);
        
    }
};