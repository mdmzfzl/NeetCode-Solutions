/*
Problem: LeetCode 322 - Coin Change

Key Idea:
The key idea is to use dynamic programming to find the minimum number of coins required to make a certain amount of money.

Approach:
1. Initialize a vector `dp` of size `amount + 1` to store the minimum number of coins required to make each amount from 0 to `amount`.
   - `dp[i]` will represent the minimum number of coins required to make the amount `i`.
2. Set `dp[0]` to 0, as it takes 0 coins to make an amount of 0.
3. Iterate through the amounts from 1 to `amount`:
   - For each amount `i`, initialize `dp[i]` to a value greater than `amount` (e.g., `amount + 1`) to represent an impossible scenario initially.
   - For each coin value `coin` in the list of coins, check if `i - coin` is a valid amount (not negative) and if `dp[i - coin] + 1` is smaller than the current `dp[i]`. If so, update `dp[i]` to `dp[i - coin] + 1`.
4. After the iteration, `dp[amount]` will contain the minimum number of coins required to make the given amount.
5. If `dp[amount]` is still greater than `amount` (the amount is not possible to make), return -1; otherwise, return `dp[amount]` as the result.

Time Complexity:
O(amount * n), where `amount` is the target amount and `n` is the number of coins. We fill in the `dp` table with a nested loop.

Space Complexity:
O(amount), as we use a vector of size `amount + 1` to store the dynamic programming values.
*/

impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        let amount = amount as usize;
        let mut dp = vec![amount + 1; amount + 1];
        dp[0] = 0;

        for i in 1..=amount {
            for &coin in &coins {
                if i >= coin as usize && dp[i - coin as usize] + 1 < dp[i] {
                    dp[i] = dp[i - coin as usize] + 1;
                }
            }
        }

        if dp[amount] > amount {
            -1
        } else {
            dp[amount] as i32
        }
    }
}
