/*
    Given a char board & a word, return true if word exists in the grid

    DFS traversal, set visited cells to '#', search in 4 directions, backtrack

    Time: O(n x 3^l) -> n = # of cells, l = length of word
    Space: O(l)
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                if (board[i][j] == word[0]) 
                    if (dfs(board, word, 0, i, j, m, n)) 
                        return true;
             
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string word, int index, int i, int j, int m, int n) {
        
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index]) 
            return false;

        if (index == word.size() - 1) 
            return true;
        
        // Marking current node as traversed
        board[i][j] = '#';
        
        // Searching in all 4 directions for next letter in word
        if (dfs(board, word, index + 1, i - 1, j, m, n)
            || dfs(board, word, index + 1, i + 1, j, m, n)
            || dfs(board, word, index + 1, i, j - 1, m, n)
            || dfs(board, word, index + 1, i, j + 1, m, n)) {
            return true;
        }
        
        // changing it back to original
        board[i][j] = word[index];
        return false;
    }
};


/*
class Solution {
    public: bool arr[7][7] = {0};
    bool ans(vector < vector < char >> & b, int m, int n, string s, int i, int j, int pos) {
        if (pos == s.size())
            return true;
        if (i >= m or i < 0 or j >= n or j < 0 or b[i][j] != s[pos] or arr[i][j] == 1)
            return false;
        arr[i][j] = 1;
        bool t = ans(b, m, n, s, i - 1, j, pos + 1);
        bool d = ans(b, m, n, s, i + 1, j, pos + 1);
        bool l = ans(b, m, n, s, i, j - 1, pos + 1);
        bool r = ans(b, m, n, s, i, j + 1, pos + 1);
        arr[i][j] = 0;
        return l or r or t or d;
    }

    bool exist(vector < vector < char >> & board, string word) {
        int m = board.size();
        int n = board[0].size();
        // leet codes optimiztion
        int first = 0, last = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) first++;
                else if (board[i][j] == word[word.size() - 1]) last++;
            }
        }
        if (first > last) reverse(word.begin(), word.end());
        // opt ends
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (ans(board, m, n, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};
*/

