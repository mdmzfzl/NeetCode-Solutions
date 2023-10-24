/*
Problem: LeetCode 763 - Partition Labels

Key Idea:
The key idea is to find the partitions of the given string such that each letter appears in only one partition.

Approach:
1. Initialize a HashMap to store the last occurrence index of each character in the string.
2. Iterate through the string to populate the HashMap with the last occurrence index of each character.
3. Initialize two variables 'start' and 'end' to keep track of the current partition's start and end.
4. Iterate through the string again:
   - For each character, update 'end' with the maximum of its current value and the last occurrence index of that character from the HashMap.
   - If the current index is equal to 'end', it means we have reached the end of the current partition.
   - Add the length of this partition (end - start + 1) to the result list.
   - Update 'start' to the next index.
5. Return the result list.

Time Complexity:
O(n), where n is the length of the input string. We perform two passes through the string.

Space Complexity:
O(1), as the HashMap has a constant number of characters (26 for lowercase English letters) and the result list is not counted towards space complexity.
*/

use std::collections::HashMap;

impl Solution {
    pub fn partition_labels(s: String) -> Vec<i32> {
        let mut last_occurrence: HashMap<char, usize> = HashMap::new();
        let mut result: Vec<i32> = Vec::new();

        // Populate the last_occurrence HashMap
        for (i, c) in s.chars().enumerate() {
            last_occurrence.insert(c, i);
        }

        let mut start = 0;
        let mut end = 0;

        // Iterate through the string to find partitions
        for (i, c) in s.chars().enumerate() {
            end = end.max(*last_occurrence.get(&c).unwrap());

            if i == end {
                result.push((end - start + 1) as i32);
                start = i + 1;
            }
        }

        result
    }
}
