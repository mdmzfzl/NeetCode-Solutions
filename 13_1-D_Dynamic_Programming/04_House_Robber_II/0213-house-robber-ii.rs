/*
Problem: LeetCode 213 - House Robber II

Key Idea:
The key idea is to break the problem into two cases:
1. Rob the first house and don't rob the last house.
2. Don't rob the first house and rob the last house.

Approach:
1. If the input `nums` is empty or has only one house, return the maximum value in `nums`.
2. Create a helper function `rob_range(nums: &[i32])` to calculate the maximum amount that can be robbed within a given range.
   - Initialize two variables, `prev` and `curr`, to keep track of the maximum amounts for the previous house and the current house, respectively.
   - Iterate through the houses in the given range and calculate the maximum amount for the current house as `max(prev, curr)`.
   - Update `prev` and `curr` accordingly.
   - Return `curr` as the maximum amount that can be robbed within the given range.
3. Calculate the maximum amount for the two cases:
   - Case 1: Rob the first house and don't rob the last house. Calculate this as `rob_range(&nums[1..])`, including all houses except the last one.
   - Case 2: Don't rob the first house and rob the last house. Calculate this as `rob_range(&nums[..nums.len() - 1])`, including all houses except the first one.
4. Return the maximum value between the two cases as the final result.

Time Complexity:
O(n), where n is the number of houses. We perform two passes through the `nums` array.

Space Complexity:
O(1), as we use a constant amount of extra space to store `prev` and `curr`.
*/

impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let n = nums.len();

        if n == 0 {
            return 0;
        } else if n == 1 {
            return nums[0];
        }

        let max_case1 = Self::rob_range(&nums[1..]);
        let max_case2 = Self::rob_range(&nums[..n - 1]);

        max_case1.max(max_case2)
    }

    fn rob_range(nums: &[i32]) -> i32 {
        let (mut prev, mut curr) = (0, 0);

        for &num in nums {
            let temp = curr;
            curr = curr.max(prev + num);
            prev = temp;
        }

        curr
    }
}
