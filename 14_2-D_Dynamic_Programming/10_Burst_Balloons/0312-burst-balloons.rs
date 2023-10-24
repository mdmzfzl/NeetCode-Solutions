/*
Problem: LeetCode 312 - Burst Balloons

Key Idea:
The key idea is to use dynamic programming to find the maximum coins that can be obtained by bursting balloons in the given order.

Approach:
1. We can approach this problem using dynamic programming. We will create a 2D array `dp` where `dp[i][j]` represents the maximum coins obtained by bursting balloons from index `i` to `j` (inclusive).
2. We will iterate over different balloon ranges by varying the length of the range from 1 to `n`, where `n` is the number of balloons.
3. For each range, we will iterate over all possible starting points for the range.
4. Within each range, we will consider different options for the last balloon to burst. We will choose the last balloon such that it maximizes the total coins.
5. To calculate the coins for bursting the last balloon, we will use the formula:
   `coins[i][j] = max(coins[i][j], nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j])`
   where `k` is the index of the last balloon in the range `[i, j]`.
6. After iterating through all possible ranges and all possible last balloons to burst, `dp[0][n-1]` will contain the maximum coins that can be obtained.
7. Return `dp[0][n-1]` as the result.

Time Complexity:
O(n^3), where `n` is the number of balloons. We have three nested loops to calculate the `dp` array.

Space Complexity:
O(n^2), as we use a 2D array of size `n x n` to store the dynamic programming values.
*/

impl Solution {
    pub fn max_coins(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut dp = vec![vec![0; n]; n];

        for len in 1..=n {
            for i in 0..=n - len {
                let j = i + len - 1;
                for k in i..=j {
                    let left = if i == 0 { 1 } else { nums[i - 1] };
                    let right = if j == n - 1 { 1 } else { nums[j + 1] };
                    let burst = nums[k] * left * right;
                    let before = if k == i { 0 } else { dp[i][k - 1] };
                    let after = if k == j { 0 } else { dp[k + 1][j] };
                    dp[i][j] = dp[i][j].max(burst + before + after);
                }
            }
        }

        dp[0][n - 1]
    }
}
