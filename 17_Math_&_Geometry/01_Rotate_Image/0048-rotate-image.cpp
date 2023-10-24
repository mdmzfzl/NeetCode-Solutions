/*
Problem: LeetCode 48 - Rotate Image

Description:
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

Intuition:
To rotate the image by 90 degrees clockwise, we can perform two steps:
1. Transpose the matrix (rows become columns, and vice versa).
2. Reverse each row of the transposed matrix.

Approach:
1. Transpose the matrix in-place:
   - Iterate over the upper triangle of the matrix (i.e., elements above the main diagonal).
   - Swap the element at matrix[i][j] with matrix[j][i].
2. Reverse each row of the transposed matrix:
   - For each row, use two pointers (start and end) and swap the elements until they meet in the middle.

Time Complexity:
The time complexity of this approach is O(n^2), where n is the number of rows (or columns) in the matrix.

Space Complexity:
The space complexity is O(1) as we are performing the rotation in-place without using any additional space.
*/

class Solution {
  public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();

        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row of the transposed matrix
        for (int i = 0; i < n; i++) {
            int start = 0;
            int end = n - 1;

            while (start < end) {
                swap(matrix[i][start], matrix[i][end]);
                start++;
                end--;
            }
        }
    }
};