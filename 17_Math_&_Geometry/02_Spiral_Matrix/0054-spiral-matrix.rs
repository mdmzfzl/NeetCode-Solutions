/*
Problem: LeetCode 54 - Spiral Matrix

Key Idea:
The key idea is to simulate the process of traversing the matrix in a spiral order by defining four boundaries: top, bottom, left, and right.

Approach:
1. Initialize variables 'top' to 0, 'bottom' to the last row index, 'left' to 0, and 'right' to the last column index.
2. Initialize an empty vector 'result' to store the spiral order elements.
3. Use a loop to continue until 'top' is less than or equal to 'bottom' and 'left' is less than or equal to 'right'.
4. Inside the loop, iterate from 'left' to 'right' and add the elements in the top row to 'result'.
5. Increment 'top' to exclude the top row from further consideration.
6. Iterate from 'top' to 'bottom' and add the elements in the rightmost column to 'result'.
7. Decrement 'right' to exclude the rightmost column from further consideration.
8. Check if 'top' is still less than or equal to 'bottom' to avoid duplicate traversal.
9. Iterate from 'right' to 'left' and add the elements in the bottom row to 'result'.
10. Decrement 'bottom' to exclude the bottom row from further consideration.
11. Check if 'left' is still less than or equal to 'right' to avoid duplicate traversal.
12. Iterate from 'bottom' to 'top' and add the elements in the leftmost column to 'result'.
13. Increment 'left' to exclude the leftmost column from further consideration.
14. Repeat the loop until 'top' is no longer less than or equal to 'bottom' or 'left' is no longer less than or equal to 'right'.
15. Return the 'result' vector containing the elements in spiral order.

Time Complexity:
O(m * n), where 'm' is the number of rows and 'n' is the number of columns in the matrix. We visit each element once.

Space Complexity:
O(1), as we do not use any additional data structures that scale with the size of the input.
*/

impl Solution {
    pub fn spiral_order(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        if matrix.is_empty() {
            return Vec::new();
        }

        let mut top = 0;
        let mut bottom = matrix.len() as i32 - 1;
        let mut left = 0;
        let mut right = matrix[0].len() as i32 - 1;
        let mut result = Vec::new();

        while top <= bottom && left <= right {
            for i in left..=right {
                result.push(matrix[top as usize][i as usize]);
            }
            top = top.checked_add(1).unwrap();

            for i in top..=bottom {
                result.push(matrix[i as usize][right as usize]);
            }
            right = right.checked_sub(1).unwrap();

            if top <= bottom {
                for i in (left..=right).rev() {
                    result.push(matrix[bottom as usize][i as usize]);
                }
                bottom = bottom.checked_sub(1).unwrap();
            }

            if left <= right {
                for i in (top..=bottom).rev() {
                    result.push(matrix[i as usize][left as usize]);
                }
                left = left.checked_add(1).unwrap();
            }
        }

        result
    }
}

/*
// Pattern Matching and Enums

enum Direction {
    Up,
    Down,
    Right,
    Left,
}

impl Solution {
    pub fn spiral_order(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let mut current_direction = Direction::Right;
        let mut current_round = 0;
        let mut current_row = 0;
        let mut current_col = 0;
        let m = matrix.len();
        let n = matrix[0].len();
        let mut result = vec![];

        for _ in 0..m * n {
            result.push(matrix[current_row][current_col]);

            match current_direction {
                Direction::Up => {
                    // Check if we've reached the upper limit
                    if current_row == current_round + 1 {
                        current_col += 1;
                        current_direction = Direction::Right;
                        current_round += 1;
                    } else {
                        current_row -= 1;
                    }
                }
                Direction::Down => {
                    // Check if we've reached the lower limit
                    if current_row + 1 == m - current_round {
                        current_col -= 1;
                        current_direction = Direction::Left;
                    } else {
                        current_row += 1;
                    }
                }
                Direction::Right => {
                    // Check if we've reached the right limit
                    if current_col + 1 == n - current_round {
                        current_row += 1;
                        current_direction = Direction::Down;
                    } else {
                        current_col += 1;
                    }
                }
                Direction::Left => {
                    // Check if we've reached the left limit
                    if current_col == current_round {
                        current_row -= 1;
                        current_direction = Direction::Up;
                    } else {
                        current_col -= 1;
                    }
                }
            }
        }

        result
    }
}
*/
