/*
Problem: LeetCode 74 - Search a 2D Matrix

Description:
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
- Integers in each row are sorted in ascending order from left to right.
- Integers in each column are sorted in ascending order from top to bottom.

Intuition:
To search for a value efficiently in the given matrix, we can utilize the sorted property of the matrix and perform binary search on both rows and columns. By narrowing down the search space, we can quickly find the target value or determine that it does not exist.

Approach:
1. Initialize the number of rows (m) and columns (n) in the matrix.
2. Perform a binary search on the rows:
   - Set the left pointer to 0 and the right pointer to m - 1.
   - While the left pointer is less than or equal to the right pointer:
     - Calculate the middle row index as (left + right) / 2.
     - If the target value is found in the middle row, return true.
     - If the target value is less than the first element of the middle row, update the right pointer to middle - 1.
     - If the target value is greater than the last element of the middle row, update the left pointer to middle + 1.
3. Perform a binary search on the columns:
   - Set the top pointer to 0 and the bottom pointer to n - 1.
   - While the top pointer is less than or equal to the bottom pointer:
     - Calculate the middle column index as (top + bottom) / 2.
     - If the target value is found in the middle column, return true.
     - If the target value is less than the first element of the middle column, update the bottom pointer to middle - 1.
     - If the target value is greater than the last element of the middle column, update the top pointer to middle + 1.
4. If the target value is not found after both binary searches, return false.

Time Complexity:
The time complexity is O(log m + log n), where m is the number of rows and n is the number of columns in the matrix. Binary search is performed on both rows and columns.

Space Complexity:
The space complexity is O(1), as the algorithm uses a constant amount of extra space.
*/

class Solution {
  public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int leftRow = 0;
        int rightRow = m - 1;
        int topCol = 0;
        int bottomCol = n - 1;

        while (leftRow <= rightRow) {
            int midRow = leftRow + (rightRow - leftRow) / 2;

            if (matrix[midRow][0] <= target && target <= matrix[midRow][n - 1]) {
                while (topCol <= bottomCol) {
                    int midCol = topCol + (bottomCol - topCol) / 2;

                    if (matrix[midRow][midCol] == target) {
                        return true;
                    } else if (matrix[midRow][midCol] < target) {
                        topCol = midCol + 1;
                    } else {
                        bottomCol = midCol - 1;
                    }
                }

                break;
            } else if (matrix[midRow][0] > target) {
                rightRow = midRow - 1;
            } else {
                leftRow = midRow + 1;
            }
        }

        return false;
    }
};