"""
Problem: LeetCode 678 - Valid Parenthesis String

Key Idea:
We can solve this problem using a greedy approach. The idea is to keep track of the possible lower and upper bound of valid open parentheses count as we traverse the string. For every '(', we increment both lower and upper bounds, for every ')', we decrement both bounds, and for '*', we increment the lower bound and decrement the upper bound. At each step, we ensure that the lower bound never goes below 0.

Time Complexity:
- The time complexity of this approach is O(n), where n is the length of the input string.

Space Complexity:
- The space complexity is O(1), as we only use a constant amount of additional space for variables.
"""


class Solution:
    def checkValidString(self, s: str) -> bool:
        lower = upper = 0

        for char in s:
            if char == "(":
                lower += 1
                upper += 1
            elif char == ")":
                lower = max(lower - 1, 0)
                upper -= 1
            else:  # char == '*'
                lower = max(lower - 1, 0)
                upper += 1

            if upper < 0:
                return False

        return lower == 0
