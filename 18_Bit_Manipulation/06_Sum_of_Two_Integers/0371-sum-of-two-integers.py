"""
Problem: LeetCode 371 - Sum of Two Integers

Key Idea:
To calculate the sum of two integers without using the + and - operators, we can use bitwise operations. We use the XOR operation (^) to calculate the sum without considering the carry, and the AND operation (&) followed by a left shift (<<) to calculate the carry. We repeat these steps until there is no carry left.

Time Complexity:
- The number of iterations required to calculate the sum is proportional to the number of bits in the input integers, which is constant. Therefore, the time complexity is O(1).

Space Complexity:
- The space complexity is O(1), as we use a constant amount of space.
"""


class Solution:
    def getSum(self, a: int, b: int) -> int:
        MASK = 0xFFFFFFFF
        MAX_INT = 0x7FFFFFFF

        while b != 0:
            a, b = (a ^ b) & MASK, ((a & b) << 1) & MASK

        return a if a <= MAX_INT else ~(a ^ MASK)
