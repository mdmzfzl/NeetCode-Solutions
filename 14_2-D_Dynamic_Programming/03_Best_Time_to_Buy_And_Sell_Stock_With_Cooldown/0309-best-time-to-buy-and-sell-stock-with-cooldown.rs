/*
Problem: LeetCode 309 - Best Time to Buy and Sell Stock with Cooldown

Key Idea:
The key idea is to use dynamic programming to find the maximum profit that can be obtained by buying and selling a stock with a cooldown period.

Approach:
1. Initialize three vectors: `buy`, `sell`, and `cooldown`, all of size `n`, where `n` is the length of the input prices vector.
   - `buy[i]` represents the maximum profit that can be obtained by buying a stock on day `i`.
   - `sell[i]` represents the maximum profit that can be obtained by selling a stock on day `i`.
   - `cooldown[i]` represents the maximum profit on day `i` with a cooldown (no stock held).
2. Initialize `buy[0]` as the negative of the first price, indicating buying the stock on the first day.
   - Initialize `sell[0]` and `cooldown[0]` as 0 because there are no transactions yet.
3. Iterate through the prices vector from day 1 to `n-1`.
   - Update `buy[i]` as the maximum of `buy[i-1]` (not buying a stock on day `i`) and `cooldown[i-1] - prices[i]` (buying a stock on day `i` after a cooldown).
   - Update `sell[i]` as the maximum of `sell[i-1]` (not selling a stock on day `i`) and `buy[i-1] + prices[i]` (selling a stock on day `i`).
   - Update `cooldown[i]` as the maximum of `cooldown[i-1]` (no transaction on day `i`) and `sell[i-1]` (selling a stock on day `i-1` and having a cooldown on day `i`).
4. The maximum profit can be obtained by either holding no stock (`cooldown[n-1]`) or selling the stock on the last day (`sell[n-1]`).
5. Return the maximum of `cooldown[n-1]` and `sell[n-1]` as the result.

Time Complexity:
O(n), where `n` is the length of the input prices vector. We iterate through the prices vector once.

Space Complexity:
O(n), as we use three vectors of size `n` to store the dynamic programming values.
*/

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let n = prices.len();
        if n <= 1 {
            return 0;
        }

        let mut buy = vec![0; n];
        let mut sell = vec![0; n];
        let mut cooldown = vec![0; n];

        buy[0] = -prices[0];

        for i in 1..n {
            cooldown[i] = cooldown[i - 1].max(sell[i - 1]);
            buy[i] = buy[i - 1].max(cooldown[i - 1] - prices[i]);
            sell[i] = sell[i - 1].max(buy[i - 1] + prices[i]);
        }

        cooldown[n - 1].max(sell[n - 1])
    }
}
