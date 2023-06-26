class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area;
        // If we find island we do DFS to calculate the area of the island and mark it as traversed
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 1) {
                    area = 0;
                    DFS(grid, i, j, area);
                }
        
        return maxArea;
    }
private:
    int maxArea = 0;
    void DFS(vector<vector<int>>& grid, int row, int col, int& area) {
        // If row and col are out of bounds
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) 
            return;
        
        // If it's water or already visited, return
        if(grid[row][col] == 0)
            return;

        // Marking visited nodes as 0
        grid[row][col] = 0;

        // area = area of current island
        area += 1;
        if(area > maxArea)
            maxArea = area;

        // Calling DFS for other 4 directions
        DFS(grid, row + 1, col, area);
        DFS(grid, row - 1, col, area);
        DFS(grid, row, col + 1, area);
        DFS(grid, row, col - 1, area);
    }
};

/*
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                if (grid[i][j]) ans = max(ans, trav(i, j, grid));
        return ans;
    }
private:
    int n, m;
    int trav(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= n || j >= m || !grid[i][j]) return 0;
        grid[i][j] = 0;
        return 1 + trav(i-1, j, grid) + trav(i, j-1, grid) + trav(i+1, j, grid) + trav(i, j+1, grid);
    }
};
*/