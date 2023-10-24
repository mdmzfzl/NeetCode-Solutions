/*
Problem: LeetCode 130 - Surrounded Regions

Description:
Given an m x n matrix board containing 'X' and 'O', capture all regions that are surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Intuition:
To capture the surrounded regions, we need to identify the regions that are connected to the borders of the matrix. The regions that are not connected to the borders are the ones that need to be captured.
We can use a depth-first search (DFS) approach to identify and mark the regions that are connected to the borders, and then iterate through the matrix to capture the remaining regions.

Approach:
1. Traverse the borders of the matrix and perform a DFS to mark the regions that are connected to the borders:
   - If a cell is 'O', perform a DFS to mark all its neighboring 'O' cells as connected to the border.
2. Iterate through the entire matrix:
   - If a cell is 'O' and not marked as connected to the border, capture it by changing it to 'X'.
   - If a cell is marked as connected to the border, restore it to 'O'.
3. The regions that are not marked as connected to the border are the captured regions.

Time Complexity:
The time complexity is O(m * n), where m is the number of rows and n is the number of columns in the matrix. We visit each cell once.

Space Complexity:
The space complexity is O(m * n), where m is the number of rows and n is the number of columns in the matrix. This is the space used for the recursion stack during the DFS traversal.
*/

class Solution {
  public:
    void solve(vector<vector<char>> &board) {
        if (board.empty()) {
            return;
        }

        int m = board.size();
        int n = board[0].size();

        // Traverse the top and bottom borders
        for (int col = 0; col < n; ++col) {
            dfs(board, 0, col);
            dfs(board, m - 1, col);
        }

        // Traverse the left and right borders
        for (int row = 0; row < m; ++row) {
            dfs(board, row, 0);
            dfs(board, row, n - 1);
        }

        // Capture the remaining regions
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';  // Capture the region
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';  // Restore the region
                }
            }
        }
    }

  private:
    void dfs(vector<vector<char>> &board, int row, int col) {
        int m = board.size();
        int n = board[0].size();

        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != 'O') {
            return;
        }

        board[row][col] = '#';  // Mark the cell as connected to the border
        dfs(board, row - 1, col);  // Up
        dfs(board, row + 1, col);  // Down
        dfs(board, row, col - 1);  // Left
        dfs(board, row, col + 1);  // Right
    }
};