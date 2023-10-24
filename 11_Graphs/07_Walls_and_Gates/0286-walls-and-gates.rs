/*
Problem: LeetCode 286 - Walls and Gates

Key Idea:
The key idea is to perform a breadth-first search (BFS) from each gate to find the distance from that gate to each empty room (represented by INF). We start BFS from all gates simultaneously to propagate distances efficiently.

Approach:
1. Create a queue and enqueue all gate positions, initializing their distance as 0.
2. Perform BFS:
   - Dequeue a position from the queue.
   - Explore its neighbors (up, down, left, right).
   - If a neighbor is an empty room (INF), update its distance and enqueue it.
   - Repeat until the queue is empty.
3. After BFS from all gates, the grid contains the shortest distance from each gate to each empty room.
4. Return the updated grid.

Time Complexity:
O(m * n), where `m` is the number of rows and `n` is the number of columns in the grid. In the worst case, we might visit all cells once.

Space Complexity:
O(m * n) for the queue and other variables.
*/

impl Solution {
    pub fn walls_and_gates(rooms: &mut Vec<Vec<i32>>) {
        let rows = rooms.len();
        if rows == 0 {
            return;
        }
        let cols = rooms[0].len();

        let directions = [(0, 1), (0, -1), (1, 0), (-1, 0)];
        let mut queue = std::collections::VecDeque::new();

        // Enqueue all gate positions
        for i in 0..rows {
            for j in 0..cols {
                if rooms[i][j] == 0 {
                    queue.push_back((i, j, 0));
                }
            }
        }

        while !queue.is_empty() {
            if let Some((x, y, distance)) = queue.pop_front() {
                for (dx, dy) in directions.iter() {
                    let new_x = (x as i32 + dx) as usize;
                    let new_y = (y as i32 + dy) as usize;

                    if new_x < rows && new_y < cols && rooms[new_x][new_y] == std::i32::MAX {
                        rooms[new_x][new_y] = distance + 1;
                        queue.push_back((new_x, new_y, distance + 1));
                    }
                }
            }
        }
    }
}
