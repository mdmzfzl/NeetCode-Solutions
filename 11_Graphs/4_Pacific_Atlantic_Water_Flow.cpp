/*
    Top & left pacific, bottom & right atlantic, determine spots that flow to both

    Instead go outside in, from oceans to spots where rain could flow from
    Faster bc avoids repeated work: cells along a path can also reach that ocean

    Time: O(m x n)
    Space: O(m x n)
*/

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // row and col sizes
        row = heights.size();
        col = heights[0].size();
        
        // Vectors for checking if water can flow from the corners to inside
        vector<vector<bool>> pacific(row, vector<bool>(col));
        vector<vector<bool>> atlantic(row, vector<bool>(col));
        
        // Doing DFS for all the elements on edges of the island
        for (int i = 0; i < row; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, col - 1);
        }
        
        for (int j = 0; j < col; j++) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, row - 1, j);
        }
        
        vector<vector<int>> result;
        
        // If water can flow both to the atlantic and pacific
        // add to the result vector
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }

private:
    int row, col;
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j) {
        
        visited[i][j] = true;
        
        if (i > 0 && !visited[i - 1][j] && heights[i - 1][j] >= heights[i][j]) {
            dfs(heights, visited, i - 1, j);
        }
        if (i < row - 1 && !visited[i + 1][j] && heights[i + 1][j] >= heights[i][j]) {
            dfs(heights, visited, i + 1, j);
        }
        if (j > 0 && !visited[i][j - 1] && heights[i][j - 1] >= heights[i][j]) {
            dfs(heights, visited, i, j - 1);
        }
        if (j < col - 1 && !visited[i][j + 1] && heights[i][j + 1] >= heights[i][j]) {
            dfs(heights, visited, i, j + 1);
        }
    }
};
