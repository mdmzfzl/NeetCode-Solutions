"""
Problem: LeetCode 7 - Reverse Integer

Key Idea:
To reverse an integer, we can use integer arithmetic. We repeatedly extract the last digit of the number using the modulo operator (%) and add it to the reversed number after multiplying by 10. We then update the original number by integer division (//) to remove the last digit. We continue this process until the original number becomes 0.

Time Complexity:
- The time complexity is O(log(x)), where x is the input integer. We perform operations on each digit of the integer.

Space Complexity:
- The space complexity is O(1), as we use a constant amount of space.
"""


class Solution:
    def reverse(self, x: int) -> int:
        INT_MAX = 2**31 - 1
        INT_MIN = -(2**31)

        reversed_num = 0
        sign = 1 if x > 0 else -1
        x = abs(x)

        while x != 0:
            pop = x % 10
            x //= 10

            if reversed_num > (INT_MAX - pop) // 10:
                return 0

            reversed_num = reversed_num * 10 + pop

        return reversed_num * sign
