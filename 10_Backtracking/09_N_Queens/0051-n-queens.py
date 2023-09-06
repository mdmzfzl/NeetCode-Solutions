"""
Problem: LeetCode 51 - N-Queens

Key Idea:
To solve the N-Queens problem, we can use backtracking. Starting from each row, we try placing a queen in each column of that row and recursively move on to the next row. If a valid placement is found, we continue the process. We keep track of the board state and the positions of the queens to avoid conflicts.

Time Complexity:
- In the worst case, we explore all possible combinations of queen placements, leading to a time complexity of O(N!), where N is the size of the board (number of rows/columns).

Space Complexity:
- The space complexity is O(N^2), as we need to store the board state and the positions of the queens.
"""


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def is_safe(row, col):
            # Check for conflicts with previous rows
            for prev_row in range(row):
                if board[prev_row][col] == "Q":
                    return False
                if (
                    col - (row - prev_row) >= 0
                    and board[prev_row][col - (row - prev_row)] == "Q"
                ):
                    return False
                if (
                    col + (row - prev_row) < n
                    and board[prev_row][col + (row - prev_row)] == "Q"
                ):
                    return False
            return True

        def place_queen(row):
            if row == n:
                result.append(["".join(row) for row in board])
                return

            for col in range(n):
                if is_safe(row, col):
                    board[row][col] = "Q"
                    place_queen(row + 1)
                    board[row][col] = "."

        board = [["." for _ in range(n)] for _ in range(n)]
        result = []
        place_queen(0)
        return result


# class Solution:
#     def solveNQueens(self, n: int) -> List[List[str]]:
#         result = []  # List to store solutions
#         board = [['.'] * n for _ in range(n)]  # Chessboard representation
#         left_diagonal = [False] * (2 * n - 1)  # Left diagonals availability
#         right_diagonal = [False] * (2 * n - 1)  # Right diagonals availability
#         column = [False] * n  # Columns availability

#         def backtrack(row):
#             if row == n:
#                 solution = ["".join(row) for row in board]  # Convert the board to a solution format
#                 result.append(solution)
#                 return

#             for col in range(n):
#                 # Check if placing a queen in the current position is valid
#                 if column[col] or left_diagonal[row - col] or right_diagonal[row + col]:
#                     continue

#                 # Place a queen and mark unavailable positions
#                 board[row][col] = 'Q'
#                 column[col] = left_diagonal[row - col] = right_diagonal[row + col] = True

#                 # Move to the next row
#                 backtrack(row + 1)

#                 # Backtrack: Reset the board and availability
#                 board[row][col] = '.'
#                 column[col] = left_diagonal[row - col] = right_diagonal[row + col] = False

#         backtrack(0)  # Start the backtracking process from the first row
#         return result
