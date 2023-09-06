"""
Problem: LeetCode 91 - Decode Ways

Key Idea:
The key idea for solving this problem is to use dynamic programming to count the number of ways to decode the given string. We will create a DP array where dp[i] represents the number of ways to decode the string s[:i] (the first i characters of the string).

Time Complexity:
The time complexity is O(n), where n is the length of the input string s. We iterate through the string once to fill in the DP array.

Space Complexity:
The space complexity is O(n) because we use an additional DP array of the same length as the input string.
"""


class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)

        # Initialize a DP array to store the number of ways to decode substrings.
        dp = [0] * (n + 1)

        # Base cases:
        dp[0] = 1  # An empty string can be decoded in one way.
        dp[1] = (
            1 if s[0] != "0" else 0
        )  # The first character can be decoded in one way if it's not '0'.

        # Fill in the DP array.
        for i in range(2, n + 1):
            # Check the one-digit and two-digit possibilities.
            one_digit = int(s[i - 1])
            two_digits = int(s[i - 2 : i])

            # If the one-digit is not '0', it can be decoded in the same way as dp[i-1].
            if one_digit != 0:
                dp[i] += dp[i - 1]

            # If the two-digit is between 10 and 26, it can be decoded in the same way as dp[i-2].
            if 10 <= two_digits <= 26:
                dp[i] += dp[i - 2]

        return dp[n]
