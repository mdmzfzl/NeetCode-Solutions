"""
Problem: LeetCode 62 - Unique Paths

Key Idea:
The key idea is to use dynamic programming to count the number of unique paths from the top-left corner to the bottom-right corner of a grid. We create a dynamic programming grid 'dp', where dp[i][j] represents the number of unique paths to reach cell (i, j) from the top-left corner.

Time Complexity:
The time complexity is O(m*n), where 'm' is the number of rows and 'n' is the number of columns in the grid. We iterate through each cell once to fill in the dp array.

Space Complexity:
The space complexity is O(m*n) because we use an additional dp grid of the same size as the input grid to store the results.
"""


class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # Initialize a 2D dp grid of size m x n with all values set to 1.
        dp = [[1] * n for _ in range(m)]

        # Fill in the dp grid using dynamic programming.
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

        # The value in dp[m-1][n-1] represents the number of unique paths.
        return dp[m - 1][n - 1]
