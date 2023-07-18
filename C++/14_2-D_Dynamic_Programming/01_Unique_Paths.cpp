class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> DP(m, vector<int>(n, 1));
        for(int i = m - 2; i >= 0; i--) {
            for(int j = n - 2; j >= 0; j--) {
            DP[i][j] = DP[i+1][j] + DP[i][j+1];
            }
        }
        return DP[0][0];
    }
};
