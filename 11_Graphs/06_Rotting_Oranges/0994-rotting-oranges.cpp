/*
Problem: LeetCode 994 - Rotting Oranges

Description:
You are given an m x n grid where each cell can have one of three values:
- 0 representing an empty cell.
- 1 representing a fresh orange.
- 2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Intuition:
To find the minimum number of minutes needed to rot all the oranges, we can use a breadth-first search (BFS) approach. We start with the initial rotten oranges and spread the rot to their adjacent fresh oranges. We continue this process in rounds until no more fresh oranges can be infected. The number of rounds needed corresponds to the minimum minutes required.

Approach:
1. Initialize a queue to store the coordinates of the rotten oranges.
2. Initialize variables to keep track of the number of fresh oranges and the number of minutes passed.
3. Iterate through the grid to find the initial rotten oranges and count the number of fresh oranges.
   - Enqueue the coordinates of the rotten oranges into the queue.
4. Perform a BFS traversal:
   - For each round, process all the rotten oranges in the queue.
   - For each rotten orange, check its adjacent cells (up, down, left, right):
     - If an adjacent cell is a fresh orange, mark it as rotten, decrease the count of fresh oranges, and enqueue its coordinates.
   - Increment the number of minutes.
5. After the BFS traversal, check if there are any remaining fresh oranges. If so, return -1.
6. Return the number of minutes minus one since the last round is not counted as a minute needed to rot the oranges.

Time Complexity:
The time complexity is O(m * n), where m is the number of rows and n is the number of columns in the grid. In the worst case, we may need to visit all the cells.

Space Complexity:
The space complexity is O(m * n), where m is the number of rows and n is the number of columns in the grid. This is the space used for the queue to store the coordinates of the rotten oranges.
*/

class Solution {
  public:
    int orangesRotting(vector<vector<int>> &grid) {
        if (grid.empty()) {
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();
        int freshOranges = 0;
        int minutes = 0;
        queue<pair<int, int>> rottenOranges;  // Queue to store the coordinates of the rotten oranges

        // Find the initial rotten oranges and count the number of fresh oranges
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    rottenOranges.push({i, j});
                } else if (grid[i][j] == 1) {
                    ++freshOranges;
                }
            }
        }

        // Perform a BFS traversal
        while (!rottenOranges.empty() && freshOranges > 0) {
            int size = rottenOranges.size();

            for (int i = 0; i < size; ++i) {
                int row = rottenOranges.front().first;
                int col = rottenOranges.front().second;
                rottenOranges.pop();
                // Check adjacent cells (up, down, left, right)
                vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

                for (const auto &dir : directions) {
                    int newRow = row + dir.first;
                    int newCol = col + dir.second;

                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1) {
                        // Mark the adjacent fresh orange as rotten
                        grid[newRow][newCol] = 2;
                        rottenOranges.push({newRow, newCol});
                        --freshOranges;
                    }
                }
            }

            if (!rottenOranges.empty()) {
                ++minutes;  // Increment the number of minutes
            }
        }

        if (freshOranges > 0) {
            return -1;  // There are remaining fresh oranges
        }

        return minutes;
    }
};