"""
Problem: LeetCode 198 - House Robber

Key Idea:
The key idea to solve this problem is to use dynamic programming. We create a list `dp` where `dp[i]` represents the maximum amount of money that can be robbed up to the `i-th` house.

To populate `dp`, we iterate through the houses from left to right. For each house `i`, we have two choices:
1. Rob the current house, which means we add the money from the current house (`nums[i]`) to the amount robbed from two houses before (`dp[i-2]`).
2. Skip the current house and take the maximum amount robbed from the previous house (`dp[i-1]`).

We choose the maximum of these two options and update `dp[i]` accordingly. Finally, `dp[-1]` will contain the maximum amount that can be robbed.

Time Complexity:
The time complexity is O(n) because we iterate through the list of houses once.

Space Complexity:
The space complexity is O(n) because we use a list `dp` to store the maximum amounts that can be robbed up to each house.
"""


class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]

        dp = [0] * n
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])

        for i in range(2, n):
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])

        return dp[-1]
