"""
Problem: LeetCode 74 - Search a 2D Matrix

Key Idea:
Since both the rows and columns in the input 2D matrix are sorted, we can treat the matrix as a one-dimensional sorted array and perform binary search to find the target element. We can map the 2D indices to the corresponding index in the 1D array and then apply binary search to locate the target element.

Time Complexity:
The time complexity of this solution is O(log(m*n)), where m is the number of rows and n is the number of columns in the matrix. The binary search process reduces the search space by half in each step.

Space Complexity:
The space complexity is O(1), as no extra space is used other than a few variables to keep track of indices and values.
"""


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False

        rows, cols = len(matrix), len(matrix[0])
        left, right = 0, rows * cols - 1

        while left <= right:
            mid = left + (right - left) // 2
            num = matrix[mid // cols][mid % cols]

            if num == target:
                return True
            elif num < target:
                left = mid + 1
            else:
                right = mid - 1

        return False
