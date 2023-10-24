/*
Problem: LeetCode 45 - Jump Game II

Key Idea:
The key idea is to use a greedy approach to find the minimum number of jumps required to reach the end of the array.

Approach:
1. Initialize two variables: 'max_reach' to store the maximum index that can be reached with the current number of jumps and 'end' to store the index of the last element.
2. Initialize a variable 'jumps' to store the number of jumps needed to reach the current 'max_reach'.
3. Iterate through the array:
   - For each element, update 'max_reach' by taking the maximum of its current value and the sum of its value and the current index.
   - If the current index reaches the 'end', it means we have reached the end of the current jump.
   - In this case, update 'end' to 'max_reach' and increment 'jumps'.
4. Return 'jumps' as the result.

Time Complexity:
O(n), where n is the number of elements in the array. We perform a single pass through the array.

Space Complexity:
O(1), as we only use a constant amount of extra space to store variables.
*/

impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {
        let mut max_reach = 0;
        let mut end = 0;
        let mut jumps = 0;

        for i in 0..nums.len() - 1 {
            max_reach = max_reach.max(i + nums[i] as usize);

            if i == end {
                end = max_reach;
                jumps += 1;
            }
        }

        jumps
    }
}
