"""
Problem: LeetCode 268 - Missing Number

Key Idea:
To find the missing number in an array containing distinct numbers from 0 to n, we can use the XOR operation. We XOR all the numbers from 0 to n and then XOR the result with all the elements in the array. The XOR operation cancels out the duplicate numbers, leaving only the missing number.

Time Complexity:
- XORing all the numbers from 0 to n takes O(n) time, and XORing all the elements in the array also takes O(n) time. Therefore, the total time complexity is O(n).

Space Complexity:
- The space complexity is O(1), as we use a constant amount of space.
"""


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        missing_num = n

        for i in range(n):
            missing_num ^= i ^ nums[i]

        return missing_num
