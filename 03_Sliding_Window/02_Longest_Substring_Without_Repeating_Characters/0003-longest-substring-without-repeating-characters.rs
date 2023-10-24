/*
Problem: LeetCode 3 - Longest Substring Without Repeating Characters

Key Idea:
The key idea is to use a sliding window approach with two pointers. Maintain a window (substring) using two pointers, and a set to track characters within the current window. Move the right pointer to expand the window and add characters to the set, while checking for repeats. If a repeat is found, move the left pointer to shrink the window and remove characters from the set. Keep updating the maximum length as you iterate through the string.

Approach:
1. Initialize two pointers, `left` and `right`, representing the start and end of the current window.
2. Initialize a hashmap to store the last seen index of each character.
3. Initialize a variable `max_length` to track the maximum length of the substring.
4. Iterate through the string using the `right` pointer:
   - If the character at `right` is already in the hashmap and its index is greater than or equal to `left`, update `left` to the next position after the last occurrence of the character.
   - Calculate the current length of the substring as `right - left + 1`.
   - Update `max_length` with the maximum of its current value and the current length.
   - Update the index of the character in the hashmap.
5. Return `max_length` as the result.

Time Complexity:
O(n), where n is the length of the input string. We perform a single pass through the string using the sliding window approach.

Space Complexity:
O(min(n, m)), where n is the length of the input string and m is the size of the character set. In the worst case, the hashmap can store all characters in the string.
*/

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut char_indices = std::collections::HashMap::new();
        let mut max_length = 0;
        let mut left = 0;

        for (right, ch) in s.chars().enumerate() {
            if let Some(&prev_index) = char_indices.get(&ch) {
                left = left.max(prev_index + 1);
            }

            max_length = max_length.max(right - left + 1);
            char_indices.insert(ch, right);
        }

        max_length as i32
    }
}
