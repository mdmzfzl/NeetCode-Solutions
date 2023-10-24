/*
Problem: LeetCode 128 - Longest Consecutive Sequence

Key Idea:
The key idea is to use a hash set to efficiently keep track of the consecutive sequence lengths starting from each number.

Approach:
1. Create a hash set to store the numbers from the input array.
2. Initialize a variable `longest_streak` to track the maximum consecutive sequence length found so far.
3. Iterate through the numbers in the input array:
   - For each number `num`, check if `num - 1` exists in the hash set. If not, it's a potential starting point of a consecutive sequence.
   - While `num + 1` exists in the hash set, increment `num` to extend the sequence.
   - Update `longest_streak` with the maximum of its current value and the length of the current sequence.
4. Return `longest_streak` as the result.

Time Complexity:
O(n), where n is the number of elements in the input array. We iterate through the array once and perform O(1) operations on average for each number.

Space Complexity:
O(n), as the hash set can contain all the elements from the input array.
*/

use std::collections::HashSet;

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        let num_set: HashSet<i32> = nums.iter().cloned().collect();
        let mut longest_streak: i32 = 0;

        for num in num_set.iter() {
            if !num_set.contains(&(num - 1)) {
                let mut streak = 1;
                let mut current = *num;

                while (num_set.contains(&(current + 1))) {
                    current += 1;
                    streak += 1;
                }

                longest_streak = std::cmp::max(streak, longest_streak);
            }
        }

        longest_streak
    }
}
