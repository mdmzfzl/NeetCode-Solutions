/*
Problem: LeetCode 300 - Longest Increasing Subsequence

Key Idea:
The key idea is to use dynamic programming to find the length of the longest increasing subsequence in the given array.

Approach:
1. Initialize a vector `dp` of the same length as the input vector `nums`, all initially set to 1.
   - `dp[i]` will represent the length of the longest increasing subsequence ending at index `i`.
   - Initialize it to 1 because a single element is always a valid subsequence.
2. Iterate through the input vector `nums` from the second element to the end.
3. For each element `nums[i]`, iterate through the elements from the start to index `i - 1`:
   - For each element `nums[j]`, if `nums[i]` is greater than `nums[j]`, update `dp[i]` to the maximum of `dp[i]` and `dp[j] + 1`.
   - This means that if we can extend an increasing subsequence ending at index `j` with `nums[i]`, we update the length of the increasing subsequence ending at index `i`.
4. After the iteration, the maximum value in the `dp` vector will be the length of the longest increasing subsequence.
5. Return this maximum value as the result.

Time Complexity:
O(n^2), where `n` is the length of the input vector `nums`. We have nested loops for each element.

Space Complexity:
O(n), as we use a vector of size `n` to store the dynamic programming values.
*/

impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut dp = vec![1; n];

        for i in 1..n {
            for j in 0..i {
                if nums[i] > nums[j] {
                    dp[i] = dp[i].max(dp[j] + 1);
                }
            }
        }

        dp.iter().cloned().max().unwrap_or(0)
    }
}
