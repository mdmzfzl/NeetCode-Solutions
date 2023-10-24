/*
Problem: LeetCode 778 - Swim in Rising Water

Description:
On an N x N grid, each cell is either empty (0) or blocked (1).
A move consists of walking from one empty cell to another empty cell adjacent to it
in one of the 4 cardinal directions (up, down, left, right).
Time starts at 0, and each time you visit an empty cell, you walk to an adjacent empty
cell and increase time by 1.
The grid is said to be unreachable if we cannot walk from the top-left corner of the grid
(0, 0) to the bottom-right corner of the grid (N-1, N-1) without walking through any
blocked cells.
Return the minimum time required to reach the bottom-right corner of the grid, or -1 if
the grid is unreachable.

Intuition:
This problem can be solved using a binary search approach. We can search for the minimum
time required to reach the bottom-right corner, and then verify if it is possible to
reach the destination using that time.

Approach:
1. Implement a Depth-First Search (DFS) function that explores the grid to check if it is
   possible to reach the destination within a given time t. The DFS function takes the
   current position (x, y), the time t, the grid, and a visited set to track visited cells.
2. In the DFS function, check if the current position is out of bounds or blocked, and
   return false if so.
3. Check if the current position is the destination (bottom-right corner) and return true
   if so.
4. Mark the current position as visited and recursively call the DFS function for all
   adjacent empty cells (up, down, left, right) with time t as the parameter.
5. If any of the recursive calls return true, it means we can reach the destination within
   time t, so return true.
6. If none of the recursive calls return true, return false, indicating that it is not
   possible to reach the destination within time t.
7. Now, use a binary search to find the minimum time required to reach the destination.
   The search range is from 0 to the maximum height in the grid.
8. While the low is less than or equal to the high, calculate the mid as (low + high) / 2
   and call the DFS function with time mid to check if it is possible to reach the
   destination within mid time.
9. If the DFS function returns true, it means it is possible to reach the destination
   within mid time, so set high to mid - 1 to search for smaller time.
10. Otherwise, set low to mid + 1 to search for larger time.
11. After the binary search, return low as the minimum time required to reach the
    destination if reachable, or -1 if unreachable.

Time Complexity:
The time complexity of the binary search is O(log N * N), where N is the side length of
the grid. The DFS function visits all empty cells in the grid, so the overall time
complexity is O(N^2).

Space Complexity:
The space complexity is O(N^2) due to the visited set used in the DFS function.
*/

class Solution {
  public:
    bool dfs(int x, int y, int t, vector<vector<int>> &grid) {
        int n = grid.size();

        // Check if current position is out of bounds or blocked
        if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] > t) {
            return false;
        }

        // Check if current position is destination
        if (x == n - 1 && y == n - 1) {
            return true;
        }

        int prev = grid[x][y];
        grid[x][y] = -1; // Mark the cell as visited
        // Recursively call DFS for all adjacent empty cells
        bool canReach = dfs(x + 1, y, t, grid) ||
                        dfs(x - 1, y, t, grid) ||
                        dfs(x, y + 1, t, grid) ||
                        dfs(x, y - 1, t, grid);
        grid[x][y] = prev; // Reset the cell to its original value
        return canReach;
    }

    int swimInWater(vector<vector<int>> &grid) {
        int n = grid.size();
        int low = 0, high = n * n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if it is possible to reach destination within time mid
            if (dfs(0, 0, mid, grid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};

/*
// Beats 100% Runtime

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = max(grid[0][0], grid[n - 1][n - 1]); // Smallest possible value to start the binary search.
        int right = n * n - 1; // Largest possible value to end the binary search.

        while (left <= right) {
            int mid = (left + right) / 2;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            if (dfs(grid, visited, 0, 0, mid)) {
                // If it's possible to reach the destination with the threshold "mid",
                // try to find a better (smaller) threshold in the left half of the binary search space.
                right = mid - 1;
            } else {
                // If it's not possible to reach the destination with the threshold "mid",
                // increase the threshold by searching in the right half of the binary search space.
                left = mid + 1;
            }
        }
        // At the end of the binary search, "right" will be the smallest threshold that
        // makes it possible to reach the destination (0-indexed), so return "right + 1".
        return right + 1;
    }

private:
    const vector<int> DIR{0, 1, 0, -1, 0};

    // Depth-First Search function to check if it's possible to reach the destination (bottom-right cell)
    // from the current cell (i, j) with a maximum threshold of k.
    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int k) {
        int n = grid.size();
        if (i == n - 1 && j == n - 1) {
            // We reached the destination, return true.
            return true;
        }
        if (visited[i][j]) {
            // We already visited this cell, return false.
            return false;
        }
        visited[i][j] = true;

        // Explore all possible directions from the current cell.
        for (int l = 0; l < DIR.size() - 1; ++l) {
            int x = i + DIR[l];
            int y = j + DIR[l + 1];
            if (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y] && grid[x][y] <= k) {
                if (dfs(grid, visited, x, y, k)) {
                    return true;
                }
            }
        }
        return false;
    }
};
*/