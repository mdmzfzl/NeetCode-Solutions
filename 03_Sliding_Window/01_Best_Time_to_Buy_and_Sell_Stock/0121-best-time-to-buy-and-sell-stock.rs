/*
Problem: LeetCode 121 - Best Time to Buy and Sell Stock

Key Idea:
The key idea is to iterate through the prices while keeping track of the minimum price seen so far. Calculate the potential profit at each step by subtracting the minimum price from the current price, and update the maximum profit if a higher profit is found.

Approach:
1. Initialize variables `min_price` to represent the minimum price encountered so far and `max_profit` to represent the maximum profit.
2. Iterate through the prices:
   - For each price `p`, update `min_price` if `p` is smaller.
   - Calculate the potential profit by subtracting `min_price` from `p`.
   - Update `max_profit` with the maximum of its current value and the potential profit.
3. Return `max_profit` as the result.

Time Complexity:
O(n), where n is the number of elements in the input array. We perform a single pass through the array to find the maximum profit.

Space Complexity:
O(1), as we use only a constant amount of extra space for variables.
*/

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut min_price = i32::max_value();
        let mut max_profit = 0;

        for price in prices {
            min_price = min_price.min(price);
            max_profit = max_profit.max(price - min_price);
        }

        max_profit
    }
}
