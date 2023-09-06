"""
Problem: LeetCode 338 - Counting Bits

Key Idea:
To count the number of 1 bits for each number in the range [0, num], we can use dynamic programming. We observe that the number of 1 bits in a number x is equal to the number of 1 bits in x // 2 plus the value of the least significant bit (x % 2).

Time Complexity:
- We iterate through each number in the range [0, num] and perform constant-time operations for each number. Therefore, the time complexity is O(n), where n is the value of 'num'.

Space Complexity:
- The space complexity is O(n), as we use an array of size 'num + 1' to store the count of 1 bits for each number in the range.
"""


class Solution:
    def countBits(self, num: int) -> List[int]:
        bits_count = [0] * (num + 1)

        for i in range(1, num + 1):
            bits_count[i] = bits_count[i // 2] + (i % 2)

        return bits_count
