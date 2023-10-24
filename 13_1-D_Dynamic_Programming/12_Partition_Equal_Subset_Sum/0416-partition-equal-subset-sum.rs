/*
Problem: LeetCode 416 - Partition Equal Subset Sum

Key Idea:
The key idea is to use dynamic programming to determine if it's possible to partition the input array into two subsets with equal sums.

Approach:
1. Calculate the sum of all elements in the input array `nums` and store it in a variable `total_sum`.
2. If the total sum is odd, it's impossible to partition the array into two subsets with equal sums. Return `false` in this case.
3. Otherwise, initialize a boolean vector `dp` of size `total_sum / 2 + 1`, where `dp[i]` represents whether it's possible to form a subset with a sum of `i`.
   - Initialize `dp[0]` to `true` because an empty subset has a sum of 0.
4. Iterate through the elements of the input array `nums`:
   - For each element `num`, iterate through the `dp` vector in reverse order from `total_sum / 2` down to `num`.
   - Update `dp[i]` to `true` if either `dp[i]` is already `true` or `dp[i - num]` is `true`. This means we can form a subset with a sum of `i` by either not including the current `num` or including it.
5. After the iteration, if `dp[total_sum / 2]` is `true`, it's possible to partition the array into two subsets with equal sums; otherwise, it's not possible.
6. Return `dp[total_sum / 2]` as the result.

Time Complexity:
O(n * sum), where `n` is the number of elements in the input array `nums`, and `sum` is the sum of all elements in the array. We fill in the `dp` table with a nested loop.

Space Complexity:
O(sum / 2), as we use a boolean vector of size `total_sum / 2 + 1` to store the dynamic programming values.
*/

impl Solution {
    pub fn can_partition(nums: Vec<i32>) -> bool {
        let total_sum: i32 = nums.iter().sum();

        if total_sum % 2 != 0 {
            return false;
        }

        let target_sum = (total_sum / 2) as usize;
        let mut dp = vec![false; target_sum + 1];
        dp[0] = true;

        for &num in nums.iter() {
            for i in (num as usize..=target_sum).rev() {
                dp[i] = dp[i] || dp[i - num as usize];
            }
        }

        dp[target_sum]
    }
}
