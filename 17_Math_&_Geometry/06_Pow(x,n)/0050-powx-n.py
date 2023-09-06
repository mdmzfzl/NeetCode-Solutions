"""
Problem: LeetCode 50 - Pow(x, n)

Key Idea:
The problem is to calculate x raised to the power n. We can solve this problem using the concept of exponentiation by squaring. If n is even, we can compute x^n as (x^(n//2)) * (x^(n//2)). If n is odd, we can compute x^n as x * (x^(n//2)) * (x^(n//2)).

Time Complexity:
- The time complexity of this approach is O(log n), where n is the exponent.

Space Complexity:
- The space complexity is O(log n), as we use the call stack for the recursive calculations.
"""


class Solution:
    def myPow(self, x: float, n: int) -> float:
        def helper(base, exp):
            if exp == 0:
                return 1.0
            temp = helper(base, exp // 2)
            if exp % 2 == 0:
                return temp * temp
            else:
                return base * temp * temp

        if n < 0:
            x = 1 / x
            n = -n

        return helper(x, n)
