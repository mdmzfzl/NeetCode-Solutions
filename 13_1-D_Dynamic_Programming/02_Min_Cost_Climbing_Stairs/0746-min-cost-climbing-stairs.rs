/*
Problem: LeetCode 746 - Min Cost Climbing Stairs

Key Idea:
The key idea is to use dynamic programming to find the minimum cost to reach each step.

Approach:
1. Initialize an array `dp` of size n+1 to store the minimum cost to reach each step, where n is the length of the `cost` array.
2. Initialize `dp[0]` and `dp[1]` to be 0, as there is no cost to reach the first two steps.
3. Iterate from step 2 to n:
   - Calculate `dp[i]` as the minimum of `dp[i-1] + cost[i-1]` and `dp[i-2] + cost[i-2]`. This represents the minimum cost to reach the i-th step.
4. Return `dp[n]`, which represents the minimum cost to reach the top floor.

Time Complexity:
O(n), where n is the length of the `cost` array. We perform a single pass through the steps.

Space Complexity:
O(n), as we use an array `dp` of size n+1 to store intermediate results.
*/

impl Solution {
    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        let n = cost.len();
        if n <= 2 {
            return cost.iter().min().unwrap_or(&0).to_owned();
        }

        let mut dp = vec![0; n + 1];

        for i in 2..=n {
            dp[i] = std::cmp::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        dp[n]
    }
}
