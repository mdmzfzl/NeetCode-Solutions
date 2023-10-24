/*
Problem: LeetCode 704 - Binary Search

Key Idea:
The key idea is to use binary search. Compare the target with the middle element of the array and eliminate half of the search space based on this comparison. Repeat this process until the target is found or the search space is empty.

Approach:
1. Initialize two pointers, `left` and `right`, representing the leftmost and rightmost indices of the search interval.
2. While `left <= right`, perform binary search:
   a. Calculate the middle index as `mid = left + (right - left) / 2`.
   b. If the element at the `mid` index is equal to the target, return `mid`.
   c. If the element at the `mid` index is less than the target, update `left` to `mid + 1` (search in the right half).
   d. If the element at the `mid` index is greater than the target, update `right` to `mid - 1` (search in the left half).
3. If the target is not found in the array, return -1 to indicate that it doesn't exist in the array.

Time Complexity:
The time complexity of binary search is O(log N) since the search interval is halved in each step.

Space Complexity:
The space complexity is O(1) as we are using a constant amount of extra space.
*/

impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut left = 0;
        let mut right = nums.len() as i32 - 1;

        while left <= right {
            let mid = left + (right - left) / 2;

            if nums[mid as usize] == target {
                return mid;
            } else if nums[mid as usize] < target {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        -1 // Target not found
    }
}
