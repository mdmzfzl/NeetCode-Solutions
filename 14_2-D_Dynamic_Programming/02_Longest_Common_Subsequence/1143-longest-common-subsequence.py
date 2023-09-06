"""
Problem: LeetCode 1143 - Longest Common Subsequence

Key Idea:
The key idea is to use dynamic programming to find the length of the longest common subsequence (LCS) between two strings. We create a 2D dp array where dp[i][j] represents the length of the LCS between the first i characters of text1 and the first j characters of text2.

Time Complexity:
The time complexity is O(m*n), where 'm' is the length of text1 and 'n' is the length of text2. We iterate through both strings once to fill in the dp array.

Space Complexity:
The space complexity is O(m*n) because we use an additional dp array of the same size as the input strings.
"""


class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)

        # Create a 2D dp array of size (m+1) x (n+1) and initialize it with zeros.
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        # Fill in the dp array using dynamic programming.
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if text1[i - 1] == text2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

        # The value in dp[m][n] represents the length of the LCS.
        return dp[m][n]
