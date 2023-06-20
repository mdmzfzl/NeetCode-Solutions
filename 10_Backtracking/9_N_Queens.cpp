class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
    vector<bitset<9>> solutions;
    bitset<9> columns;
    bitset<17> diagonals1;
    bitset<17> diagonals2;

    solveNQueensUtil(0, N, columns, diagonals1, diagonals2, solutions);

    return solutions;
    }

private:
    void backtrack(vector<vector<string>>& solutions, vector<string>& board,
                   vector<int>& cols, vector<int>& diag1, vector<int>& diag2,
                   bitset<32>& fullCols, bitset<64>& fullDiag1, bitset<64>& fullDiag2,
                   int row, int n) {
        if (row == n) {
            solutions.push_back(board); // Found a valid solution
            return;
        }

        int availablePositions = ((1 << n) - 1) & ~(cols[row] | diag1[row] | diag2[row]);
        while (availablePositions > 0) {
            int position = availablePositions & -availablePositions; // Get the rightmost available position
            int col = __builtin_ctz(position); // Count trailing zeros to get the column index

            updateState(cols, diag1, diag2, fullCols, fullDiag1, fullDiag2, row, col, n, true); // Place a queen
            board[row][col] = 'Q';
            backtrack(solutions, board, cols, diag1, diag2, fullCols, fullDiag1, fullDiag2, row + 1, n); // Move to the next row
            updateState(cols, diag1, diag2, fullCols, fullDiag1, fullDiag2, row, col, n, false); // Backtrack and remove the queen
            board[row][col] = '.';

            availablePositions &= availablePositions - 1; // Clear the rightmost set bit
        }
    }

    void updateState(vector<int>& cols, vector<int>& diag1, vector<int>& diag2,
                     bitset<32>& fullCols, bitset<64>& fullDiag1, bitset<64>& fullDiag2,
                     int row, int col, int n, bool isPlacing) {
        cols[row] = isPlacing ? 1 : 0;
        diag1[row + col] = isPlacing ? 1 : 0;
        diag2[row - col + n - 1] = isPlacing ? 1 : 0;
        fullCols[col] = isPlacing ? 1 : 0;
        fullDiag1[row - col + n - 1] = isPlacing ? 1 : 0;
        fullDiag2[row + col] = isPlacing ? 1 : 0;
    }
};


/*
// OPTIMIZED SOLUTION - using Backtracking & hashmap

// TC : O(n!)
// SC : O(n*n) = O(n^2)

class Solution {
    void solve(int col, vector<string> &board, int n, vector<int> &leftrow, vector<int> &lowerdiagonal, vector<int> &upperdiagonal, vector<vector<string>> &ans){ // TC: O(n*(n-1)*(n-2)*(n-3)...) = O(n!)
        // base case
        if(col == n){
            ans.push_back(board);
            return;
        }

        // solve 1 case and rest recurssion will take care
        for(int row=0; row<n; row++){
            if(leftrow[row] == 0 && lowerdiagonal[row+col] == 0 && upperdiagonal[n-1+col-row] == 0){ // isSafe func() --> TC: O(1)
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lowerdiagonal[row+col] = 1;
                upperdiagonal[n-1+col-row] = 1;
                solve(col+1, board, n, leftrow, lowerdiagonal, upperdiagonal, ans);
                board[row][col] = '.';
                leftrow[row] = 0;
                lowerdiagonal[row+col] = 0;
                upperdiagonal[n-1+col-row] = 0;
            }
        }
    }

    public:
    vector<vector<string>> solveNQueens(int n) {
        // write your code here

        vector<string> board(n, string(n, '.')); // SC: O(n*n)
        vector<vector<string>> ans; // SC: O(n*n*n)
        
        vector<int> leftrow(n, 0); // SC: O(n)
        vector<int> lowerdiagonal(2*n-1, 0); // SC: O(n)
        vector<int> upperdiagonal(2*n-1, 0); // SC: O(n)
        
        solve(0, board, n, leftrow, lowerdiagonal, upperdiagonal, ans);
        
        return ans;
    }
};
*/