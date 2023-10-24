/*
Problem: LeetCode 167 - Two Sum II - Input array is sorted

Key Idea:
The key idea is to use a two-pointer approach to find the two numbers that add up to the target sum.

Approach:
1. Initialize two pointers, `left` at the start of the array and `right` at the end.
2. While `left` is less than `right`:
   - Calculate the sum of the elements at `nums[left]` and `nums[right]`.
   - If the sum is equal to the target, return a vector containing `left + 1` and `right + 1` (1-based indices).
   - If the sum is less than the target, increment `left`.
   - If the sum is greater than the target, decrement `right`.
3. If no solution is found, return an empty vector.

Time Complexity:
O(n), where n is the number of elements in the input array. We perform a single pass through the array using the two-pointer approach.

Space Complexity:
O(1), as we use only a constant amount of extra space for pointers and variables.
*/

impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        let mut left = 0;
        let mut right = numbers.len() - 1;

        while left < right {
            let sum = numbers[left] + numbers[right];

            if sum == target {
                return vec![(left + 1) as i32, (right + 1) as i32];
            } else if sum < target {
                left += 1;
            } else {
                right -= 1;
            }
        }

        vec![]
    }
}
