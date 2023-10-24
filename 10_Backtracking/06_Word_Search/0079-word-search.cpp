/*
Problem: LeetCode 79 - Word Search

Description:
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
The same letter cell may not be used more than once.

Intuition:
To determine if a given word exists in the grid, we can use a backtracking approach. We start from each cell and explore all possible paths to find the word.
At each step, we check if the current cell matches the current character of the word. If it does, we continue the search in the neighboring cells until the word is found or all paths have been explored.

Approach:
1. Iterate through each cell in the grid:
   - If the current cell matches the first character of the word, call the `backtrack` function.
2. Define a helper function `backtrack`:
   - If the index of the current character equals the length of the word, return true (the entire word has been found).
   - If the current cell is out of bounds or does not match the current character, return false.
   - Mark the current cell as visited (e.g., change its value to a special character to indicate it has been used).
   - Recursively call `backtrack` for the neighboring cells (up, down, left, right) with the next character of the word.
   - Restore the original value of the current cell (backtrack).
3. Return the result obtained from the `backtrack` function.

Time Complexity:
The time complexity is O(M * N * 4^L), where M is the number of rows, N is the number of columns, and L is the length of the word. In the worst case, we explore all possible paths from each cell.

Space Complexity:
The space complexity is O(L), where L is the length of the word. This is the maximum depth of the recursion stack.
*/

class Solution {
  public:
    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] && backtrack(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

  private:
    bool backtrack(vector<vector<char>> &board, const string &word, int row, int col, int index) {
        if (index == word.length()) {
            return true;  // The entire word has been found
        }

        int m = board.size();
        int n = board[0].size();

        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != word[index]) {
            return false;  // Out of bounds or the current cell does not match the current character
        }

        char temp = board[row][col];
        board[row][col] = '#';  // Mark the current cell as visited
        // Recursively call for the neighboring cells
        bool found = backtrack(board, word, row - 1, col, index + 1) ||
                     backtrack(board, word, row + 1, col, index + 1) ||
                     backtrack(board, word, row, col - 1, index + 1) ||
                     backtrack(board, word, row, col + 1, index + 1);
        board[row][col] = temp;  // Mark the current cell as unvisited (backtrack)
        return found;
    }
};