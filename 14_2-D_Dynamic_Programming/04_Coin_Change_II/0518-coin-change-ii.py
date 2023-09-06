"""
Problem: LeetCode 518 - Coin Change II

Key Idea:
The key idea is to use dynamic programming to count the number of combinations that make up each amount from 0 to 'amount'.

Time Complexity:
The time complexity is O(amount * n), where 'amount' is the target amount and 'n' is the number of coin denominations. We iterate through 'amount' values and for each amount, we iterate through 'n' coin denominations.

Space Complexity:
The space complexity is O(amount) because we use a 1D array 'dp' of size 'amount + 1' to store the number of combinations for each amount.
"""


class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        # Initialize a 1D array dp to store the number of combinations for each amount from 0 to amount.
        dp = [0] * (amount + 1)

        # There is one way to make amount 0 (by not using any coins).
        dp[0] = 1

        # Iterate through each coin denomination.
        for coin in coins:
            # Update the dp array for each amount from coin to amount.
            for i in range(coin, amount + 1):
                dp[i] += dp[i - coin]

        # The dp[amount] contains the number of combinations to make the target amount.
        return dp[amount]
