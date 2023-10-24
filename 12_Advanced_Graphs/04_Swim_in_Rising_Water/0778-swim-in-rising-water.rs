/*
Problem: LeetCode 778 - Swim in Rising Water

Key Idea:
The key idea is to perform a binary search on the time it takes to reach a point (i, j) in the grid from the starting point (0, 0). Then, we can use depth-first search (DFS) to check if it's possible to reach the destination point (n-1, n-1) within that time limit.

Approach:
1. Initialize the lower bound as the minimum value in the grid and the upper bound as the maximum value in the grid.
2. Perform a binary search on the time, searching for the minimum time required to reach the destination point (n-1, n-1) from the starting point (0, 0).
3. In each binary search iteration:
   - Calculate the mid-time (current guess) as the average of the lower and upper bounds.
   - Create a visited array of size n x n to keep track of visited cells.
   - Start DFS from the starting point (0, 0) and explore cells while considering two conditions:
     - The cell is within bounds (0 <= i < n and 0 <= j < n).
     - The cell value is less than or equal to the current mid-time.
   - If DFS reaches the destination point (n-1, n-1), update the upper bound with the mid-time.
   - Otherwise, update the lower bound.
4. Repeat the binary search until the lower bound is less than the upper bound.
5. Return the final lower bound as the minimum time required to reach the destination.

Time Complexity:
O(n^2 * log(maximum value in the grid)), where n is the size of the grid.

Space Complexity:
O(n^2) for the visited array.
*/

impl Solution {
    pub fn swim_in_water(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut low = grid[0][0];
        let mut high = (n * n) as i32 - 1;

        while low < high {
            let mid = low + (high - low) / 2;
            let mut visited = vec![vec![false; n]; n];

            if Self::dfs(&grid, &mut visited, 0, 0, mid) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        low
    }

    fn dfs(
        grid: &Vec<Vec<i32>>,
        visited: &mut Vec<Vec<bool>>,
        i: usize,
        j: usize,
        time: i32,
    ) -> bool {
        if i == grid.len() - 1 && j == grid[0].len() - 1 {
            return true;
        }

        visited[i][j] = true;
        let directions = [(0, 1), (0, -1), (1, 0), (-1, 0)];
        let n = grid.len();

        for (dx, dy) in &directions {
            let ni = i as i32 + dx;
            let nj = j as i32 + dy;

            if ni >= 0
                && ni < n as i32
                && nj >= 0
                && nj < n as i32
                && !visited[ni as usize][nj as usize]
                && grid[ni as usize][nj as usize] <= time
            {
                if Self::dfs(grid, visited, ni as usize, nj as usize, time) {
                    return true;
                }
            }
        }

        false
    }
}
