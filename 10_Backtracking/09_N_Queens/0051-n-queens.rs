/*
Problem: LeetCode 51 - N-Queens

Key Idea:
The N-Queens problem is a classic backtracking problem. The key idea is to place queens on a chessboard of size N×N in such a way that no two queens threaten each other.

Approach:
1. Create a helper function, `backtrack`, which uses backtracking to find all valid solutions.
2. Initialize an empty board of size N×N represented as a 2D vector of characters. Initially, all cells are filled with '.' to represent empty cells.
3. In the `backtrack` function:
   a. Start by placing queens row by row.
   b. For each row, try placing a queen in each column and check if it's a valid placement (no other queens threaten it).
   c. If a valid placement is found, mark that cell as 'Q', and recursively move on to the next row.
   d. After placing queens and recursively checking all rows, if we reach the N-th row, it means we have found a valid solution. Add this solution to the result.
   e. Regardless of whether a solution is found or not, backtrack by marking the current cell as '.' again and exploring other possibilities.
4. Initialize an empty result vector to store all valid solutions.
5. Start the backtracking process from the first row.
6. Return the result vector containing all valid solutions.
7. Convert the result into the required format where each solution is represented as a vector of strings (each string representing a row of the chessboard).

Time Complexity:
The time complexity is O(N!), where N is the size of the chessboard. This is because there are N possibilities for the queen placement in the first row, (N-1) possibilities for the second row, (N-2) for the third, and so on. In the worst case, we explore all possible permutations.

Space Complexity:
The space complexity is O(N^2) for the chessboard.
*/

impl Solution {
    pub fn solve_n_queens(n: i32) -> Vec<Vec<String>> {
        let mut board: Vec<Vec<char>> = vec![vec!['.'; n as usize]; n as usize];
        let mut result: Vec<Vec<String>> = Vec::new();

        Self::backtrack(n, 0, &mut board, &mut result);

        result
    }

    fn backtrack(n: i32, row: i32, board: &mut Vec<Vec<char>>, result: &mut Vec<Vec<String>>) {
        if row == n {
            // We've successfully placed queens in all rows, so add this solution.
            let solution: Vec<String> = board.iter().map(|row| row.iter().collect()).collect();
            result.push(solution);
            return;
        }

        for col in 0..n {
            if Self::is_safe(row as usize, col as usize, n as usize, board) {
                // Place the queen in the current cell.
                board[row as usize][col as usize] = 'Q';
                // Recursively try to place queens in the next row.
                Self::backtrack(n, row + 1, board, result);
                // Backtrack by removing the queen.
                board[row as usize][col as usize] = '.';
            }
        }
    }

    fn is_safe(row: usize, col: usize, n: usize, board: &Vec<Vec<char>>) -> bool {
        // Check the column above this row.
        for i in 0..row {
            if board[i][col] == 'Q' {
                return false;
            }
        }

        // Check the upper-left diagonal.
        let mut i = row as i32 - 1;
        let mut j = col as i32 - 1;
        while i >= 0 && j >= 0 {
            if board[i as usize][j as usize] == 'Q' {
                return false;
            }
            i -= 1;
            j -= 1;
        }

        // Check the upper-right diagonal.
        let mut i = row as i32 - 1;
        let mut j = col as i32 + 1;
        while i >= 0 && j < n as i32 {
            if board[i as usize][j as usize] == 'Q' {
                return false;
            }
            i -= 1;
            j += 1;
        }

        true
    }
}

/*
// Bitmask solution

impl Solution {
    pub fn solve_n_queens(n: i32) -> Vec<Vec<String>> {
        let mut result = Vec::new();
        let mut path = Vec::new();
        let n = n as usize;
        let bitmask = (1 << n) - 1;
        let mut diagonal_135 = 0;
        let mut diagonal_45 = 0;
        let mut col_mask = 0;

        fn dfs(
            n: usize,
            bitmask: i32,
            diagonal_135: i32,
            diagonal_45: i32,
            col_mask: i32,
            result: &mut Vec<Vec<String>>,
            path: &mut Vec<usize>,
        ) {
            if bitmask == col_mask {
                result.push(decode(&path, n));
                return;
            }

            let available = bitmask & (!(diagonal_135 | diagonal_45 | col_mask));

            for i in 0..n {
                let bit_info = 1 << i;
                if available & bit_info == 0 {
                    continue;
                }
                path.push(i);
                dfs(
                    n,
                    bitmask,
                    (diagonal_135 | bit_info) >> 1,
                    (diagonal_45 | bit_info) << 1,
                    col_mask | bit_info,
                    result,
                    path,
                );
                path.pop();
            }
        }

        fn decode(path: &[usize], n: usize) -> Vec<String> {
            path.iter()
                .enumerate()
                .fold(vec![vec!['.'; n]; n], |mut acc, (i, &j)| {
                    acc[i][j] = 'Q';
                    acc
                })
                .into_iter()
                .map(|x| x.into_iter().collect())
                .collect()
        }

        dfs(n, bitmask, diagonal_135, diagonal_45, col_mask, &mut result, &mut path);
        result
    }
}
*/
