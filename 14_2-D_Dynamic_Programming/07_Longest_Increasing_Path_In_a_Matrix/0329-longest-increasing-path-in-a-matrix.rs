/*
Problem: LeetCode 329 - Longest Increasing Path in a Matrix

Key Idea:
The key idea is to use dynamic programming to find the length of the longest increasing path in a matrix.

Approach:
1. Initialize a 2D vector `dp` of the same size as the matrix, where `dp[i][j]` represents the length of the longest increasing path starting from cell `(i, j)`.
2. Initialize a variable `max_length` to store the maximum path length found so far, and set it to 0.
3. Iterate through each cell in the matrix:
   - For each cell `(i, j)`, recursively explore its neighboring cells (up, down, left, and right).
   - For each neighboring cell `(x, y)`, if `(x, y)` has a greater value than `(i, j)`, calculate `length` as `dp[x][y] + 1`.
   - Update `dp[i][j]` as the maximum `length` among all valid neighboring cells.
   - Update `max_length` with the maximum value of `dp[i][j]` and `max_length`.
4. After iterating through all cells, `max_length` will contain the length of the longest increasing path in the matrix.
5. Return `max_length` as the result.

Time Complexity:
O(m * n), where `m` is the number of rows and `n` is the number of columns in the matrix. We visit each cell once in the matrix.

Space Complexity:
O(m * n), as we use a 2D vector of the same size as the matrix to store the dynamic programming values.
*/

impl Solution {
    pub fn longest_increasing_path(matrix: Vec<Vec<i32>>) -> i32 {
        if matrix.is_empty() || matrix[0].is_empty() {
            return 0;
        }

        let m = matrix.len();
        let n = matrix[0].len();
        let mut dp = vec![vec![0; n]; m];
        let mut max_length = 0;

        fn dfs(
            matrix: &Vec<Vec<i32>>,
            dp: &mut Vec<Vec<i32>>,
            m: usize,
            n: usize,
            i: usize,
            j: usize,
        ) -> i32 {
            if dp[i][j] != 0 {
                return dp[i][j];
            }

            let directions = [(0, 1), (0, -1), (1, 0), (-1, 0)];
            let mut max_len = 1;

            for &(dx, dy) in directions.iter() {
                let x = i as i32 + dx;
                let y = j as i32 + dy;

                if x >= 0
                    && x < m as i32
                    && y >= 0
                    && y < n as i32
                    && matrix[x as usize][y as usize] > matrix[i][j]
                {
                    max_len = max_len.max(1 + dfs(matrix, dp, m, n, x as usize, y as usize));
                }
            }

            dp[i][j] = max_len;
            max_len
        }

        for i in 0..m {
            for j in 0..n {
                max_length = max_length.max(dfs(&matrix, &mut dp, m, n, i, j));
            }
        }

        max_length
    }
}
