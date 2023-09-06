"""
Problem: LeetCode 312 - Burst Balloons

Key Idea:
The key idea is to use dynamic programming to calculate the maximum coins that can be obtained by bursting balloons in a certain order. We create a 2D table 'dp' where dp[i][j] represents the maximum coins obtained by bursting balloons from 'i' to 'j' (exclusive). We iterate through different balloon ranges and choose the best order to burst the balloons.

Time Complexity:
The time complexity is O(n^3), where 'n' is the number of balloons. We have three nested loops to fill the dp table.

Space Complexity:
The space complexity is O(n^2) as we use a 2D table 'dp' of size n x n to store the results of subproblems.
"""


class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        n = len(nums)

        # Add virtual balloons at the beginning and end with a value of 1.
        nums = [1] + nums + [1]

        # Create a 2D table dp to store the maximum coins.
        dp = [[0] * (n + 2) for _ in range(n + 2)]

        # Iterate through different balloon ranges.
        for length in range(2, n + 2):
            for left in range(0, n + 2 - length):
                right = left + length
                for k in range(left + 1, right):
                    # Choose the best order to burst balloons in the range [left, right].
                    dp[left][right] = max(
                        dp[left][right],
                        nums[left] * nums[k] * nums[right] + dp[left][k] + dp[k][right],
                    )

        return dp[0][n + 1]
