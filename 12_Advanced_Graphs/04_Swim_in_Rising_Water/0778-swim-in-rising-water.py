"""
Problem: LeetCode 778 - Swim in Rising Water

Key Idea:
The problem can be approached using a binary search along with depth-first search (DFS). We can perform a binary search on the range of possible time values, from the minimum value (0) to the maximum value (N * N). For each time value, we perform a DFS to check if it's possible to reach the bottom-right cell from the top-left cell without encountering cells with heights greater than the current time value. If a valid path exists, we narrow down the search to the left half of the time range; otherwise, we search in the right half.

Time Complexity:
- The binary search takes O(log(N^2)) time.
- The DFS visits each cell once and takes O(N^2) time.
- Overall, the time complexity is O(N^2 * log(N^2)).

Space Complexity:
- The DFS uses the call stack, which takes O(N^2) space.
- Additional data structures used in the algorithm take constant space.
- Therefore, the space complexity is O(N^2).
"""


class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        def dfs(i, j, visited, time):
            if i < 0 or i >= N or j < 0 or j >= N or visited[i][j] or grid[i][j] > time:
                return False
            if i == N - 1 and j == N - 1:
                return True
            visited[i][j] = True
            return (
                dfs(i + 1, j, visited, time)
                or dfs(i - 1, j, visited, time)
                or dfs(i, j + 1, visited, time)
                or dfs(i, j - 1, visited, time)
            )

        N = len(grid)
        left, right = 0, N * N

        while left < right:
            mid = (left + right) // 2
            visited = [[False] * N for _ in range(N)]
            if dfs(0, 0, visited, mid):
                right = mid
            else:
                left = mid + 1

        return left
