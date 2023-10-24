"""
Problem: LeetCode 121 - Best Time to Buy and Sell Stock

Key Idea:
To find the maximum profit from a single buy and sell transaction in the input array 'prices', we can use a simple one-pass approach. We initialize two variables, 'min_price' to keep track of the minimum price seen so far, and 'max_profit' to store the maximum profit. We iterate through the 'prices' array, and for each price, we update the 'min_price' if we find a smaller price. We also calculate the potential profit if we sell at the current price and update 'max_profit' if the current profit is greater than the previous maximum profit.

Time Complexity:
The time complexity of this solution is O(n), where n is the number of elements in the input array 'prices'. We iterate through the array once to find the maximum profit, and at each step, we perform constant-time operations.

Space Complexity:
The space complexity is O(1) since we are not using any additional data structures that depend on the input size. We only use a constant amount of extra space for the variables to store the minimum price and maximum profit.
"""


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0

        min_price = float("inf")
        max_profit = 0

        for price in prices:
            min_price = min(min_price, price)
            max_profit = max(max_profit, price - min_price)

        return max_profit
