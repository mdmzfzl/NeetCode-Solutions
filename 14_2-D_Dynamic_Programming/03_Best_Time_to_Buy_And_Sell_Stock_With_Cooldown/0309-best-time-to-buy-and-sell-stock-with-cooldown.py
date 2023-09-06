"""
Problem: LeetCode 309 -Best Time to Buy and Sell Stock with Cooldown

Key Idea:
The key idea is to use dynamic programming to keep track of the maximum profit we can obtain at each day 'i', considering the actions we can take: buy, sell, or do nothing (cooldown).

Time Complexity:
The time complexity is O(n), where 'n' is the length of the input prices list. We iterate through the prices list once to compute the maximum profit at each day.

Space Complexity:
The space complexity is O(1) because we use only a constant amount of extra space to store variables for tracking the maximum profit at each day.
"""


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0

        # Initialize variables to represent the maximum profit after each action.
        buy = -prices[
            0
        ]  # Maximum profit after buying on day 0 (negative because we spend money).
        sell = 0  # Maximum profit after selling on day 0 (no profit yet).
        cooldown = 0  # Maximum profit after cooldown on day 0 (no profit yet).

        for i in range(1, len(prices)):
            # To maximize profit on day 'i', we can either:

            # 1. Buy on day 'i'. We subtract the price of the stock from the maximum profit after cooldown on day 'i-2'.
            new_buy = max(buy, cooldown - prices[i])

            # 2. Sell on day 'i'. We add the price of the stock to the maximum profit after buying on day 'i-1'.
            new_sell = buy + prices[i]

            # 3. Do nothing (cooldown) on day 'i'. We take the maximum of the maximum profit after cooldown on day 'i-1' and after selling on day 'i-1'.
            new_cooldown = max(cooldown, sell)

            # Update the variables for the next iteration.
            buy, sell, cooldown = new_buy, new_sell, new_cooldown

        # The maximum profit will be the maximum of the profit after selling on the last day and the profit after cooldown on the last day.
        return max(sell, cooldown)
