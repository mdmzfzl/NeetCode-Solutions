class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') {
            return 0;
        }
        
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            // Single digit
            int ones = stoi(s.substr(i - 1, 1));
            if (0 < ones && ones < 10) {
                dp[i] += dp[i - 1];
            }

            // Double digit
            int tens = stoi(s.substr(i - 2, 2));
            if (tens >= 10 && tens <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};
