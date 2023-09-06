"""
Problem: LeetCode 54 - Spiral Matrix

Key Idea:
To traverse a matrix in a spiral order, we can iterate through each layer of the matrix and extract the elements in the desired order: top row, right column, bottom row, and left column. We update the boundaries of each layer as we traverse.

Time Complexity:
- We visit each element in the matrix exactly once. Therefore, the time complexity is O(m * n), where m is the number of rows and n is the number of columns in the matrix.

Space Complexity:
- The space complexity is O(1), as we use a constant amount of space to store the result.
"""


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []

        rows, cols = len(matrix), len(matrix[0])
        result = []

        # Define the boundaries of the current layer
        top, bottom, left, right = 0, rows - 1, 0, cols - 1

        while top <= bottom and left <= right:
            # Traverse the top row
            for j in range(left, right + 1):
                result.append(matrix[top][j])
            top += 1

            # Traverse the right column
            for i in range(top, bottom + 1):
                result.append(matrix[i][right])
            right -= 1

            # Traverse the bottom row
            if top <= bottom:  # Avoid duplicate traversal
                for j in range(right, left - 1, -1):
                    result.append(matrix[bottom][j])
                bottom -= 1

            # Traverse the left column
            if left <= right:  # Avoid duplicate traversal
                for i in range(bottom, top - 1, -1):
                    result.append(matrix[i][left])
                left += 1

        return result
