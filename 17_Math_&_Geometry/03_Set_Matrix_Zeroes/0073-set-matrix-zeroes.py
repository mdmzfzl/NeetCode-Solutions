"""
Problem: LeetCode 73 - Set Matrix Zeroes

Key Idea:
To set the entire row and column to zeros if an element in the matrix is zero, we can use two sets to keep track of the rows and columns that need to be set to zero. We iterate through the matrix and mark the corresponding rows and columns in the sets. Then, we iterate through the matrix again and set the elements to zero if their row or column is marked.

Time Complexity:
- We iterate through the matrix twice: once to mark the rows and columns and once to set the elements to zero. Therefore, the time complexity is O(m * n), where m is the number of rows and n is the number of columns in the matrix.

Space Complexity:
- The space complexity is O(m + n), as we use two sets to store the rows and columns that need to be set to zero.
"""


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows, cols = len(matrix), len(matrix[0])
        zero_rows, zero_cols = set(), set()

        # Mark rows and columns that need to be set to zero
        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == 0:
                    zero_rows.add(i)
                    zero_cols.add(j)

        # Set elements to zero based on marked rows and columns
        for i in range(rows):
            for j in range(cols):
                if i in zero_rows or j in zero_cols:
                    matrix[i][j] = 0
