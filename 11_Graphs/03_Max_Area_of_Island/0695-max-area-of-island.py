"""
Problem: LeetCode 695 - Max Area of Island

Key Idea:
The problem is to find the maximum area of an island in a grid where 1 represents land and 0 represents water. We can solve this using Depth-First Search (DFS) to traverse each cell of the grid and identify connected land cells forming an island.

Time Complexity:
- In the worst case, we visit each cell in the grid exactly once. Therefore, the time complexity is O(m * n), where m is the number of rows and n is the number of columns in the grid.

Space Complexity:
- The space complexity is O(m * n), where m is the number of rows and n is the number of columns in the grid. This is the maximum space required for the recursive call stack during DFS traversal.
"""


class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        def dfs(row, col):
            if (
                row < 0
                or row >= len(grid)
                or col < 0
                or col >= len(grid[0])
                or grid[row][col] == 0
            ):
                return 0

            grid[row][col] = 0  # Mark as visited
            area = 1

            area += dfs(row + 1, col)  # Check down
            area += dfs(row - 1, col)  # Check up
            area += dfs(row, col + 1)  # Check right
            area += dfs(row, col - 1)  # Check left

            return area

        max_area = 0
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col] == 1:
                    max_area = max(max_area, dfs(row, col))

        return max_area
