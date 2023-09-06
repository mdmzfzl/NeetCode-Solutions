"""
Problem: LeetCode 43 - Multiple Strings

Key Idea:
The problem is to multiply two given non-negative integers represented as strings. We can perform multiplication digit by digit, similar to how we do multiplication manually. We start from the least significant digits and move towards the most significant digits. We use two nested loops to multiply each pair of digits and keep track of carry values.

Time Complexity:
- The time complexity of this approach is O(m * n), where m and n are the lengths of the input strings.

Space Complexity:
- The space complexity is O(m + n), as the length of the result can be at most m + n digits.
"""


class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"

        m, n = len(num1), len(num2)
        result = [0] * (m + n)

        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                product = int(num1[i]) * int(num2[j])
                sum_val = product + result[i + j + 1]
                result[i + j + 1] = sum_val % 10
                result[i + j] += sum_val // 10

        return "".join(map(str, result)).lstrip("0")
