/*
Problem: LeetCode 424 - Longest Repeating Character Replacement

Key Idea:
The key idea is to use a sliding window approach and keep track of the frequency of characters within the window to find the longest substring with the same character, while allowing for replacements.

Approach:
1. Initialize variables `max_count` to track the maximum frequency of a character in the current window and `max_length` to track the maximum length of a valid substring.
2. Initialize a hashmap to store the frequency of characters within the window.
3. Initialize two pointers, `left` and `right`, representing the start and end of the current window.
4. Iterate through the string using the `right` pointer:
   - Update the frequency of the character at position `right` in the hashmap.
   - Update `max_count` with the maximum of its current value and the frequency of the character.
   - Calculate the current window size as `right - left + 1`.
   - If the current window size minus `max_count` is greater than `k`, it means there are more characters to replace than allowed. Move the `left` pointer to shrink the window.
   - Update `max_length` with the maximum of its current value and the current window size.
5. Return `max_length` as the result.

Time Complexity:
O(n), where n is the length of the input string. We perform a single pass through the string using the sliding window approach.

Space Complexity:
O(1), as the hashmap stores only a constant number of characters.
*/

impl Solution {
    pub fn character_replacement(s: String, k: i32) -> i32 {
        let s = s.as_bytes();
        let mut char_freq = [0; 26];
        let mut max_length = 0;
        let mut max_count = 0;
        let mut left = 0;

        for right in 0..s.len() {
            char_freq[(s[right] - b'A') as usize] += 1;
            max_count = max_count.max(char_freq[(s[right] - b'A') as usize]);

            if right - left + 1 - max_count > k as usize {
                char_freq[(s[left] - b'A') as usize] -= 1;
                left += 1;
            }

            max_length = max_length.max(right - left + 1);
        }

        max_length as i32
    }
}
