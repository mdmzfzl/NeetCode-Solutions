/*
Problem: LeetCode 695 - Max Area of Island

Description:
Given a grid of 0's and 1's, find the maximum area of an island in the grid.
An island is a group of connected 1's (horizontally or vertically). You may assume all four edges of the grid are all surrounded by water.

Intuition:
To find the maximum area of an island, we can use a depth-first search (DFS) approach. The idea is to traverse the grid and whenever we encounter a land (1), we explore its neighboring cells and count the number of connected lands.

Approach:
1. Initialize a variable `maxArea` to store the maximum area of an island.
2. Iterate through each cell in the grid:
   - If the current cell is a land (1), call the `dfs` function to explore its neighboring cells and update the maximum area.
3. Define a helper function `dfs`:
   - Check if the current cell is out of bounds or is not a land (1). If so, return 0.
   - Mark the current cell as visited by changing its value to 0.
   - Recursively call `dfs` for the neighboring cells (up, down, left, right) and sum the results.
4. Return the maximum area stored in `maxArea`.

Time Complexity:
The time complexity is O(m * n), where m is the number of rows and n is the number of columns in the grid. We visit each cell once.

Space Complexity:
The space complexity is O(m * n), where m is the number of rows and n is the number of columns in the grid. This is the space used for the recursion stack during the DFS traversal.
*/

class Solution {
  public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        if (grid.empty()) {
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }

        return maxArea;
    }

  private:
    int dfs(vector<vector<int>> &grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0) {
            return 0;
        }

        grid[row][col] = 0;  // Mark the current cell as visited
        int area = 1;  // Count the current cell as part of the island
        // Recursively explore the neighboring cells (up, down, left, right)
        area += dfs(grid, row - 1, col);  // Up
        area += dfs(grid, row + 1, col);  // Down
        area += dfs(grid, row, col - 1);  // Left
        area += dfs(grid, row, col + 1);  // Right
        return area;
    }
};