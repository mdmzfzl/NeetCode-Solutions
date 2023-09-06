"""
Problem: LeetCode 994 - Rotting Oranges

Key Idea:
The problem is to determine the minimum time needed for all oranges to become rotten, considering that rotten oranges can also infect adjacent fresh oranges in each minute. We can model this problem using Breadth-First Search (BFS), where each minute corresponds to a level of the BFS traversal.

Time Complexity:
- In the worst case, all cells are fresh oranges, and each cell can be visited at most once. Therefore, the BFS traversal has a time complexity of O(m * n), where m is the number of rows and n is the number of columns in the grid.

Space Complexity:
- The space complexity is O(m * n), where m is the number of rows and n is the number of columns in the grid. This is the maximum space required for the BFS queue and visited set.
"""


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        if not grid:
            return -1

        rows, cols = len(grid), len(grid[0])
        fresh_count = 0  # Count of fresh oranges
        rotten = deque()  # Queue to store coordinates of rotten oranges
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]  # Possible adjacent cells

        # Initialize the queue with coordinates of rotten oranges
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 2:
                    rotten.append((row, col))
                elif grid[row][col] == 1:
                    fresh_count += 1

        minutes = 0  # Timer

        while rotten:
            level_size = len(rotten)

            for _ in range(level_size):
                row, col = rotten.popleft()

                for dr, dc in directions:
                    new_row, new_col = row + dr, col + dc

                    # Check if the new cell is within bounds and has a fresh orange
                    if (
                        0 <= new_row < rows
                        and 0 <= new_col < cols
                        and grid[new_row][new_col] == 1
                    ):
                        grid[new_row][new_col] = 2  # Infect the fresh orange
                        fresh_count -= 1
                        rotten.append((new_row, new_col))

            if rotten:
                minutes += 1

        # If there are fresh oranges left, return -1; otherwise, return the elapsed minutes
        return minutes if fresh_count == 0 else -1
