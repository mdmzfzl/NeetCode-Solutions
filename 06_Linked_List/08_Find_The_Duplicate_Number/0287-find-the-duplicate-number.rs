/*
Problem: LeetCode 287 - Find the Duplicate Number

Key Idea:
The key idea is to treat the array as a linked list with a cycle and find the entrance point of the cycle using the Floyd's Tortoise and Hare algorithm.

Approach:
1. Initialize two pointers, `slow` and `fast`, to the first element of the array.
2. Move `slow` one step at a time and `fast` two steps at a time until they meet inside the cycle.
3. Once they meet, reset one of the pointers, say `slow`, to the first element and move both `slow` and `fast` one step at a time until they meet again.
4. The point where they meet is the entrance point of the cycle, which corresponds to the duplicate number.
5. Return the duplicate number.

Time Complexity:
O(n), where n is the length of the array. We perform two iterations through the array, each taking O(n) time.

Space Complexity:
O(1), as we use a constant amount of extra space for pointers and variables.
*/

impl Solution {
    pub fn find_duplicate(nums: Vec<i32>) -> i32 {
        let mut slow = nums[0];
        let mut fast = nums[0];

        // Phase 1: Detect cycle
        loop {
            slow = nums[slow as usize];
            fast = nums[nums[fast as usize] as usize];

            if slow == fast {
                break;
            }
        }

        // Phase 2: Find entrance to the cycle
        slow = nums[0];
        while slow != fast {
            slow = nums[slow as usize];
            fast = nums[fast as usize];
        }

        slow
    }
}
