/*
Problem: LeetCode 33 - Search in Rotated Sorted Array

Key Idea:
The key idea is to use modified binary search. Compare the middle element with the left and right endpoints to determine if the left or right half is sorted. Adjust the search range accordingly until you find the target or exhaust the search space.

Approach:
1. Initialize two pointers, `left` and `right`, to the start and end of the array.
2. In each step of the binary search:
   a. Calculate the middle index as `mid` = (left + right) / 2.
   b. Check if `nums[mid]` is equal to the target. If true, return `mid` as the result.
   c. Determine if the left half or right half of the array is sorted by comparing `nums[left]` and `nums[mid]`.
      - If the left half is sorted:
        i. Check if the target falls within the range of `nums[left]` and `nums[mid]`. If true, update `right = mid - 1`.
        ii. Otherwise, update `left = mid + 1`.
      - If the right half is sorted:
        i. Check if the target falls within the range of `nums[mid]` and `nums[right]`. If true, update `left = mid + 1`.
        ii. Otherwise, update `right = mid - 1`.
3. If the target is not found after the binary search, return -1 to indicate that it's not in the array.

Time Complexity:
- The binary search takes O(log n) time, where n is the length of the input array.

Space Complexity:
- The space complexity is O(1) as we are using only a constant amount of extra space.
*/

impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut left = 0;
        let mut right = nums.len() - 1;

        while left <= right {
            let mid = left + (right - left) / 2;

            if nums[mid] == target {
                return mid as i32;
            }

            if nums[left] <= nums[mid] {
                if nums[left] <= target && target < nums[mid] {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if nums[mid] < target && target <= nums[right] {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        -1
    }
}
