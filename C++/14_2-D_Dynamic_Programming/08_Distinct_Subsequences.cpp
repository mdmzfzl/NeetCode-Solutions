/*
Problem: LeetCode 115 - Distinct Subsequences

Description:
Given two strings s and t, return the number of distinct subsequences of s which equals t.
A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters.
It is guaranteed the answer fits on a 32-bit signed integer.

Intuition:
To find the number of distinct subsequences of s which equals t, we can use dynamic programming. The problem can be broken down into smaller subproblems, where we find the number of distinct subsequences for each prefix of s and t.

Approach:
1. Create a 2D dp array of size (m+1) x (n+1), where m is the length of string s and n is the length of string t. The dp[i][j] represents the number of distinct subsequences of the first i characters of string s and the first j characters of string t.
2. Initialize the first column dp[i][0] to 1, as there is one way to delete all characters from string s to get an empty string, which matches the empty string t.
3. For each (i, j) in the dp array, calculate the value using the recurrence relation:
   - If the current characters in s and t match (s[i-1] == t[j-1]), dp[i][j] = dp[i-1][j-1] + dp[i-1][j].
   - Otherwise, dp[i][j] = dp[i-1][j].
4. Return dp[m][n], which represents the number of distinct subsequences of s which equals t.

Time Complexity:
The time complexity is O(m * n), where m is the length of string s and n is the length of string t, as we fill the dp array of size (m+1) x (n+1).

Space Complexity:
The space complexity is O(m * n), where m is the length of string s and n is the length of string t, as we use a 2D dp array to store the number of distinct subsequences for each prefix of s and t.

Dynamic Programming:
- Subproblem: The subproblem is finding the number of distinct subsequences of the first i characters of string s and the first j characters of string t.
- Recurrence Relation: For each (i, j) in the dp array, calculate the value using the recurrence relation:
   - If the current characters in s and t match (s[i-1] == t[j-1]), dp[i][j] = dp[i-1][j-1] + dp[i-1][j].
   - Otherwise, dp[i][j] = dp[i-1][j].
- Base Case: Initialize the first column dp[i][0] to 1, as there is one way to delete all characters from string s to get an empty string, which matches the empty string t.
*/

class Solution {
  public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        // Create a 2D DP array to store the number of distinct subsequences
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));

        // Base case: there is one way to delete all characters from s to get an empty string (t = "")
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }

        // Calculate the number of distinct subsequences
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // If the current characters match, we can either include or exclude s[i-1] in the subsequence
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    // If the characters don't match, we can only exclude s[i-1] from the subsequence
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // The value at dp[m][n] represents the number of distinct subsequences of t in s
        return dp[m][n];
    }
};