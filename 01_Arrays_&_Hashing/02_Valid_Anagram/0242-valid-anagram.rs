/*
Problem: LeetCode 242 - Valid Anagram

Key Idea:
The key idea is to compare the frequencies of characters in two strings. An anagram will have the same frequency of characters.

Approach:
1. Create two arrays, `freq_s` and `freq_t`, of size 26 to represent the frequencies of characters in the input strings `s` and `t`.
2. Iterate through the characters of `s` and `t`:
   - Increment the corresponding frequency in `freq_s` for characters in `s`.
   - Decrement the corresponding frequency in `freq_t` for characters in `t`.
3. After the iteration, if `freq_s` and `freq_t` are equal, then `s` and `t` are valid anagrams.

Time Complexity:
O(n), where n is the length of the input strings `s` and `t`. We iterate through the strings once.

Space Complexity:
O(1), as the arrays `freq_s` and `freq_t` have constant size (26) regardless of the input size.
*/

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }

        let mut freq_s = [0; 26];
        let mut freq_t = [0; 26];

        for ch in s.chars() {
            freq_s[(ch as u8 - b'a') as usize] += 1;
        }

        for ch in t.chars() {
            freq_t[(ch as u8 - b'a') as usize] += 1;
        }

        freq_s == freq_t
    }
}
