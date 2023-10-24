/*
Problem: LeetCode 329 - Longest Increasing Path in a Matrix

Description:
Given an m x n integers matrix, return the length of the longest increasing path in the matrix.
From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

Intuition:
To find the longest increasing path in the matrix, we can use dynamic programming. The problem can be broken down into smaller subproblems, where we find the longest increasing path starting from each cell in the matrix.

Approach:
1. Create a 2D dp array of the same size as the matrix to store the length of the longest increasing path starting from each cell.
2. Initialize the dp array to all zeros, as the minimum path length from any cell is 1 (the cell itself).
3. For each cell (i, j) in the matrix, perform a depth-first search (DFS) to find the longest increasing path starting from that cell.
4. During the DFS, for each neighboring cell (x, y) of the current cell (i, j) that is within bounds and has a greater value than the current cell, calculate the length of the longest increasing path starting from (x, y) using the DFS, and update the dp array accordingly.
5. Return the maximum value in the dp array as the result, which represents the length of the longest increasing path in the matrix.

Time Complexity:
The time complexity is O(m * n), where m and n are the dimensions of the matrix, as we perform a DFS starting from each cell once.

Space Complexity:
The space complexity is also O(m * n) as we use a 2D dp array to store the length of the longest increasing path for each cell.

Dynamic Programming:
- Subproblem: The subproblem is finding the longest increasing path starting from each cell in the matrix.
- Recurrence Relation: For each neighboring cell (x, y) of the current cell (i, j) that is within bounds and has a greater value than the current cell, calculate the length of the longest increasing path starting from (x, y) using the DFS, and update the dp array accordingly.
- Base Case: Initialize the dp array to all zeros, as the minimum path length from any cell is 1 (the cell itself).
*/

class Solution {
  public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0)); // dp[i][j] stores the longest increasing path starting at position (i, j)
        int longestPath = 0;

        // Iterate through each element in the matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Find the longest increasing path starting at position (i, j) and update the longestPath
                longestPath = max(longestPath, dfs(matrix, dp, i, j));
            }
        }

        return longestPath; // Return the overall longest increasing path
    }

    // Helper function to find the longest increasing path starting at position (i, j)
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j) {
        if (dp[i][j] > 0) {
            return dp[i][j];    // If the result is already calculated, return it from the dp array
        }

        int m = matrix.size();
        int n = matrix[0].size();
        int longest = 1; // The minimum length is 1, considering the current element
        // Check the four neighbors
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (const auto &dir : directions) {
            int x = i + dir.first;
            int y = j + dir.second;

            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                // If the neighbor is within the matrix bounds and has a greater value, calculate the longest path recursively
                longest = max(longest, 1 + dfs(matrix, dp, x, y));
            }
        }

        dp[i][j] = longest; // Save the result in the dp array to avoid redundant computations
        return longest;
    }
};