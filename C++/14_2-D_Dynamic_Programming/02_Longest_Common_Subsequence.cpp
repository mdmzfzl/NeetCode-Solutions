/*
Problem: LeetCode 1143 - Longest Common Subsequence

Description:
Given two strings text1 and text2, return the length of their longest common subsequence.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted
without changing the relative order of the remaining characters.

Intuition:
To find the longest common subsequence between two strings, we can use dynamic programming.
The problem can be broken down into smaller subproblems by considering different suffixes of the strings.
We can build the solution by finding the longest common subsequence for each pair of suffixes.

Approach:
1. Initialize a 2D array dp of size (m+1) x (n+1), where dp[i][j] represents the length of the longest common subsequence
   between the first i characters of text1 and the first j characters of text2.
2. Initialize the first row and first column of dp to 0.
3. Iterate through the characters of text1 and text2:
   - If the current characters are equal, dp[i][j] = dp[i-1][j-1] + 1.
     This means that we include the current character in the longest common subsequence.
   - Otherwise, dp[i][j] = max(dp[i-1][j], dp[i][j-1]).
     This means that we exclude one character either from text1 or text2 to find the longest common subsequence.
4. Return dp[m][n], which represents the length of the longest common subsequence.

Time Complexity:
The time complexity is O(m * n), where m and n are the lengths of text1 and text2, respectively.

Space Complexity:
The space complexity is O(m * n), as we use a 2D array to store the length of the longest common subsequence.

Dynamic Programming:
- Subproblem: The subproblem is finding the longest common subsequence for each pair of suffixes of the strings.
- Recurrence Relation: If text1[i] == text2[j], dp[i][j] = dp[i-1][j-1] + 1. Otherwise, dp[i][j] = max(dp[i-1][j], dp[i][j-1]).
- Base Case: Initialize the first row and first column of dp to 0.
*/

class Solution {
  public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // Length of longest common subsequence

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1; // Include the current character
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Exclude one character
                }
            }
        }

        return dp[m][n]; // Length of longest common subsequence
    }
};