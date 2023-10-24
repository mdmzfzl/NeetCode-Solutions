/*
Problem: LeetCode 695 - Max Area of Island

Key Idea:
The key idea is to use depth-first search (DFS) to traverse the grid and identify connected islands. We maintain a count of the area of each island and keep track of the maximum area encountered.

Approach:
1. We can approach this problem using depth-first search (DFS).
2. Initialize a variable `max_area` to 0 to keep track of the maximum area of an island.
3. Iterate through the grid cells:
   - For each unvisited '1' cell, start a DFS to explore the island.
   - During DFS, mark visited cells as '0' to avoid counting them multiple times.
   - Increment the area count for the current island.
   - Update `max_area` with the maximum of the current area and the previous maximum.
4. Continue this process for all cells in the grid.
5. Return `max_area` as the result.

Time Complexity:
O(m * n), where `m` is the number of rows and `n` is the number of columns in the grid. We visit each cell once.

Space Complexity:
O(m * n) for the recursion stack, as in the worst case, we might have to explore all cells in the grid.
*/

impl Solution {
    pub fn max_area_of_island(grid: Vec<Vec<i32>>) -> i32 {
        let mut grid = grid; // Make grid mutable

        let rows = grid.len();
        let cols = grid[0].len();
        let mut max_area = 0;

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] == 1 {
                    let area = Solution::dfs(&mut grid, i, j);
                    max_area = max_area.max(area);
                }
            }
        }

        max_area
    }

    fn dfs(grid: &mut Vec<Vec<i32>>, i: usize, j: usize) -> i32 {
        let rows = grid.len();
        let cols = grid[0].len();

        if i >= rows || j >= cols || grid[i][j] == 0 {
            return 0;
        }

        grid[i][j] = 0; // Mark as visited

        // Explore neighbors in all four directions
        let directions = [(0, 1), (0, -1), (1, 0), (-1, 0)];
        let mut area = 1;

        for (dx, dy) in directions.iter() {
            let x = (i as isize + dx) as usize;
            let y = (j as isize + dy) as usize;
            area += Solution::dfs(grid, x, y);
        }

        area
    }
}
