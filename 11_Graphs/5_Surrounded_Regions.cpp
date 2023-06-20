/**
 * * To solve - 
 * 1. Move over the boundary of board, and find O's 
 * 2. Every time we find an O, perform DFS from it's position
 * 3. In DFS convert all 'O' to 'E'(so we can differentiate which 'O's can be flipped and which cannot)
 * 4. After all DFSs have been performed, board contains three elements: E, O and X
 * 5. 'O' are left over elements which are not connected to any boundary O, so flip them to 'X'
 * 6. 'E' are elements which cannot be flipped to 'X', so flip them back to 'O'
*/

/*
    Given a matrix, capture ('X') all regions that are surrounded ('O')

    Distinguish captured vs escaped, 'X' vs 'O' vs 'E'

    Time: O(m x n)
    Space: O(m x n)
*/

class Solution {
public: 
    void solve(vector<vector<char>> &board) {
        m = board.size();
        if(m == 0) 
			return;
        n = board[0].size();

        // Moving over first and last column
        for (int i = 0; i < m; i++) {
            if(board[i][0] == 'O') 
                dfs(board, i, 0);
            if(board[i][n - 1] == 'O') 
                dfs(board, i, n - 1);
        }

		// Moving over first and last row 
        for (int j = 0; j < n; j++) {
            if(board[0][j] == 'O')
                dfs(board, 0, j);
            if(board[m - 1][j] == 'O')
            dfs(board, m - 1, j);
        }

        // flip cells to correct final states
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'E') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
private: 
    int m, n;
    void dfs(vector<vector<char>> &board, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
            return;
        }

        board[i][j] = 'E';

        dfs(board, i - 1, j);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i, j + 1);
    }
};