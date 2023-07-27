/*
Problem: LeetCode 62 - Unique Paths

Description:
A robot is located at the top-left corner of a m x n grid. The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid.
How many possible unique paths are there?

Intuition:
To find the number of unique paths, we can use dynamic programming.
The problem can be broken down into smaller subproblems by considering different positions in the grid.
We can build the solution by counting the number of unique paths to reach each position.

Approach:
1. Initialize a 2D array dp of size m x n, where dp[i][j] represents the number of unique paths to reach position (i, j).
2. Initialize the first row and first column of dp to 1, as there is only one way to reach each position in the first row and first column.
3. Iterate through the grid starting from position (1, 1):
   - For each position (i, j), set dp[i][j] as the sum of dp[i-1][j] and dp[i][j-1].
     This means that the number of unique paths to reach (i, j) is the sum of the paths from the above position (i-1, j) and the left position (i, j-1).
4. Return dp[m-1][n-1], which represents the number of unique paths to reach the bottom-right corner of the grid.

Time Complexity:
The time complexity is O(m * n), where m and n are the dimensions of the grid.

Space Complexity:
The space complexity is O(m * n), as we use a 2D array to store the number of unique paths for each position.

Dynamic Programming:
- Subproblem: The subproblem is finding the number of unique paths to reach each position in the grid.
- Recurrence Relation: dp[i][j] = dp[i-1][j] + dp[i][j-1].
- Base Case: Initialize the first row and first column of dp to 1, as there is only one way to reach each position in the first row and first column.
*/

class Solution {
  public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1)); // Number of unique paths to reach each position

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; // Number of unique paths = paths from above + paths from left
            }
        }

        return dp[m - 1][n - 1]; // Number of unique paths to reach the bottom-right corner
    }
};