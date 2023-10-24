/*
Problem: LeetCode 417 - Pacific Atlantic Water Flow

Key Idea:
The key idea is to perform depth-first search (DFS) from the ocean boundaries (Pacific and Atlantic) to identify cells that can flow water to both oceans. We'll use two boolean grids to mark cells reachable by each ocean, and the intersection of these grids will give us the answer.

Approach:
1. Create two boolean grids, one for the Pacific Ocean and one for the Atlantic Ocean, both initialized to false.
2. Start DFS from the boundaries of the grid (ocean coasts) and mark cells as reachable for each ocean separately.
   - For the Pacific Ocean, start DFS from the top row and left column.
   - For the Atlantic Ocean, start DFS from the bottom row and right column.
3. After the DFS is complete for both oceans, iterate through all cells in the grid.
   - If a cell is marked as reachable by both oceans, it can flow water to both oceans. Add it to the result.
4. Return the result, which is a list of cells that can flow water to both oceans.

Time Complexity:
O(m * n), where `m` is the number of rows and `n` is the number of columns in the grid. We visit each cell once.

Space Complexity:
O(m * n) for the two boolean grids, as we need to mark each cell in the grid.
*/

impl Solution {
    pub fn pacific_atlantic(matrix: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let rows = matrix.len();
        if rows == 0 {
            return Vec::new();
        }
        let cols = matrix[0].len();

        let mut pacific_reachable = vec![vec![false; cols]; rows];
        let mut atlantic_reachable = vec![vec![false; cols]; rows];

        for i in 0..rows {
            Solution::dfs(&matrix, &mut pacific_reachable, i, 0, i, 0);
            Solution::dfs(&matrix, &mut atlantic_reachable, i, cols - 1, i, cols - 1);
        }

        for j in 0..cols {
            Solution::dfs(&matrix, &mut pacific_reachable, 0, j, 0, j);
            Solution::dfs(&matrix, &mut atlantic_reachable, rows - 1, j, rows - 1, j);
        }

        let mut result = Vec::new();
        for i in 0..rows {
            for j in 0..cols {
                if pacific_reachable[i][j] && atlantic_reachable[i][j] {
                    result.push(vec![i as i32, j as i32]);
                }
            }
        }

        result
    }

    fn dfs(
        matrix: &Vec<Vec<i32>>,
        reachable: &mut Vec<Vec<bool>>,
        i: usize,
        j: usize,
        prev_i: usize,
        prev_j: usize,
    ) {
        let rows = matrix.len();
        let cols = matrix[0].len();

        if i < 0
            || i >= rows
            || j < 0
            || j >= cols
            || reachable[i][j]
            || matrix[i][j] < matrix[prev_i][prev_j]
        {
            return;
        }

        reachable[i][j] = true;

        let directions = [(0, 1), (0, -1), (1, 0), (-1, 0)];
        for (dx, dy) in directions.iter() {
            let x = (i as isize + dx) as usize;
            let y = (j as isize + dy) as usize;
            Solution::dfs(matrix, reachable, x, y, i, j);
        }
    }
}
