"""
Problem: LeetCode 191 - Number of 1 Bits

Key Idea:
To count the number of 1 bits in an unsigned integer, we can use bit manipulation. We iterate through each bit of the number and use a bitwise AND operation with 1 to check if the least significant bit is 1. If it is, we increment the count and right-shift the number by 1 to check the next bit.

Time Complexity:
- The number of bits in an unsigned integer is constant (32 bits for 32-bit integers and 64 bits for 64-bit integers). Therefore, the time complexity is O(1).

Space Complexity:
- The space complexity is O(1), as we use a constant amount of space.
"""


class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n:
            count += n & 1
            n = n >> 1
        return count
