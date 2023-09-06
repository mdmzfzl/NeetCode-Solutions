"""
Problem: LeetCode 213 - House Robber II

Key Idea:
The key idea for solving this problem is to recognize that it's an extension of the House Robber I problem (LeetCode 198). Since we cannot rob adjacent houses, we have two scenarios:
1. Rob the first house and exclude the last house.
2. Exclude the first house and consider robbing the last house.

We calculate the maximum amount for both scenarios using the House Robber I algorithm and return the maximum of the two results.

Time Complexity:
The time complexity is O(n) because we use the House Robber I algorithm twice, once excluding the last house and once excluding the first house.

Space Complexity:
The space complexity is O(1) because we use a constant amount of extra space to store variables.
"""


class Solution:
    def rob(self, nums: List[int]) -> int:
        def houseRobber(nums: List[int]) -> int:
            n = len(nums)
            if n == 0:
                return 0
            if n == 1:
                return nums[0]

            prev = 0
            curr = 0

            for num in nums:
                temp = curr
                curr = max(prev + num, curr)
                prev = temp

            return curr

        if len(nums) == 1:
            return nums[0]

        # Rob first house and exclude the last house, or exclude the first house and rob the last house.
        return max(houseRobber(nums[1:]), houseRobber(nums[:-1]))
