/*
Problem: LeetCode 51 - N-Queens

Description:
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Intuition:
The N-Queens problem can be solved using backtracking. The idea is to place queens on the board row by row, ensuring that no two queens attack each other. We can use a recursive approach to explore all possible placements and backtrack when conflicts arise.

Approach:
1. Define a vector of vectors `board` to represent the chessboard.
2. Define a vector `queens` to store the column index of the queens placed in each row.
3. Define a helper function `backtrack`:
   - If the current row is equal to `n`, it means all queens have been placed successfully. Add the current `board` configuration to the `result` vector.
   - Otherwise:
     - Iterate through the columns from 0 to `n`:
       - Check if placing a queen at the current position (row, col) is valid (i.e., no conflicts with previously placed queens).
       - If it is valid, mark the current position on the `board` as a queen ('Q') and add the current column to `queens`.
       - Recursively call `backtrack` for the next row.
       - Remove the queen from the `board` and backtrack by removing the last queen from `queens`.
4. Call the `backtrack` function with the initial row 0.
5. Return the `result` vector containing all distinct board configurations.

Time Complexity:
The time complexity is O(N!), where N is the size of the chessboard (n x n). This is because there are N! possible placements for the queens.

Space Complexity:
The space complexity is O(N), where N is the size of the chessboard (n x n). This is because we store the `board`, `queens`, and the `result` vector.
*/

class Solution {
  public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));  // Initialize the board with empty spaces
        vector<int> queens;  // Column indices of the queens in each row
        backtrack(n, 0, board, queens, result);  // Call the backtrack function to generate all valid solutions
        return result;
    }

  private:
    // Backtracking function to generate all valid solutions
    void backtrack(int n, int row, vector<string> &board, vector<int> &queens, vector<vector<string>> &result) {
        if (row == n) {
            result.push_back(board);  // Add the current valid solution to the result
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isValidPlacement(row, col, queens)) {
                board[row][col] = 'Q';  // Place the queen at the current position
                queens.push_back(col);  // Store the column index of the queen in the current row
                // Recursively call for the next row
                backtrack(n, row + 1, board, queens, result);
                queens.pop_back();  // Remove the last queen from the current row
                board[row][col] = '.';  // Restore the empty space
            }
        }
    }

    // Function to check if placing a queen at the current position is valid
    bool isValidPlacement(int row, int col, const vector<int> &queens) {
        for (int i = 0; i < queens.size(); ++i) {
            int rowDiff = abs(row - i);
            int colDiff = abs(col - queens[i]);

            if (rowDiff == 0 || colDiff == 0 || rowDiff == colDiff) {
                return false;  // Found a queen in the same row, same column, or diagonal
            }
        }

        return true;  // No conflicting queens found, placement is valid
    }
};