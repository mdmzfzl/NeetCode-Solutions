"""
Problem: LeetCode 22 - Generate Parentheses

Key Idea:
To generate all valid combinations of parentheses, we can use backtracking. We start with an empty string and two counters, one for the open parentheses and one for the close parentheses. At each step, we have two choices: add an open parenthesis if the count of open parentheses is less than the total number of pairs, or add a close parenthesis if the count of close parentheses is less than the count of open parentheses. We continue this process recursively until we reach the desired length of the string. If the string becomes valid, we add it to the result.

Time Complexity:
The time complexity of this solution is O(4^n / sqrt(n)), where n is the number of pairs of parentheses. This is because each valid combination is a sequence of open and close parentheses of length 2n, and there are 2^(2n) such sequences. However, not all sequences are valid, and the Catalan number (4^n / sqrt(n)) bounds the number of valid combinations.

Space Complexity:
The space complexity is O(4^n / sqrt(n)) as well, as this is the maximum number of valid combinations that can be generated.
"""


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def backtrack(s, open_count, close_count):
            if len(s) == 2 * n:
                result.append(s)
                return

            if open_count < n:
                backtrack(s + "(", open_count + 1, close_count)
            if close_count < open_count:
                backtrack(s + ")", open_count, close_count + 1)

        result = []
        backtrack("", 0, 0)
        return result
