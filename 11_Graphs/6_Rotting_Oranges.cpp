/**
 * * Approach
 * 1. Create a visited grid to store the state of the cell (fresh, rotten, or empty).
 * 2. Initialize a queue to store the rotten oranges and count the number of fresh oranges.
 * 3. Check if there are no fresh oranges, return 0, or if there are no rotten oranges, return -1.
 * 4. Loop while the queue is not empty. 
 *      a. Store the size of the queue.
 *      b. Loop through the size of the queue. 
 *          i. Get the front cell of the queue.
 *          ii. Check all four directions of the cell to see if there are any fresh oranges.
 *          iii. If there is a fresh orange, change its state to rotten and decrement the count of fresh oranges, and push the cell into the queue.
 *      c. Increment the minutes.
 * 5. If there are no fresh oranges, return the minutes.
 * 6. If there are still fresh oranges, return -1.
*/

/*
    BFS: rotten will contaminate neighbors first, then propagate out

    Time: O(m x n)
    Space: O(m x n)
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // build initial set of rotten oranges
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        // mark the start of a minute
        q.push({-1, -1});
        
        int result = -1;
        
        // start rotting process via BFS
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            if (row == -1) {
                // finish 1 minute of processing, mark next minute
                result++;
                if (!q.empty()) {
                    q.push({-1, -1});
                }
            } else {
                // rotten orange, contaminate its neighbors
                for (int i = 0; i < dirs.size(); i++) {
                    int x = row + dirs[i][0];
                    int y = col + dirs[i][1];
                    
                    if (x < 0 || x >= m || y < 0 || y >= n) {
                        continue;
                    }
                    
                    if (grid[x][y] == 1) {
                        // contaminate
                        grid[x][y] = 2;
                        fresh--;
                        // this orange will now contaminate others
                        q.push({x, y});
                    }
                }
            }
        }
        
        if (fresh == 0) {
            return result;
        }
        return -1;
    }
private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
