"""
Problem: LeetCode 329 - Longest Increasing Path in a Matrix

Key Idea:
The key idea is to use dynamic programming to find the longest increasing path in a matrix. We can start from each cell and perform a depth-first search (DFS) to explore the neighboring cells with larger values.

Time Complexity:
The time complexity is O(m * n), where 'm' is the number of rows and 'n' is the number of columns in the matrix. We visit each cell once and perform DFS from each cell.

Space Complexity:
The space complexity is O(m * n) as we use a memoization table 'dp' of the same size to store the results of subproblems.
"""


class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if not matrix:
            return 0

        # Define directions for moving to neighboring cells: up, down, left, right.
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        # Function to perform DFS from a given cell (i, j).
        def dfs(i, j):
            # If the result for this cell is already calculated, return it.
            if dp[i][j] != -1:
                return dp[i][j]

            # Initialize the result for this cell to 1 (counting itself).
            dp[i][j] = 1

            # Explore the four neighboring cells.
            for dx, dy in directions:
                x, y = i + dx, j + dy
                if 0 <= x < m and 0 <= y < n and matrix[x][y] > matrix[i][j]:
                    # If the neighboring cell has a larger value, perform DFS.
                    dp[i][j] = max(dp[i][j], 1 + dfs(x, y))

            return dp[i][j]

        m, n = len(matrix), len(matrix[0])
        dp = [[-1] * n for _ in range(m)]  # Memoization table to store results.
        max_path = 0

        # Start DFS from each cell in the matrix.
        for i in range(m):
            for j in range(n):
                max_path = max(max_path, dfs(i, j))

        return max_path
