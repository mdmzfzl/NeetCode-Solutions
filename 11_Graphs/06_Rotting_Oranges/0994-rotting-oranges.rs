/*
Problem: LeetCode 994 - Rotting Oranges

Key Idea:
The key idea is to perform a breadth-first search (BFS) traversal of the grid, where the initial rotten oranges are treated as the starting points. We keep track of the time taken for each orange to rot and find the maximum time.

Approach:
1. Initialize a queue for BFS and a variable `time` to 0.
2. Iterate through the grid and enqueue the positions of initially rotten oranges (with value 2) into the queue. Also, count the number of fresh oranges.
3. While the queue is not empty:
   - For each level of BFS (representing a minute), process all oranges in the queue at that level:
     - Dequeue an orange and mark its neighbors as rotten if they are fresh.
     - Decrement the count of fresh oranges.
     - Increment the `time` for the current level.
   - After processing a level, increment `time` to indicate a minute has passed.
4. If there are no fresh oranges remaining, return `time`. Otherwise, return -1 to indicate that some oranges cannot rot.

Time Complexity:
O(m * n), where `m` is the number of rows and `n` is the number of columns in the grid. In the worst case, we may visit all cells once.

Space Complexity:
O(m * n) for the queue and the grid.
*/

use std::collections::VecDeque;

impl Solution {
    pub fn oranges_rotting(mut grid: Vec<Vec<i32>>) -> i32 {
        let rows = grid.len();
        if rows == 0 {
            return 0;
        }
        let cols = grid[0].len();

        let mut queue = VecDeque::new();
        let mut fresh_count = 0;

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] == 2 {
                    queue.push_back((i, j, 0)); // (row, col, time)
                } else if grid[i][j] == 1 {
                    fresh_count += 1;
                }
            }
        }

        let directions = [(0, 1), (0, -1), (1, 0), (-1, 0)];
        let mut time = 0;

        while !queue.is_empty() {
            let (x, y, t) = queue.pop_front().unwrap();

            for (dx, dy) in directions.iter() {
                let new_x = x as isize + dx;
                let new_y = y as isize + dy;

                if new_x >= 0 && new_x < rows as isize && new_y >= 0 && new_y < cols as isize {
                    let new_x = new_x as usize;
                    let new_y = new_y as usize;

                    if grid[new_x][new_y] == 1 {
                        grid[new_x][new_y] = 2;
                        fresh_count -= 1;
                        queue.push_back((new_x, new_y, t + 1));
                    }
                }
            }

            if fresh_count == 0 {
                time = t; // All oranges have rotted
            }
        }

        if fresh_count == 0 {
            time
        } else {
            -1 // Some oranges cannot rot
        }
    }
}
