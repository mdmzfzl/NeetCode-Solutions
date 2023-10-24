/*
Problem: LeetCode 73 - Set Matrix Zeroes

Description:
Given an m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Intuition:
To solve this problem in-place, we can use the first row and the first column of the matrix to keep track of which rows and columns need to be set to 0. We use two additional boolean variables to track whether the first row and first column themselves need to be set to 0.

Approach:
1. First, we check if the first row and the first column need to be set to 0 by iterating through the first row and first column of the matrix.
2. Then, we traverse the matrix starting from the second row and second column.
   - If the current element matrix[i][j] is 0, we set the corresponding elements in the first row and first column to 0.
3. Next, we traverse the matrix again from the second row and second column and set the elements to 0 if the corresponding element in the first row or first column is 0.
4. Finally, we handle the first row and first column based on the boolean variables we used to track them.

Time Complexity:
The time complexity of this approach is O(m * n), where m is the number of rows and n is the number of columns in the matrix. We traverse the matrix twice.

Space Complexity:
The space complexity is O(1) as we are using the first row and first column of the matrix to keep track of which rows and columns need to be set to 0.
*/

class Solution {
  public:
    void setZeroes(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowZero = false;
        bool firstColZero = false;

        // Check if first row needs to be set to 0
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // Check if first column needs to be set to 0
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Mark rows and columns that need to be set to 0 in the first row and first column
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set elements to 0 based on the first row and first column
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Set first row and first column to 0 if needed
        if (firstRowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        if (firstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};