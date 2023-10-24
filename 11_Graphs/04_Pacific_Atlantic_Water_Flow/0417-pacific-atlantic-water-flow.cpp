/*
Problem: LeetCode 417 - Pacific Atlantic Water Flow

Description:
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix, and the "Atlantic ocean" touches the right and bottom edges.
Water can only flow in four directions (up, down, left, or right) from a cell to its neighboring cells with equal or lower height.
Find the list of grid coordinates where water can flow to both the Pacific and Atlantic oceans.

Intuition:
To find the cells where water can flow to both the Pacific and Atlantic oceans, we can use a depth-first search (DFS) or breadth-first search (BFS) approach. The idea is to start the traversal from the ocean borders (Pacific and Atlantic) and mark the cells that can be reached by water. Finally, we find the cells that are marked by both traversals.

Approach:
1. Create two boolean matrices `canReachPacific` and `canReachAtlantic`, initialized with false, to track the cells that can be reached by water from the respective oceans.
2. Perform a DFS or BFS traversal from the ocean borders to mark the cells that can be reached by water:
   - For the Pacific ocean:
     - Start from the leftmost column and the topmost row. Traverse all neighboring cells with equal or lower heights and mark them as reachable by water from the Pacific ocean.
   - For the Atlantic ocean:
     - Start from the rightmost column and the bottommost row. Traverse all neighboring cells with equal or lower heights and mark them as reachable by water from the Atlantic ocean.
3. Iterate through all the cells and find the cells that are marked as reachable by both oceans.
4. Return the list of grid coordinates representing the cells that can flow to both oceans.

Time Complexity:
The time complexity is O(m * n), where m is the number of rows and n is the number of columns in the matrix. We perform a DFS or BFS traversal on each cell once.

Space Complexity:
The space complexity is O(m * n), where m is the number of rows and n is the number of columns in the matrix. This is the space used to store the boolean matrices and the recursion stack or the queue during the DFS or BFS traversal.
*/

class Solution {
  public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix) {
        vector<vector<int>> result;

        if (matrix.empty()) {
            return result;
        }

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> canReachPacific(m, vector<bool>(n, false));  // Matrix to track cells reachable from the Pacific ocean
        vector<vector<bool>> canReachAtlantic(m, vector<bool>(n, false));  // Matrix to track cells reachable from the Atlantic ocean

        // Traverse the top and bottom borders to mark cells reachable from the Pacific and Atlantic oceans
        for (int col = 0; col < n; ++col) {
            dfs(matrix, 0, col, INT_MIN, canReachPacific);
            dfs(matrix, m - 1, col, INT_MIN, canReachAtlantic);
        }

        // Traverse the left and right borders to mark cells reachable from the Pacific and Atlantic oceans
        for (int row = 0; row < m; ++row) {
            dfs(matrix, row, 0, INT_MIN, canReachPacific);
            dfs(matrix, row, n - 1, INT_MIN, canReachAtlantic);
        }

        // Find the cells that are reachable from both the Pacific and Atlantic oceans
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (canReachPacific[i][j] && canReachAtlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

  private:
    void dfs(const vector<vector<int>> &matrix, int row, int col, int prevHeight, vector<vector<bool>> &canReachOcean) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Check if the current cell is out of bounds or has been visited already
        if (row < 0 || row >= m || col < 0 || col >= n || matrix[row][col] < prevHeight || canReachOcean[row][col]) {
            return;
        }

        canReachOcean[row][col] = true;  // Mark the current cell as reachable
        // Recursively traverse the neighboring cells
        dfs(matrix, row - 1, col, matrix[row][col], canReachOcean);  // Up
        dfs(matrix, row + 1, col, matrix[row][col], canReachOcean);  // Down
        dfs(matrix, row, col - 1, matrix[row][col], canReachOcean);  // Left
        dfs(matrix, row, col + 1, matrix[row][col], canReachOcean);  // Right
    }
};
