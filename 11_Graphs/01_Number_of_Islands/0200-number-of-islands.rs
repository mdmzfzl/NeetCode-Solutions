/*
Problem: LeetCode 200 - Number of Islands

Key Idea:
The key idea is to use Depth-First Search (DFS) to count the number of connected islands in a grid.

Approach:
1. We can approach this problem by iterating through the grid and using DFS to explore each island.
2. Initialize a variable `count` to keep track of the number of islands.
3. Iterate through each cell in the grid:
   - If the cell is '1' (land), increment `count` and start a DFS from that cell to mark all connected land cells as visited.
     - During DFS, mark visited cells as '0' to avoid counting them again.
4. Continue this process for all cells in the grid.
5. Return the `count` as the result.

Time Complexity:
O(m * n), where `m` is the number of rows and `n` is the number of columns in the grid. We visit each cell once.

Space Complexity:
O(m * n), as in the worst case, the entire grid can be composed of '1's and require a DFS stack.
*/

impl Solution {
    pub fn num_islands(grid: Vec<Vec<char>>) -> i32 {
        if grid.is_empty() || grid[0].is_empty() {
            return 0;
        }

        let mut grid = grid; // Make grid mutable

        let rows = grid.len();
        let cols = grid[0].len();
        let mut count = 0;

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] == '1' {
                    count += 1;
                    Solution::dfs(&mut grid, i, j);
                }
            }
        }

        count
    }

    fn dfs(grid: &mut Vec<Vec<char>>, i: usize, j: usize) {
        let rows = grid.len();
        let cols = grid[0].len();

        if i >= rows || j >= cols || grid[i][j] == '0' {
            return;
        }

        grid[i][j] = '0'; // Mark as visited

        // Explore neighbors in all four directions
        let directions = [(0, 1), (0, -1), (1, 0), (-1, 0)];
        for (dx, dy) in directions.iter() {
            let x = (i as isize + dx) as usize;
            let y = (j as isize + dy) as usize;
            if x < rows && y < cols && grid[x][y] == '1' {
                Solution::dfs(grid, x, y);
            }
        }
    }
}
