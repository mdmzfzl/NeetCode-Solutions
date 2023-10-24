/*
Problem: LeetCode 239 - Sliding Window Maximum

Key Idea:
The key idea is to use a double-ended queue (deque) to store indices of array elements. As you slide the window, maintain the deque to ensure it only contains relevant indices for the current window. This helps in efficiently finding the maximum value within each window by comparing array elements with the front of the deque.

Approach:
1. Initialize an empty double-ended queue `deque` to store indices of elements.
2. Iterate through the input array using the `i` pointer:
   - While the `deque` is not empty and the front element of the `deque` is out of the current window (i.e., its index is less than or equal to `i - k`), remove it from the front of the `deque`.
   - While the `deque` is not empty and the element at the back of the `deque` is less than the current element, remove it from the back of the `deque`.
   - Push the index of the current element to the back of the `deque`.
   - If the current index is greater than or equal to `k - 1`, it means the first sliding window is complete. Add the front element of the `deque` (the maximum element) to the result array.
3. Return the result array.

Time Complexity:
O(n), where n is the number of elements in the input array. We perform a single pass through the array using the sliding window approach.

Space Complexity:
O(k), where k is the size of the sliding window. The deque can store at most `k` elements.
*/

use std::collections::VecDeque;

impl Solution {
    pub fn max_sliding_window(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let k = k as usize;
        let mut result = Vec::new();
        let mut deque = VecDeque::new();

        for i in 0..nums.len() {
            while !deque.is_empty() && deque.front().unwrap() <= &(i as i32 - k as i32) {
                deque.pop_front();
            }

            while !deque.is_empty() && nums[*deque.back().unwrap() as usize] < nums[i] {
                deque.pop_back();
            }

            deque.push_back(i as i32);

            if i >= k - 1 {
                result.push(nums[*deque.front().unwrap() as usize]);
            }
        }

        result
    }
}
