/*
Problem: LeetCode 62 - Unique Paths

Key Idea:
The key idea is to use dynamic programming to find the total number of unique paths from the top-left corner to the bottom-right corner of a grid. The intuition is that at any given cell, the number of unique paths to reach it is the sum of the paths from the cell above and the cell to the left, as you can only move down or right in the grid. By applying this principle iteratively and filling a 2D array, you can efficiently compute the final count of unique paths.

Approach:
1. Initialize a 2D vector `dp` of size `m x n`, where `dp[i][j]` represents the number of unique paths to reach cell `(i, j)` from the top-left corner `(0, 0)`.
2. Initialize the first row and the first column of `dp` to 1 because there is only one way to reach any cell in the first row or the first column (by moving right or down).
3. Iterate through the grid from row 1 to `m-1` and column 1 to `n-1`.
4. For each cell `(i, j)`, update `dp[i][j]` as the sum of the number of unique paths from the cell above `(i-1, j)` and the cell to the left `(i, j-1)`.
5. After the iteration, `dp[m-1][n-1]` will contain the number of unique paths to reach the bottom-right corner.
6. Return `dp[m-1][n-1]` as the result.

Time Complexity:
O(m * n), where `m` is the number of rows and `n` is the number of columns in the grid. We fill in the `dp` table with a nested loop.

Space Complexity:
O(m * n), as we use a 2D vector of size `m x n` to store the dynamic programming values.
*/

impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        let m = m as usize;
        let n = n as usize;

        let mut dp = vec![vec![1; n]; m];

        for i in 1..m {
            for j in 1..n {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        dp[m - 1][n - 1]
    }
}
