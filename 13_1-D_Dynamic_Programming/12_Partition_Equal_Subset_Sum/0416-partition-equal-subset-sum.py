"""
Problem: LeetCode 416 - Partition Equal Subset Sum

Key Idea:
The key idea is to use dynamic programming to determine if it's possible to partition the input array into two subsets with equal sums. We create a dynamic programming array dp, where dp[i][j] represents whether it's possible to form a subset with a sum of 'j' using the first 'i' elements of the input array.

Time Complexity:
The time complexity is O(n * sum(nums)), where 'n' is the length of the input nums and 'sum(nums)' is the sum of all elements in the input. This is because we use a nested loop to iterate through each element in nums and each possible sum up to 'sum(nums)'.

Space Complexity:
The space complexity is O(n * sum(nums)) because we use a 2D dp array of size (n+1) x (sum(nums)+1) to store the results.
"""


class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total_sum = sum(nums)

        # If the total sum is odd, it's impossible to partition into two equal subsets.
        if total_sum % 2 != 0:
            return False

        target_sum = total_sum // 2

        # Initialize a dynamic programming array dp with all values set to False.
        dp = [False] * (target_sum + 1)

        # It's always possible to achieve a sum of 0 using an empty subset.
        dp[0] = True

        for num in nums:
            for i in range(target_sum, num - 1, -1):
                # If it's possible to achieve a sum of 'i - num' using a subset,
                # then it's also possible to achieve a sum of 'i' using a subset.
                dp[i] = dp[i] or dp[i - num]

        return dp[target_sum]
