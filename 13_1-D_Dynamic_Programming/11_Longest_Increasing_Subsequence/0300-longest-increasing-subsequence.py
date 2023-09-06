"""
Problem: LeetCode 300 - Longest Increasing Subsequence

Key Idea:
The key idea is to use dynamic programming to find the length of the longest increasing subsequence. We create a dynamic programming array dp, where dp[i] represents the length of the longest increasing subsequence ending at index i.

Time Complexity:
The time complexity is O(n^2), where 'n' is the length of the input nums. We use a nested loop to compare and update the values in the dp array.

Space Complexity:
The space complexity is O(n) because we use an additional dp array of length 'n' to store the results.
"""


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0

        # Initialize a dynamic programming array dp with all values set to 1.
        dp = [1] * len(nums)

        # Iterate through the array to find the longest increasing subsequence.
        for i in range(len(nums)):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)

        # Return the maximum value in dp, which represents the length of the longest increasing subsequence.
        return max(dp)
