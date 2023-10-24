/*
Problem: LeetCode 73 - Set Matrix Zeroes

Key Idea:
The key idea is to use the first row and the first column to store information about whether the corresponding row or column should be zeroed.

Approach:
1. Initialize two boolean variables, 'first_row_zero' and 'first_col_zero', to keep track of whether the first row and the first column should be zeroed.
2. Iterate through the matrix starting from the second row and the second column.
3. If a cell in the matrix is zero, set the corresponding cell in the first row and the first column to zero to mark that the row or column should be zeroed.
4. Iterate through the matrix again and set the cells to zero based on the information in the first row and the first column.
5. If 'first_row_zero' is true, zero out the entire first row.
6. If 'first_col_zero' is true, zero out the entire first column.
7. Return the modified matrix.

Time Complexity:
O(m * n), where 'm' is the number of rows and 'n' is the number of columns in the matrix. We visit each cell in the matrix twice.

Space Complexity:
O(1), as we use the first row and the first column of the matrix to store information and do not use any additional data structures.
*/

impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let mut first_row_zero = false;
        let mut first_col_zero = false;
        let m = matrix.len();
        let n = matrix[0].len();

        // Check if the first row should be zeroed.
        for i in 0..m {
            if matrix[i][0] == 0 {
                first_col_zero = true;
                break;
            }
        }

        // Check if the first column should be zeroed.
        for j in 0..n {
            if matrix[0][j] == 0 {
                first_row_zero = true;
                break;
            }
        }

        // Mark rows and columns to be zeroed using the first row and first column.
        for i in 1..m {
            for j in 1..n {
                if matrix[i][j] == 0 {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Zero out rows based on the information in the first column.
        for i in 1..m {
            if matrix[i][0] == 0 {
                for j in 1..n {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero out columns based on the information in the first row.
        for j in 1..n {
            if matrix[0][j] == 0 {
                for i in 1..m {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero out the first row if necessary.
        if first_row_zero {
            for j in 0..n {
                matrix[0][j] = 0;
            }
        }

        // Zero out the first column if necessary.
        if first_col_zero {
            for i in 0..m {
                matrix[i][0] = 0;
            }
        }
    }
}

/*
// Using HashSet

use std::collections::HashSet;

impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let (rows, cols) = (matrix.len(), matrix[0].len());
        let mut rows_with_zero = HashSet::new();
        let mut cols_with_zero = HashSet::new();

        // Find rows and columns with zeros
        for (r, row) in matrix.iter().enumerate() {
            for (c, &val) in row.iter().enumerate() {
                if val == 0 {
                    rows_with_zero.insert(r);
                    cols_with_zero.insert(c);
                }
            }
        }

        // Set rows with zeros to all zeros
        for &r in &rows_with_zero {
            matrix[r].iter_mut().map(|val| *val = 0).count();
        }

        // Set columns with zeros to all zeros
        for &c in &cols_with_zero {
            for row in matrix.iter_mut() {
                row[c] = 0;
            }
        }
    }
}
*/
