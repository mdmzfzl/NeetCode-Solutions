/*
Problem: LeetCode 55 - Jump Game

Key Idea:
The key idea is to determine if it's possible to reach the last index of the array by jumping from one element to another.

Approach:
1. Initialize a variable 'max_reach' to store the maximum index that can be reached from the current position.
2. Iterate through the array:
   - For each element, update 'max_reach' by taking the maximum of its current value and the sum of its value and the current index.
   - If 'max_reach' is greater than or equal to the last index, it means it's possible to reach the end of the array.
   - Keep updating 'max_reach' as long as it's greater than the current index.
3. If 'max_reach' is greater than or equal to the last index after the iteration, return true; otherwise, return false.

Time Complexity:
O(n), where n is the number of elements in the array. We perform a single pass through the array.

Space Complexity:
O(1), as we only use a constant amount of extra space to store 'max_reach'.
*/

impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let mut max_reach = 0;

        for i in 0..nums.len() {
            if max_reach < i {
                return false; // Cannot reach the current index
            }

            max_reach = max_reach.max(i + nums[i] as usize);

            if max_reach >= nums.len() - 1 {
                return true; // Can reach or surpass the last index
            }
        }

        false
    }
}
