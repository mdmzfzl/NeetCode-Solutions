"""
Problem: LeetCode 97 - Interleaving String

Key Idea:
The key idea is to use dynamic programming to determine whether s3 can be formed by interleaving s1 and s2.

Time Complexity:
The time complexity is O(m * n), where 'm' is the length of string 's1' and 'n' is the length of string 's2'. We use a 2D array 'dp' of size (m + 1) x (n + 1) to store intermediate results.

Space Complexity:
The space complexity is O(m * n), as we use a 2D array 'dp' of size (m + 1) x (n + 1) to store intermediate results.
"""


class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        # Get the lengths of s1, s2, and s3.
        m, n, p = len(s1), len(s2), len(s3)

        # If the sum of lengths of s1 and s2 is not equal to the length of s3, return False.
        if m + n != p:
            return False

        # Initialize a 2D DP array dp of size (m + 1) x (n + 1) to store intermediate results.
        dp = [[False] * (n + 1) for _ in range(m + 1)]

        # Base case: dp[0][0] is True since two empty strings can form an empty string.
        dp[0][0] = True

        # Fill in the first row of dp.
        for j in range(1, n + 1):
            dp[0][j] = dp[0][j - 1] and s2[j - 1] == s3[j - 1]

        # Fill in the first column of dp.
        for i in range(1, m + 1):
            dp[i][0] = dp[i - 1][0] and s1[i - 1] == s3[i - 1]

        # Fill in the rest of dp.
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                # For dp[i][j] to be True, one of the following conditions must be met:
                # 1. dp[i-1][j] is True and s1[i-1] matches s3[i+j-1].
                # 2. dp[i][j-1] is True and s2[j-1] matches s3[i+j-1].
                dp[i][j] = (dp[i - 1][j] and s1[i - 1] == s3[i + j - 1]) or (
                    dp[i][j - 1] and s2[j - 1] == s3[i + j - 1]
                )

        # The result is stored in dp[m][n].
        return dp[m][n]
