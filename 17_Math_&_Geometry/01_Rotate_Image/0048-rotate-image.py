"""
Problem: LeetCode 48 - Rotate Image

Key Idea:
To rotate the given matrix in-place, we can perform a series of swaps. We start by swapping elements symmetrically along the diagonal, and then swap elements symmetrically along the vertical midline. This process rotates the matrix by 90 degrees clockwise.

Time Complexity:
- We perform swaps for each element in the matrix exactly once. Therefore, the time complexity is O(n^2), where n is the number of rows/columns in the matrix.

Space Complexity:
- The space complexity is O(1), as we perform swaps in-place without using any additional space.
"""


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)

        # Transpose the matrix
        for i in range(n):
            for j in range(i, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        # Reverse each row
        for i in range(n):
            matrix[i].reverse()
