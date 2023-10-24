/*
Problem: LeetCode 153 - Find Minimum in Rotated Sorted Array

Key Idea:
The key idea is to use binary search. Compare the middle element with the rightmost element to determine whether the minimum element is in the left or right half. Adjust the search range accordingly until you find the minimum element.

Approach:
1. Use binary search to find the minimum element.
2. Initialize two pointers, `left` and `right`, to the start and end of the array, respectively.
3. While `left` is less than `right`:
   a. Calculate the middle index as `mid` = (left + right) / 2.
   b. Check if the element at `mid` is greater than the element at `right`.
      - If true, this means the minimum element is in the right half, so update `left` = `mid + 1`.
      - If false, the minimum element is in the left half, so update `right` = `mid`.
4. After the binary search, `left` will point to the minimum element, and we return the element at `left`.

Time Complexity:
- Binary search takes O(log n) time.

Space Complexity:
- The space complexity is O(1) as we use only a constant amount of extra space.
*/

impl Solution {
    pub fn find_min(nums: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut right = nums.len() - 1;

        while left < right {
            let mid = left + (right - left) / 2;

            if nums[mid] > nums[right] {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        nums[left]
    }
}
