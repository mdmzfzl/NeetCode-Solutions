/*
Problem: LeetCode 217 - Contains Duplicate

Key Idea:
The key idea is to use a hashmap to keep track of the numbers we have seen so far. If we encounter a number that is already in the hashmap, we know there is a duplicate.

Approach:
1. Create an empty hashmap to store the numbers and their occurrences.
2. Iterate through the input array:
   - For each number `num`, check if it exists in the hashmap. If yes, return `true` as a duplicate is found.
   - Otherwise, insert `num` into the hashmap.
3. If no duplicate is found during the iteration, return `false`.

Time Complexity:
O(n), where n is the number of elements in the input array. We iterate through the array once and each hashmap lookup takes O(1) time on average.

Space Complexity:
O(n), as the worst case is when all elements in the array are distinct and we store all of them in the hashmap.
*/

use std::collections::HashSet;

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut seen_nums = HashSet::new();
        
        for num in nums {
            if seen_nums.contains(&num) {
                return true;
            }
            seen_nums.insert(num);
        }
        
        false
    }
}
