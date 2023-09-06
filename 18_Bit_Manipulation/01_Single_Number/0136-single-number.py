"""
Problem: LeetCode 136 - Single Number

Key Idea:
To find the single number in an array where all other numbers appear twice, we can use the XOR operation. XORing a number with itself results in 0, and XORing any number with 0 results in the number itself. Therefore, if we XOR all the numbers in the array, the duplicates will cancel out, leaving only the single number.

Time Complexity:
- The XOR operation has a time complexity of O(n), where n is the number of elements in the array.

Space Complexity:
- The space complexity is O(1), as we only need a constant amount of space to store the XOR result.
"""


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result = 0
        for num in nums:
            result ^= num
        return result
