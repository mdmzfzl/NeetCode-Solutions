"""
Problem: LeetCode 746 - Min Cost Climbing Stairs

Key Idea:
To find the minimum cost to reach the top of the stairs, we can use dynamic programming. We start by creating a list dp where dp[i] represents the minimum cost to reach the i-th stair. We initialize dp[0] and dp[1] to the costs of the 0-th and 1-st stairs, as there's no cost to reach them.

Then, we iterate from the 2-nd stair to the top, and for each stair i, we calculate dp[i] as the minimum of either reaching it from dp[i-1] (one step) or dp[i-2] (two steps), plus the cost of the current stair.

The minimum cost to reach the top will be either dp[n-1] or dp[n-2], where n is the number of stairs, as we can reach the top by either taking one step from the last stair or two steps from the second-to-last stair.

Time Complexity:
The time complexity is O(n) because we iterate through the stairs once.

Space Complexity:
The space complexity is O(n) because we use a list dp to store the minimum costs for each stair.
"""


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        if n <= 1:
            return 0  # No cost if there are 0 or 1 stairs

        dp = [0] * n  # Initialize a list to store minimum costs

        # Base cases
        dp[0] = cost[0]
        dp[1] = cost[1]

        for i in range(2, n):
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]

        return min(dp[n - 1], dp[n - 2])
