/*
Problem: LeetCode 198 - House Robber

Key Idea:
The key idea is to use dynamic programming to find the maximum amount of money that can be robbed without alerting the police.

Approach:
1. Initialize two variables, `prev` and `curr`, to represent the maximum amount of money that can be robbed from the previous two houses and the current house, respectively.
2. Start iterating from the first house to the last house:
   - Calculate the maximum amount that can be robbed from the current house as `max(prev + current_house_value, curr)`.
   - Update `prev` and `curr` accordingly.
3. Return `curr` as the maximum amount of money that can be robbed without alerting the police.

Time Complexity:
O(n), where n is the number of houses. We perform a single pass through the houses.

Space Complexity:
O(1), as we use only two variables (`prev` and `curr`) to store intermediate results.
*/

impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let (mut prev, mut curr) = (0, 0);

        for &num in nums.iter() {
            let temp = curr;
            curr = curr.max(prev + num);
            prev = temp;
        }

        curr
    }
}
