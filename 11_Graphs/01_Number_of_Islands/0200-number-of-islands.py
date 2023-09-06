"""
Problem: LeetCode 200 - Number of Islands

Key Idea:
The problem is to count the number of islands in a 2D grid where '1' represents land and '0' represents water. We can solve this problem using Depth-First Search (DFS) algorithm. For each cell that contains '1', we perform DFS to explore all adjacent land cells and mark them as visited by changing their value to '0'. This way, we count each connected component of '1's as a separate island.

Time Complexity:
- In the worst case, we visit each cell in the grid once. Therefore, the time complexity is O(m * n), where m is the number of rows and n is the number of columns in the grid.

Space Complexity:
- The space complexity is O(m * n), where m is the number of rows and n is the number of columns in the grid. This is the maximum space required for the call stack during DFS traversal.
"""


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        rows, cols = len(grid), len(grid[0])
        count = 0

        def dfs(row, col):
            if (
                row < 0
                or row >= rows
                or col < 0
                or col >= cols
                or grid[row][col] == "0"
            ):
                return

            grid[row][col] = "0"  # Mark the cell as visited
            directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

            for dr, dc in directions:
                dfs(row + dr, col + dc)

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == "1":
                    count += 1
                    dfs(i, j)

        return count
