/*
Problem: LeetCode 36 - Valid Sudoku

Key Idea:
The key idea is to check whether the rules of a Sudoku are satisfied: no repeated digits in each row, each column, and each of the 9 sub-boxes.

Approach:
1. Create three arrays, `row_sets`, `col_sets`, and `box_sets`, of size 9x9 to store sets of digits encountered in each row, column, and sub-box.
2. Iterate through the Sudoku board:
   - For each cell `(i, j)` with digit `num`:
     - Check if `num` is already in `row_sets[i]`, `col_sets[j]`, or `box_sets[box_index]`. If yes, return `false`.
     - Otherwise, add `num` to `row_sets[i]`, `col_sets[j]`, and `box_sets[box_index]`.
3. If the iteration completes without any violations, return `true`.

Time Complexity:
O(1), as we iterate through the Sudoku board with a constant size of 9x9 cells.

Space Complexity:
O(1), as the sizes of `row_sets`, `col_sets`, and `box_sets` are all fixed and independent of the input size.
*/

impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut row_sets = vec![vec![false; 9]; 9];
        let mut col_sets = vec![vec![false; 9]; 9];
        let mut box_sets = vec![vec![false; 9]; 9];

        for i in 0..9 {
            for j in 0..9 {
                if board[i][j] != '.' {
                    let num = (board[i][j] as u8 - b'1') as usize;
                    let box_index = (i / 3) * 3 + j / 3;

                    if row_sets[i][num] || col_sets[j][num] || box_sets[box_index][num] {
                        return false;
                    }

                    row_sets[i][num] = true;
                    col_sets[j][num] = true;
                    box_sets[box_index][num] = true;
                }
            }
        }

        true
    }
}
