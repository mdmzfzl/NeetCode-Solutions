/*
Problem: LeetCode 36 - Valid Sudoku

Description:
Given a 9 x 9 Sudoku board, determine if it is a valid Sudoku. The board is only partially filled, and each digit from 1 to 9 must appear exactly once in each row, column, and 3 x 3 sub-grid.

Intuition:
To check if a Sudoku board is valid, we need to verify that each digit appears exactly once in each row, column, and 3 x 3 sub-grid. We can use three separate 2D arrays to keep track of the digits already used in each row, column, and sub-grid.

Approach:
1. Initialize three 2D arrays, usedRows, usedCols, and usedSubgrids, with all values set to 0.
2. Iterate through each cell in the Sudoku board:
   - If the current cell is not empty:
     - Convert the character to an integer and subtract 1 to get the corresponding number index.
     - Calculate the sub-grid index based on the current cell's position.
     - Check if the number is already used in the current row, column, or sub-grid by looking at the corresponding index in the usedRows, usedCols, and usedSubgrids arrays.
     - If the number is already used, return false as the Sudoku board is not valid.
     - Mark the number as used in the current row, column, and sub-grid by setting the corresponding index to 1 in the usedRows, usedCols, and usedSubgrids arrays.
3. If all cells pass the checks, return true as the Sudoku board is valid.

Time Complexity:
The time complexity of this approach is O(1) since the Sudoku board has a fixed size of 9 x 9, and the iteration is constant.

Space Complexity:
The space complexity is O(1) since the arrays used for tracking the used digits (usedRows, usedCols, and usedSubgrids) have a fixed size of 9 x 9.
*/

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int usedRows[9][9] = {0};
        int usedCols[9][9] = {0};
        int usedSubgrids[9][9] = {0};

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int subgridIndex = (i / 3) * 3 + j / 3;

                    if (usedRows[i][num] || usedCols[j][num] || usedSubgrids[subgridIndex][num]) {
                        return false;
                    }

                    usedRows[i][num] = usedCols[j][num] = usedSubgrids[subgridIndex][num] = 1;
                }
            }
        }

        return true;
    }
};