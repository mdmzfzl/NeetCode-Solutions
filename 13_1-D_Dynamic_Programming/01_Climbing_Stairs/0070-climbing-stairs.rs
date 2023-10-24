/*
Problem: LeetCode 70 - Climbing Stairs

Key Idea:
The key idea is to realize that to reach the i-th step, you can either:
1. Take one step from the (i-1)-th step if you had already climbed (i-1) steps.
2. Take two steps from the (i-2)-th step if you had already climbed (i-2) steps.

Approach:
1. Initialize two variables, `prev` and `curr`, to represent the number of ways to reach the (i-1)-th and i-th step, respectively.
2. Start iterating from step 3 to n (inclusive), where n is the total number of steps:
   - Calculate the number of ways to reach the i-th step as `curr = prev + curr`, where `prev` represents the number of ways to reach the (i-1)-th step, and `curr` represents the number of ways to reach the i-th step.
   - Update `prev` to the previous value of `curr`.
3. Return the value of `curr` as the number of ways to reach the n-th step.

Time Complexity:
O(n), where n is the total number of steps. We perform a single pass through the steps.

Space Complexity:
O(1), as we use only two variables (`prev` and `curr`) to store intermediate results.
*/

impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if n <= 2 {
            return n;
        }

        let (mut prev, mut curr) = (1, 2);

        for _ in 3..=n {
            let temp = curr;
            curr = prev + curr;
            prev = temp;
        }

        curr
    }
}
