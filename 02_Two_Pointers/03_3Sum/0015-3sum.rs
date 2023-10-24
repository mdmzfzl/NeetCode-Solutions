/*
Problem: LeetCode 15 - 3Sum

Key Idea:
The key idea is to use a combination of sorting the array and a two-pointer approach to find all unique triplets that sum up to zero.

Approach:
1. Sort the input array in ascending order.
2. Iterate through the array up to the second-to-last element:
   - Initialize two pointers, `left` and `right`, one pointing to the element after the current element and the other pointing to the end of the array.
   - While `left` is less than `right`:
     - Calculate the sum of the current element, `nums[left]`, and `nums[right]`.
     - If the sum is equal to zero, add the triplet `[nums[i], nums[left], nums[right]]` to the result.
     - If the sum is less than zero, increment `left`.
     - If the sum is greater than zero, decrement `right`.
     - Move both `left` and `right` until they are no longer pointing to duplicate elements.
3. Return the result containing all unique triplets.

Time Complexity:
O(n^2), where n is the number of elements in the input array. The sorting step takes O(n log n), and the two-pointer traversal takes O(n^2) in the worst case.

Space Complexity:
O(log n), as the sorting step requires additional space for the call stack due to the recursive nature of the sorting algorithm. The result array also contributes to the space complexity.
*/

impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = Vec::new();
        let n = nums.len();
        let mut nums = nums;

        nums.sort();

        for i in 0..n - 2 {
            if i > 0 && nums[i] == nums[i - 1] {
                continue; // Skip duplicate elements
            }

            let mut left = i + 1;
            let mut right = n - 1;

            while left < right {
                let sum = nums[i] + nums[left] + nums[right];

                if sum == 0 {
                    result.push(vec![nums[i], nums[left], nums[right]]);
                    while left < right && nums[left] == nums[left + 1] {
                        left += 1;
                    }
                    while left < right && nums[right] == nums[right - 1] {
                        right -= 1;
                    }
                    left += 1;
                    right -= 1;
                } else if sum < 0 {
                    left += 1;
                } else {
                    right -= 1;
                }
            }
        }

        result
    }
}
