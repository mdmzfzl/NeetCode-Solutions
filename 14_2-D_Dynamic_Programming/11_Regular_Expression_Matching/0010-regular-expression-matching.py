"""
Problem: LeetCode 10 - Regular Expression Matching

Key Idea:
The key idea is to use dynamic programming to solve this problem. We create a 2D table 'dp' where dp[i][j] represents whether the first 'i' characters in the string 's' match the first 'j' characters in the pattern 'p'. We fill this table based on the characters in 's' and 'p' and previous results.

Time Complexity:
The time complexity is O(m * n), where 'm' is the length of the string 's' and 'n' is the length of the pattern 'p'. We have a nested loop that iterates through the characters in 's' and 'p'.

Space Complexity:
The space complexity is O(m * n) as we use a 2D table 'dp' of size m x n to store the results of subproblems.
"""


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)

        # Create a 2D table dp to store whether s[:i] matches p[:j].
        dp = [[False] * (n + 1) for _ in range(m + 1)]

        # Base case: empty string matches empty pattern.
        dp[0][0] = True

        # Fill the first row of dp based on '*' in the pattern.
        for j in range(2, n + 1):
            if p[j - 1] == "*":
                dp[0][j] = dp[0][j - 2]

        # Fill the dp table based on characters in s and p.
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if p[j - 1] == s[i - 1] or p[j - 1] == ".":
                    dp[i][j] = dp[i - 1][j - 1]
                elif p[j - 1] == "*":
                    dp[i][j] = dp[i][j - 2] or (
                        dp[i - 1][j] and (s[i - 1] == p[j - 2] or p[j - 2] == ".")
                    )

        return dp[m][n]
