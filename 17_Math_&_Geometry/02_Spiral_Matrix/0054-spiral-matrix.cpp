/*
Problem: LeetCode 54 - Spiral Matrix

Description:
Given an m x n matrix, return all elements of the matrix in spiral order.

Intuition:
We can traverse the matrix in a spiral order by simulating the movement in four directions: right, down, left, and up.
To keep track of the visited elements, we can maintain four boundaries: top, bottom, left, and right.

Approach:
1. Initialize four variables: top = 0, bottom = m - 1, left = 0, right = n - 1.
2. Loop until top <= bottom and left <= right:
   - Traverse from left to right along the top boundary and increment top.
   - Traverse from top to bottom along the right boundary and decrement right.
   - Traverse from right to left along the bottom boundary and decrement bottom.
   - Traverse from bottom to top along the left boundary and increment left.
3. Keep adding the elements encountered during the traversal to the result vector.

Time Complexity:
The time complexity of this approach is O(m * n), where m is the number of rows and n is the number of columns in the matrix.

Space Complexity:
The space complexity is O(1) as we are not using any additional space.
*/

class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> result;

        if (matrix.empty()) {
            return result;
        }

        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            // Traverse from left to right along the top boundary
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }

            top++;

            // Traverse from top to bottom along the right boundary
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }

            right--;

            // Traverse from right to left along the bottom boundary
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }

                bottom--;
            }

            // Traverse from bottom to top along the left boundary
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }

                left++;
            }
        }

        return result;
    }
};