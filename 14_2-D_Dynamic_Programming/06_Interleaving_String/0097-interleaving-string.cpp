/*
Problem: LeetCode 97 - Interleaving String

Description:
Given strings s1, s2, and s3, find whether s3 is formed by the interleaving of s1 and s2.

Intuition:
To determine if s3 can be formed by interleaving s1 and s2, we can use dynamic programming.
The problem can be broken down into smaller subproblems, where we check if a prefix of s3 can be formed by interleaving prefixes of s1 and s2.

Approach:
1. Create a 2D dp array of size (s1.length()+1) x (s2.length()+1), where dp[i][j] represents whether s3[0...i+j-1] can be formed by interleaving s1[0...i-1] and s2[0...j-1].
2. Initialize dp[0][0] as true, representing the base case where both s1 and s2 are empty, and s3 is also empty.
3. Fill in the dp array using the following recurrence relation:
   - dp[i][j] is true if one of the following conditions is met:
     - dp[i-1][j] is true, and s1[i-1] is equal to s3[i+j-1].
     - dp[i][j-1] is true, and s2[j-1] is equal to s3[i+j-1].
4. Return dp[s1.length()][s2.length()], which represents whether s3 can be formed by interleaving s1 and s2.

Time Complexity:
The time complexity is O(s1.length() * s2.length()), as we fill in the entire dp array.

Space Complexity:
The space complexity is O(s1.length() * s2.length()), as we use a 2D array to store the intermediate results.

Dynamic Programming:
- Subproblem: The subproblem is checking if a prefix of s3 can be formed by interleaving prefixes of s1 and s2.
- Recurrence Relation: dp[i][j] is true if dp[i-1][j] is true and s1[i-1] is equal to s3[i+j-1], or if dp[i][j-1] is true and s2[j-1] is equal to s3[i+j-1].
- Base Case: Initialize dp[0][0] as true, representing the base case where both s1 and s2 are empty, and s3 is also empty.
*/

class Solution {
  public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();

        // If the lengths of s1 and s2 do not add up to the length of s3, it's not possible to form s3 by interleaving s1 and s2
        if (m + n != s3.length()) {
            return false;
        }

        // Create a 2D dp array to store the results of subproblems
        // dp[i][j] represents whether the first i characters of s1 and the first j characters of s2 can form the first i + j characters of s3
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        // Base case: Both s1 and s2 are empty, and the result is true
        dp[0][0] = true;

        // Loop through each possible combination of i and j
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                // Check if the previous characters of s1 and s3 match
                if (i > 0 && s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }

                // Check if the previous characters of s2 and s3 match
                if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }

        // Return the result, whether the last characters of s1 and s2 can form the last characters of s3
        return dp[m][n];
    }
};