/*
Problem: LeetCode 74 - Search a 2D Matrix

Key Idea:
The given matrix is sorted both row-wise and column-wise. We can treat this matrix as a 1D sorted array and use binary search to efficiently find the target element.

Approach:
1. Initialize two pointers, `start` and `end`, representing the leftmost and rightmost indices of the 1D array.
2. While `start <= end`, perform binary search:
   a. Calculate the middle index as `mid = start + (end - start) / 2`.
   b. Convert `mid` into a 2D index as `(row, col)` where `row = mid / n` and `col = mid % n` (assuming the matrix has 'n' columns).
   c. If `matrix[row][col]` is equal to the target, return `true`.
   d. If `matrix[row][col]` is less than the target, update `start` to `mid + 1`.
   e. If `matrix[row][col]` is greater than the target, update `end` to `mid - 1`.
3. If the target is not found after the binary search, return `false`.

Time Complexity:
The time complexity of binary search is O(log(N*M)), where N is the number of rows, and M is the number of columns in the matrix.

Space Complexity:
The space complexity is O(1) as we are using a constant amount of extra space.
*/

impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let rows = matrix.len() as i32;
        let cols = matrix[0].len() as i32;

        let mut start = 0;
        let mut end = rows * cols - 1;

        while start <= end {
            let mid = start + (end - start) / 2;
            let mid_value = matrix[(mid / cols) as usize][(mid % cols) as usize];

            if mid_value == target {
                return true;
            } else if mid_value < target {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        false
    }
}
