/*
Problem: LeetCode 286 - Walls and Gates

Description:
You are given an m x n grid rooms initialized with these three possible values:
- -1: A wall or an obstacle.
- 0: A gate.
- INF: Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF, as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, leave it as INF.

Intuition:
To fill each empty room with the distance to its nearest gate, we can use a breadth-first search (BFS) approach. We start the BFS from each gate and propagate the distances to the neighboring empty rooms. We repeat this process for each gate to ensure that all empty rooms are filled with their nearest gate distances.

Approach:
1. Initialize a queue to store the coordinates of the gates.
2. Iterate through the grid and enqueue the coordinates of the gates into the queue.
3. Perform a BFS traversal:
   - For each gate, start the BFS and propagate the distances to the neighboring empty rooms.
   - Initialize a distance variable as 0.
   - While the queue is not empty, process the rooms in the queue:
     - For each room, check its neighboring rooms (up, down, left, right):
       - If a neighboring room is an empty room (INF), mark it with the current distance + 1, enqueue its coordinates, and update the grid.
   - Increment the distance by 1.
4. After the BFS traversal, the grid will be filled with the distances to the nearest gates.

Time Complexity:
The time complexity is O(m * n), where m is the number of rows and n is the number of columns in the grid. In the worst case, we may need to visit all the rooms.

Space Complexity:
The space complexity is O(m * n), where m is the number of rows and n is the number of columns in the grid. This is the space used for the queue to store the coordinates of the gates.
*/

class Solution {
  public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        if (rooms.empty()) {
            return;
        }

        int m = rooms.size();
        int n = rooms[0].size();
        queue<pair<int, int>> gates;  // Queue to store the coordinates of the gates

        // Enqueue the coordinates of the gates
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) {
                    gates.push({i, j});
                }
            }
        }

        // Perform a BFS traversal
        while (!gates.empty()) {
            int size = gates.size();

            for (int i = 0; i < size; ++i) {
                int row = gates.front().first;
                int col = gates.front().second;
                gates.pop();
                // Check neighboring rooms (up, down, left, right)
                vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

                for (const auto &dir : directions) {
                    int newRow = row + dir.first;
                    int newCol = col + dir.second;

                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && rooms[newRow][newCol] == INT32_MAX) {
                        // Mark the neighboring room with the distance to the gate and enqueue its coordinates
                        rooms[newRow][newCol] = rooms[row][col] + 1;
                        gates.push({newRow, newCol});
                    }
                }
            }
        }
    }
};