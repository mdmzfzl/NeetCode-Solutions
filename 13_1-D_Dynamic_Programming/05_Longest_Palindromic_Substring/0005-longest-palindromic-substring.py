"""
Problem: LeetCode 5 - Longest Palindromic Substring

Key Idea:
The key idea for solving this problem is to expand around each character in the string and check for palindromes. We will consider each character as the center of a potential palindrome and expand outwards while checking if the characters at both ends are equal. We need to handle two cases: palindromes with odd length (centered at a single character) and palindromes with even length (centered between two characters).

Time Complexity:
The time complexity is O(n^2) because in the worst case, we might expand around each of the 'n' characters, and each expansion can take O(n) time in the worst case.

Space Complexity:
The space complexity is O(1) because we use a constant amount of extra space to store variables.
"""


class Solution:
    def longestPalindrome(self, s: str) -> str:
        def expandAroundCenter(left: int, right: int) -> str:
            # Expand around the center while the characters at both ends are equal.
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            # Return the palindrome substring.
            return s[left + 1 : right]

        if len(s) < 2:
            return s

        longest = ""

        for i in range(len(s)):
            # Check for odd-length palindromes.
            palindrome1 = expandAroundCenter(i, i)
            if len(palindrome1) > len(longest):
                longest = palindrome1

            # Check for even-length palindromes.
            palindrome2 = expandAroundCenter(i, i + 1)
            if len(palindrome2) > len(longest):
                longest = palindrome2

        return longest
