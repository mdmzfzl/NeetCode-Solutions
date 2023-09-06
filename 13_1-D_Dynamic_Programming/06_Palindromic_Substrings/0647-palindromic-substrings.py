"""
Problem: LeetCode 647 - Palindromic Substrings

Key Idea:
The key idea for solving this problem is to expand around each character in the string and count the palindromic substrings. We will consider each character as the center of a potential palindrome and expand outwards while checking if the characters at both ends are equal. We need to handle two cases: palindromes with odd length (centered at a single character) and palindromes with even length (centered between two characters).

Time Complexity:
The time complexity is O(n^2) because in the worst case, we might expand around each of the 'n' characters, and each expansion can take O(n) time in the worst case.

Space Complexity:
The space complexity is O(1) because we use a constant amount of extra space to store variables.
"""


class Solution:
    def countSubstrings(self, s: str) -> int:
        def expandAroundCenter(left: int, right: int) -> int:
            count = 0
            # Expand around the center while the characters at both ends are equal.
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
                count += 1
            return count

        if not s:
            return 0

        total_palindromes = 0

        for i in range(len(s)):
            # Check for odd-length palindromes.
            total_palindromes += expandAroundCenter(i, i)

            # Check for even-length palindromes.
            total_palindromes += expandAroundCenter(i, i + 1)

        return total_palindromes
