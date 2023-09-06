"""
Problem: LeetCode 417 - Pacific Atlantic Water Flow

Key Idea:
The problem is to find the cells in a matrix where water can flow from both the Pacific Ocean and the Atlantic Ocean. We can solve this using Depth-First Search (DFS) starting from the ocean borders. Each cell that can be reached from both oceans will be added to the final result.

Time Complexity:
- We perform two separate DFS traversals from the ocean borders, one for the Pacific Ocean and one for the Atlantic Ocean. In the worst case, we visit each cell in the matrix exactly once during each DFS traversal.
- Therefore, the time complexity is O(m * n), where m is the number of rows and n is the number of columns in the matrix.

Space Complexity:
- The space complexity is O(m * n), where m is the number of rows and n is the number of columns in the matrix. This is the maximum space required for the recursive call stack during DFS traversal.
"""


class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights:
            return []

        rows, cols = len(heights), len(heights[0])
        pacific_reachable = set()
        atlantic_reachable = set()

        def dfs(r, c, reachable):
            reachable.add((r, c))
            for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                nr, nc = r + dr, c + dc
                if (
                    0 <= nr < rows
                    and 0 <= nc < cols
                    and (nr, nc) not in reachable
                    and heights[nr][nc] >= heights[r][c]
                ):
                    dfs(nr, nc, reachable)

        for r in range(rows):
            dfs(r, 0, pacific_reachable)
            dfs(r, cols - 1, atlantic_reachable)

        for c in range(cols):
            dfs(0, c, pacific_reachable)
            dfs(rows - 1, c, atlantic_reachable)

        return list(pacific_reachable & atlantic_reachable)
