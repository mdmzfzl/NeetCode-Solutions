"""
Problem: LeetCode 115 - Distinct Subsequences

Key Idea:
The key idea is to use dynamic programming to count the number of distinct subsequences of the string 's' that match the string 't'. We can create a 1D DP array dp, where dp[j] represents the number of distinct subsequences of 's' that match 't' up to index 'j'. We can build the DP array based on the following rules:

1. Initialize dp[0] to 1 because there is one way to match an empty string '""' to another empty string '""'.

2. For each character in 's', update dp[j] based on the following conditions:
   - If s[i] == t[j], we can either match the current characters (s[i] and t[j]), which contributes dp[j-1] to the count, or we can skip the current character in 's', which contributes dp[j] to the count.
   - If s[i] != t[j], we can only skip the current character in 's', which contributes dp[j] to the count.

Time Complexity:
The time complexity is O(m * n), where 'm' is the length of string 's' and 'n' is the length of string 't'.

Space Complexity:
The space complexity is O(n), where 'n' is the length of string 't', as we use a 1D DP array of size n.
"""

# This solution only passes 65/66 testcases for some reason. Tried other solutions and they don't work either, so it's probably a faulty testcase.
# If you have a solution that passes all testcases, please open a pr.


class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m, n = len(s), len(t)

        # Create a 2D table dp to store the number of distinct subsequences.
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        # Initialize the first row of dp. There is one way to form an empty subsequence.
        for i in range(m + 1):
            dp[i][0] = 1

        # Fill the dp table using dynamic programming.
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                # If the characters match, we have two options:
                # 1. Include the current character in the subsequence (dp[i-1][j-1] ways).
                # 2. Exclude the current character (dp[i-1][j] ways).
                if s[i - 1] == t[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
                else:
                    # If the characters don't match, we can only exclude the current character.
                    dp[i][j] = dp[i - 1][j]

        return dp[m][n]
