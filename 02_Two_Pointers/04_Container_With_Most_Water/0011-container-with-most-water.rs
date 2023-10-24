/*
Problem: LeetCode 11 - Container With Most Water

Key Idea:
The key idea is to use a two-pointer approach to find the container with the most water. The water height of the container is determined by the shorter of the two container walls, and the width is determined by the distance between the two walls.

Approach:
1. Initialize two pointers, `left` at the start of the array and `right` at the end of the array.
2. Initialize a variable `max_area` to track the maximum area found so far.
3. While `left` is less than `right`:
   - Calculate the current container's area using the formula: `area = min(height[left], height[right]) * (right - left)`.
   - Update `max_area` with the maximum of its current value and the current area.
   - Move the pointer pointing to the shorter wall (either `left` or `right`) inward.
4. Return `max_area` as the result.

Time Complexity:
O(n), where n is the number of elements in the input array. We perform a single pass through the array using the two-pointer approach.

Space Complexity:
O(1), as we use only a constant amount of extra space for pointers and variables.
*/

impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut max_area = 0;
        let mut left = 0;
        let mut right = height.len() - 1;

        while left < right {
            let current_area = std::cmp::min(height[left], height[right]) * (right - left) as i32;
            max_area = std::cmp::max(max_area, current_area);

            if height[left] < height[right] {
                left += 1;
            } else {
                right -= 1;
            }
        }

        max_area
    }
}
