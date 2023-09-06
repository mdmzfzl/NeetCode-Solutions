"""
Problem: LeetCode 72 - Edit Distance

Key Idea:
The key idea is to use dynamic programming to calculate the minimum number of operations (insert, delete, or replace) required to transform one string 'word1' into another string 'word2'. We can define a 2D table 'dp' where dp[i][j] represents the minimum edit distance between the first 'i' characters of 'word1' and the first 'j' characters of 'word2'.

Time Complexity:
The time complexity is O(m * n), where 'm' is the length of string 'word1' and 'n' is the length of string 'word2'. We iterate through both strings once to fill the dp table.

Space Complexity:
The space complexity is O(m * n) as we use a 2D table 'dp' of the same size to store the results of subproblems.
"""


class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)

        # Create a 2D table dp to store the minimum edit distance.
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        # Initialize the first row and first column of dp.
        for i in range(m + 1):
            dp[i][0] = i
        for j in range(n + 1):
            dp[0][j] = j

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                # If the characters match, no additional operation is needed.
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    # Choose the minimum of the three possible operations:
                    # 1. Insert a character (dp[i][j - 1] + 1)
                    # 2. Delete a character (dp[i - 1][j] + 1)
                    # 3. Replace a character (dp[i - 1][j - 1] + 1)
                    dp[i][j] = min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1

        return dp[m][n]
