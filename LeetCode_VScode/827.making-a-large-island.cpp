/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

// Solution: DFS
// ref: https://zxi.mytechroad.com/blog/graph/leetcode-827-making-a-large-island/
// class Solution
// {
// public:
//     int largestIsland(vector<vector<int>> &grid)
//     {
//         m_ = grid.size();
//         n_ = grid[0].size();
//         g_ = &grid;
//         // color index
//         int color = 1;
//         // calculate each connected area (loop 1)
//         for (int i = 0; i < m_; ++i)
//         {
//             for (int j = 0; j < n_; ++j)
//             {
//                 if (grid[i][j] == 1)
//                 {
//                     ++color;
//                     // mark the pos with the color
//                     colors[color] = calculateArea(i, j, color);
//                     result = max(colors[color], result);
//                 }
//             }
//         }
//         // calculated the maximum area by changing one 0 (loop 0)
//         for (int i = 0; i < m_; ++i)
//         {
//             for (int j = 0; j < n_; ++j)
//             {
//                 if (grid[i][j] == 0)
//                 {
//                     int connectArea = 1;
//                     // find the area of each connect side
//                     // Q: why use set?
//                     // A: remove duplicated area, since a '0' could next to a same area on more than one side.
//                     for (int color : set<int>{getColor(i - 1, j), getColor(i + 1, j),
//                                             getColor(i, j - 1), getColor(i, j + 1)})
//                     {
//                         // connect all area
//                         connectArea += colors[color];
//                     }
//                     result = max(connectArea, result);
//                 }
//             }
//         }
//         return result;
//     }

// private:
//     // size of the grid
//     int m_, n_;
//     // pointer to the grid
//     vector<vector<int>> *g_;
//     // a hash table that store the max area of each color section
//     unordered_map<int, int> colors;
//     int result = 0;

//     // calculate the area of the colored area (use the method from LC 200)
//     int calculateArea(int i, int j, int color)
//     {
//         if (i < 0 || j < 0 || i >= m_ || j >= n_ || (*g_)[i][j] != 1) // != 1 means the place has been marked
//             return 0;
//         // mark the pos with color
//         (*g_)[i][j] = color;
//         return 1 + calculateArea(i - 1, j, color) + calculateArea(i + 1, j, color) + calculateArea(i, j - 1, color) + calculateArea(i, j + 1, color);
//     }

//     // get the color of each position
//     int getColor(int i, int j)
//     {
//         return (i < 0 || j < 0 || i >= m_ || j >= n_) ? 0 : (*g_)[i][j];
//     }
// };

// Solution 2: BFS
// NOTE: Pass all testcase but TLE at the last one
class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        m_ = grid.size();
        n_ = grid[0].size();
        int result = 0;
        int hasZero = false;    // does the graph has a 0?
        for (int i = 0; i < m_; ++i)
        {
            for (int j = 0; j < n_; ++j)
            {
                if (grid[i][j] == 1)
                    continue;
                // the queue for BFS
                // NOTE: use std::pair will cause TLE
                queue<pair<int, int>> q{{{i, j}}};
                // a 2d vector to store visited
                vector<vector<bool>> visited(m_, vector<bool>(n_, false));
                visited[i][j] = true;
                // mark the pos as 1 for now
                grid[i][j] = 1;
                // storing the current result
                int area = 1;
                hasZero = true;
                while (!q.empty())
                {
                    int currentI = q.front().first;
                    int currentJ = q.front().second;
                    q.pop();
                    for (auto d : dir)
                    {
                        int newI = currentI + d.first;
                        int newJ = currentJ + d.second;
                        if (newI < 0 || newJ < 0 || newI >= m_ || newJ >= n_ ||
                            grid[newI][newJ] != 1 || visited[newI][newJ])
                        {
                            continue;
                        }
                        visited[newI][newJ] = true;
                        q.push({newI, newJ});
                        ++area;
                    }
                }
                grid[i][j] = 0;
                result = max(area, result);
            }
        }

        return hasZero ? result : m_ * n_;
    }

private:
    int m_, n_;
    // stores all the possible moving direction
    vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
// @lc code=end
