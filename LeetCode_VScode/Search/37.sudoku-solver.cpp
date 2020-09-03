/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
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

// Solution 1: DFS + backtracking
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // initialize
        // Q: why size in 10 but not 9
        elementUsedRow = vector<vector<bool>>(9, vector<bool>(10, false));
        elementUsedCol = vector<vector<bool>>(9, vector<bool>(10, false));
        elementUsedBox = vector<vector<bool>>(9, vector<bool>(10, false));

        // search exist element
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                // if the element is used
                if(board[i][j] != '.'){
                    // find which element it is
                    int n = board[i][j] - '0';
                    // calculate the index for box
                    int bi = i / 3;
                    int bj = j / 3;
                    // mark the element as used
                    elementUsedRow[i][n] = true;
                    elementUsedCol[j][n] = true;
                    // NOTE: box index = bi * 3 + bj
                    elementUsedBox[bi * 3 + bj][n] = true;
                }
            }
        }

        int startI = 0, startJ = 0;
        fill(board, startI, startJ);
    }

private:
    // those stores the element that use in each row, column and box
    vector<vector<bool>> elementUsedRow, elementUsedCol, elementUsedBox;

    bool fill(vector<vector<char>>& board, int i, int j){
        // if we done with searching all cells, return true
        if(i == 9)  return true;

        // calculate next cell position for searching
        int nj = (j + 1) % 9;
        int ni = (nj == 0) ? i + 1 : i; // go to next row it j(x) reaches the end

        // if board[i][j] not empty, search the next cell
        if(board[i][j] != '.')  return fill(board, ni, nj);

        // search nums 1-9 ([0, 8] + 1)
        for(int n = 1; n <= 9; ++n){
            int bi = i / 3;
            int bj = j / 3;
            int boxIndex = bi * 3 + bj;
            // search if the number wasn't used in row, column and box
            if(!elementUsedRow[i][n] && !elementUsedCol[j][n] && !elementUsedBox[boxIndex][n]){
                elementUsedRow[i][n] = true;
                elementUsedCol[j][n] = true;
                elementUsedBox[boxIndex][n] = true;
                board[i][j] = n + '0';  // fill the cell
                
                // if the board was successfully filled, return true;
                if(fill(board, ni, nj)) return true;

                // otherwise, restore the board and continue search number
                board[i][j] = '.';
                elementUsedBox[boxIndex][n] = false;
                elementUsedCol[j][n] = false;
                elementUsedRow[i][n] = false;
            }
        }

        return false;
    }
};
// @lc code=end

