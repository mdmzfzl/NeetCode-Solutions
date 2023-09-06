"""
Problem: LeetCode 190 - Reverse Bits

Key Idea:
To reverse the bits of a given unsigned integer, we can iterate through each bit of the input number. For each bit, we use bitwise operations to reverse the bit and append it to the result.

Time Complexity:
- The number of bits in an unsigned integer is constant (32 bits for 32-bit integers and 64 bits for 64-bit integers). Therefore, the time complexity is O(1).

Space Complexity:
- The space complexity is O(1), as we use a constant amount of space.
"""


class Solution:
    def reverseBits(self, n: int) -> int:
        reversed_num = 0
        for _ in range(32):
            reversed_num = (reversed_num << 1) | (n & 1)
            n = n >> 1
        return reversed_num
