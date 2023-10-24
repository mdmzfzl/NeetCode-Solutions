/*
Problem: LeetCode 494 - Target Sum

Key Idea:
The key idea is to use dynamic programming to count the number of ways to achieve a target sum using the given positive and negative numbers.

Approach:
1. Initialize a variable `sum` to store the sum of all elements in the input array `nums`.
2. Calculate the target sum `target` as the difference between the `sum` and the given `S`.
3. Check if `target` is odd or negative. If it is, there are no ways to achieve the target sum, so return 0.
4. Initialize a vector `dp` of size `2 * target + 1` to store the number of ways to achieve each possible sum from `-target` to `target`.
5. Initialize `dp[0]` as 1 because there is one way to achieve a sum of 0 (by not choosing any number).
6. Iterate through the elements of `nums`:
   - For each element `num`, iterate through the `dp` vector from `target` down to `num` (inclusive).
   - For each index `i`, update `dp[i]` by adding `dp[i - num]`. This represents the number of ways to achieve the sum `i` by including the current element.
7. After the iteration, `dp[target]` will contain the number of ways to achieve the target sum.
8. Return `dp[target]` as the result.

Time Complexity:
O(n * target), where `n` is the number of elements in the input array `nums` and `target` is the target sum. We fill in the `dp` table with a nested loop.

Space Complexity:
O(target), as we use a vector of size `2 * target + 1` to store the dynamic programming values.
*/

impl Solution {
    pub fn find_target_sum_ways(nums: Vec<i32>, s: i32) -> i32 {
        let sum: i32 = nums.iter().sum();
        let target = sum - s;

        if target < 0 || target % 2 != 0 {
            return 0;
        }

        let target = (target / 2) as usize;
        let mut dp = vec![0; target + 1];
        dp[0] = 1;

        for num in nums {
            for i in (num as usize..=target).rev() {
                dp[i] += dp[i - num as usize];
            }
        }

        dp[target]
    }
}
