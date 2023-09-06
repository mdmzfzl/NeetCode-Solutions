"""
Problem: LeetCode 286 - Walls and Gates

Key Idea:
The problem is to fill each empty room (represented by INF) with the distance to the nearest gate. This can be approached using Breadth-First Search (BFS), where the gates are the starting points and the empty rooms are visited layer by layer.

Time Complexity:
- Each cell is visited at most once, and BFS takes linear time proportional to the number of cells in the grid. Therefore, the time complexity is O(m * n), where m is the number of rows and n is the number of columns in the grid.

Space Complexity:
- The space complexity is O(m * n), where m is the number of rows and n is the number of columns in the grid. This is the maximum space required for the BFS queue and visited set.
"""


class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        if not rooms:
            return

        rows, cols = len(rooms), len(rooms[0])
        gates = [(i, j) for i in range(rows) for j in range(cols) if rooms[i][j] == 0]
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        for gate_row, gate_col in gates:
            visited = set()  # To track visited cells in BFS
            queue = deque([(gate_row, gate_col, 0)])

            while queue:
                row, col, distance = queue.popleft()
                rooms[row][col] = min(rooms[row][col], distance)
                visited.add((row, col))

                for dr, dc in directions:
                    new_row, new_col = row + dr, col + dc

                    if (
                        0 <= new_row < rows
                        and 0 <= new_col < cols
                        and rooms[new_row][new_col] != -1
                        and (new_row, new_col) not in visited
                    ):
                        queue.append((new_row, new_col, distance + 1))
                        visited.add((new_row, new_col))
