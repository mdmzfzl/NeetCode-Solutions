"""
Problem: LeetCode 79 - Word Search

Key Idea:
To determine if a given word exists in the 2D board, we can perform a depth-first search (DFS) from each cell in the board. At each cell, we check if the current character of the word matches the character in the cell. If it does, we mark the cell as visited, recursively search its neighboring cells, and backtrack if the search is unsuccessful. We repeat this process for all cells in the board.

Time Complexity:
- In the worst case, for each cell, we perform a DFS with a maximum depth of the length of the word, which leads to a time complexity of O(m * n * 4^k), where m and n are the dimensions of the board and k is the length of the word.

Space Complexity:
- The space complexity is O(k), where k is the length of the word, as it represents the maximum depth of the recursive call stack.
"""


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs(row, col, index):
            if index == len(word):
                return True

            if (
                row < 0
                or row >= len(board)
                or col < 0
                or col >= len(board[0])
                or board[row][col] != word[index]
            ):
                return False

            original_char = board[row][col]
            board[row][col] = "#"  # Mark the cell as visited

            found = (
                dfs(row + 1, col, index + 1)
                or dfs(row - 1, col, index + 1)
                or dfs(row, col + 1, index + 1)
                or dfs(row, col - 1, index + 1)
            )

            board[row][col] = original_char  # Backtrack

            return found

        for row in range(len(board)):
            for col in range(len(board[0])):
                if board[row][col] == word[0] and dfs(row, col, 0):
                    return True

        return False
