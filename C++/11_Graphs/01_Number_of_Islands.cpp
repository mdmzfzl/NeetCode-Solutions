class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;

        // If we find island we increment our result and call dfs to mark all nodes in that island as visited
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == '1') {
                    DFS(grid, i, j);
                    islands++;
                }
        
        return islands;
    }

private:
    void DFS(vector<vector<char>>& grid, int row, int col) {
        // If row and col are out of bounds
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) 
            return;
        
        // If it's water or already visited, return
        if(grid[row][col] == '2' || grid[row][col] == '0')
            return;
        
        // Marking visited nodes as 2
        grid[row][col] = '2';

        // Marking all nodes around it that are island blocks as visited
        DFS(grid, row + 1, col);
        DFS(grid, row - 1, col);
        DFS(grid, row, col + 1);
        DFS(grid, row, col - 1);
    }
};


/*
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        //step 1 : iterate over all elements in matrix
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0;j < grid[0].size(); j++) {
                // step 2: as soon as we find '1' replace it with 0 and look adjacent elements
                if(grid[i][j] == '1') {
                    fnc(grid, i, j);
                    count++;
                }
            }
        }
        return count; 
    }

    void fnc(vector<vector<char>>& grid, int i, int j) {
        // conditions for 'out of bounce' ie if 1 lies on the boundary
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return;
        }
        if(grid[i][j] == '0') {   // if while iterating we find 0 will simply return back
            return;
        }

        grid[i][j] = '0'; // replacing the encountered 1 with 0

        fnc(grid, i+1, j); // just row above 1 
        fnc(grid, i-1, j); // just row below 1 
        fnc(grid, i, j-1); // just column left to 1 
        fnc(grid, i, j+1); // just column right to 1 
    }
};
*/