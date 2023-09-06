"""
Problem: LeetCode 139 - Word Break

Key Idea:
The key idea is to use dynamic programming to determine if it's possible to break the input string into words from the wordDict. We can create a boolean array dp, where dp[i] is True if we can break the substring s[0:i] into words from the wordDict.

Time Complexity:
The time complexity is O(n^2), where 'n' is the length of the input string. We iterate through the string and for each character, we check if it can be broken into words from the wordDict.

Space Complexity:
The space complexity is O(n) because we use a boolean array dp of length 'n' to store the results.
"""


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        # Create a set for faster word lookup.
        wordSet = set(wordDict)

        # Initialize a boolean array dp where dp[i] is True if s[0:i] can be broken into words.
        dp = [False] * (len(s) + 1)
        dp[0] = True  # An empty string can always be broken.

        # Iterate through the string.
        for i in range(1, len(s) + 1):
            for j in range(i):
                # Check if the substring s[j:i] is in the wordDict and if s[0:j] can be broken.
                if dp[j] and s[j:i] in wordSet:
                    dp[i] = True
                    break  # No need to continue checking.

        return dp[len(s)]
