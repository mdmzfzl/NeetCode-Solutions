/*
Problem: LeetCode 200 - Number of Islands

Description:
Given an m x n grid containing '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Intuition:
To find the number of islands in the grid, we can use a depth-first search (DFS) or breadth-first search (BFS) approach. The idea is to traverse the grid and whenever we encounter a land ('1'), we explore its neighboring cells and mark them as visited to avoid counting them again.

Approach:
1. Iterate through each cell in the grid:
   - If the current cell is a land ('1'), increment the count of islands and call the `dfs` or `bfs` function to explore its neighboring cells.
2. Define a helper function `dfs` or `bfs`:
   - Check if the current cell is out of bounds or is not a land ('1'). If so, return.
   - Mark the current cell as visited by changing its value to '0'.
   - Recursively call `dfs` or `bfs` for the neighboring cells (up, down, left, right).
3. Return the count of islands.

Time Complexity:
The time complexity is O(m * n), where m is the number of rows and n is the number of columns in the grid. We visit each cell once.

Space Complexity:
The space complexity is O(min(m, n)), where m is the number of rows and n is the number of columns in the grid. This is the maximum depth of the recursion stack or the maximum number of cells in the queue during the BFS traversal.
*/

class Solution {
  public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty()) {
            return 0;
        }

        int m = grid.size();  // Number of rows in the grid
        int n = grid[0].size();  // Number of columns in the grid
        int count = 0;  // Counter for the number of islands

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {  // Found a new island
                    ++count;
                    dfs(grid, i, j);  // Explore the island using DFS
                    // bfs(grid, i, j);  // Alternatively, we can use BFS to explore the island
                }
            }
        }

        return count;
    }

  private:
    void dfs(vector<vector<char>> &grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != '1') {
            return;  // Out of bounds or already visited cell
        }

        grid[row][col] = '0';  // Mark the current cell as visited
        // Recursively call DFS for the neighboring cells (up, down, left, right)
        dfs(grid, row - 1, col);  // Up
        dfs(grid, row + 1, col);  // Down
        dfs(grid, row, col - 1);  // Left
        dfs(grid, row, col + 1);  // Right
    }

    void bfs(vector<vector<char>> &grid, int row, int col) {
        int m = grid.size();  // Number of rows in the grid
        int n = grid[0].size();  // Number of columns in the grid
        queue<pair<int, int>> q;  // Queue to store cell positions
        q.push({row, col});  // Start with the current cell
        grid[row][col] = '0';  // Mark the current cell as visited
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  // Possible directions (up, down, left, right)

        while (!q.empty()) {
            int r = q.front().first;  // Row of the current cell
            int c = q.front().second;  // Column of the current cell
            q.pop();

            // Explore the neighboring cells
            for (const auto &dir : directions) {
                int nr = r + dir.first;  // Row of the neighboring cell
                int nc = c + dir.second;  // Column of the neighboring cell

                // Check if the neighboring cell is within the grid and is unvisited
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1') {
                    q.push({nr, nc});  // Add the neighboring cell to the queue
                    grid[nr][nc] = '0';  // Mark the neighboring cell as visited
                }
            }
        }
    }
};