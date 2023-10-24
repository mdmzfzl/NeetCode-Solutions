/*
Problem: LeetCode 53 - Maximum Subarray

Key Idea:
The key idea is to use Kadane's algorithm to efficiently find the maximum sum of a subarray.

Approach:
1. Initialize two variables: 'max_sum' to store the maximum sum found so far and 'current_sum' to store the current sum.
2. Iterate through the array:
   - For each element, update 'current_sum' by taking the maximum of the current element and the sum of the current element and 'current_sum'.
   - Update 'max_sum' by taking the maximum of 'max_sum' and 'current_sum'.
   - This algorithm effectively keeps track of the maximum subarray sum ending at the current element.
   - By the end of the iteration, 'max_sum' will contain the maximum subarray sum.
3. Return 'max_sum' as the result.

Time Complexity:
O(n), where n is the number of elements in the array. We perform a single pass through the array.

Space Complexity:
O(1), as we only use a constant amount of extra space to store 'max_sum' and 'current_sum'.
*/

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut max_sum = nums[0];
        let mut current_sum = nums[0];

        for i in 1..nums.len() {
            current_sum = nums[i].max(nums[i] + current_sum);
            max_sum = max_sum.max(current_sum);
        }

        max_sum
    }
}
