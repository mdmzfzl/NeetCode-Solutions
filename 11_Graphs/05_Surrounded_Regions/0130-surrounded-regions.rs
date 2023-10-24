/*
Problem: LeetCode 130 - Surrounded Regions

Key Idea:
The key idea is to use a depth-first search (DFS) or breadth-first search (BFS) algorithm to mark and traverse the regions connected to the boundaries (ocean edges) of the board. Any 'O' that is not marked as part of these connected regions must be surrounded by 'X'.

Approach:
1. Iterate through the boundaries (ocean edges) of the board.
   - For each 'O' cell encountered, perform a DFS or BFS to mark all connected 'O' cells as 'B'.
2. After marking the connected regions to the boundaries, iterate through the entire board.
   - Replace 'O' cells with 'X' and 'B' cells with 'O'.
3. The board is now updated with 'X' for cells surrounded by 'X' and 'O' for cells connected to the boundaries.

Time Complexity:
O(m * n), where `m` is the number of rows and `n` is the number of columns in the board. We visit each cell once.

Space Complexity:
O(m * n) for the recursive stack (DFS) or queue (BFS) space.
*/

impl Solution {
    pub fn solve(board: &mut Vec<Vec<char>>) {
        let rows = board.len();
        if rows == 0 {
            return;
        }
        let cols = board[0].len();

        // Mark and traverse the connected regions to the top and bottom boundaries
        for i in 0..rows {
            Solution::dfs(board, i, 0);
            Solution::dfs(board, i, cols - 1);
        }

        // Mark and traverse the connected regions to the left and right boundaries
        for j in 0..cols {
            Solution::dfs(board, 0, j);
            Solution::dfs(board, rows - 1, j);
        }

        // Update the board based on the marked cells
        for i in 0..rows {
            for j in 0..cols {
                if board[i][j] == 'O' {
                    board[i][j] = 'X';
                } else if board[i][j] == 'B' {
                    board[i][j] = 'O';
                }
            }
        }
    }

    fn dfs(board: &mut Vec<Vec<char>>, i: usize, j: usize) {
        let rows = board.len();
        let cols = board[0].len();

        if i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != 'O' {
            return;
        }

        board[i][j] = 'B'; // Mark as part of connected region

        let directions = [(0, 1), (0, -1), (1, 0), (-1, 0)];
        for (dx, dy) in directions.iter() {
            let x = (i as isize + dx) as usize;
            let y = (j as isize + dy) as usize;
            Solution::dfs(board, x, y);
        }
    }
}
