"""
Problem: LeetCode 130 - Surrounded Regions

Key Idea:
The problem is to capture 'O' cells that are not surrounded by 'X' cells in a given board. To solve this, we can use Depth-First Search (DFS) starting from the boundary 'O' cells. All the 'O' cells that are reachable from the boundary will be retained, and the rest will be changed to 'X'.

Time Complexity:
- In the worst case, we visit each cell in the board exactly once. Therefore, the time complexity is O(m * n), where m is the number of rows and n is the number of columns in the board.

Space Complexity:
- The space complexity is O(m * n), where m is the number of rows and n is the number of columns in the board. This is the maximum space required for the recursive call stack during DFS traversal.
"""


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        def dfs(row, col):
            if (
                row < 0
                or row >= len(board)
                or col < 0
                or col >= len(board[0])
                or board[row][col] != "O"
            ):
                return

            board[row][col] = "E"  # Mark as visited but not surrounded

            # Check adjacent cells
            dfs(row + 1, col)  # Check down
            dfs(row - 1, col)  # Check up
            dfs(row, col + 1)  # Check right
            dfs(row, col - 1)  # Check left

        # Traverse the boundary and mark connected 'O' cells as 'E'
        for row in range(len(board)):
            if board[row][0] == "O":
                dfs(row, 0)
            if board[row][len(board[0]) - 1] == "O":
                dfs(row, len(board[0]) - 1)

        for col in range(len(board[0])):
            if board[0][col] == "O":
                dfs(0, col)
            if board[len(board) - 1][col] == "O":
                dfs(len(board) - 1, col)

        # Mark internal 'O' cells as 'X' and restore 'E' cells to 'O'
        for row in range(len(board)):
            for col in range(len(board[0])):
                if board[row][col] == "O":
                    board[row][col] = "X"
                elif board[row][col] == "E":
                    board[row][col] = "O"
