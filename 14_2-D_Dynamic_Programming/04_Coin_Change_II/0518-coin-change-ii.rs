/*
Problem: LeetCode 518 - Coin Change II

Key Idea:
The key idea is to use dynamic programming to find the number of combinations to make a certain amount of money using a given set of coin denominations.

Approach:
1. Initialize a vector `dp` of size `amount + 1`, where `dp[i]` represents the number of combinations to make amount `i`.
2. Initialize `dp[0]` to 1 because there is one way to make amount 0 (by using no coins).
3. Iterate through the coin denominations:
   - For each coin denomination `coin`, iterate through the `dp` vector from `coin` to `amount`.
   - For each index `i`, update `dp[i]` by adding `dp[i - coin]`. This represents the number of combinations to make amount `i` by including the current coin denomination.
4. After the iteration, `dp[amount]` will contain the number of combinations to make the given amount using the given coins.
5. Return `dp[amount]` as the result.

Time Complexity:
O(amount * n), where `amount` is the target amount and `n` is the number of coin denominations. We fill in the `dp` table with a nested loop.

Space Complexity:
O(amount), as we use a vector of size `amount + 1` to store the dynamic programming values.
*/

impl Solution {
    pub fn change(amount: i32, coins: Vec<i32>) -> i32 {
        let amount = amount as usize;
        let mut dp = vec![0; amount + 1];
        dp[0] = 1;

        for coin in coins.iter() {
            for i in *coin as usize..=amount {
                dp[i] += dp[i - *coin as usize];
            }
        }

        dp[amount]
    }
}
