/*
Problem: LeetCode 76 - Minimum Window Substring

Key Idea:
The key idea is to use a sliding window approach with two pointers. Maintain a window that covers a substring in the main string and contains all required characters. Move the right pointer to expand the window, and when all characters are included, move the left pointer to minimize the window size while still satisfying the conditions. Keep track of the minimum window size as you iterate through the string.

Approach:
1. Initialize two arrays, `target_freq` and `window_freq`, each of size 128 to represent the frequency of characters in the target string and the current window, respectively. Use ASCII values for indexing.
2. Convert the input strings to byte arrays to work with ASCII values.
3. Initialize variables `left` and `right` representing the start and end of the current window, and a variable `min_length` to track the minimum window length found so far.
4. Initialize a variable `required_chars` to track the count of characters needed to form the target substring.
5. Iterate through the `t` string and update the `target_freq` array with the frequency of each character.
6. Iterate through the `s` string using the `right` pointer:
   - Update the frequency of the character at position `right` in the `window_freq` array.
   - If the frequency of the character at position `right` in the `window_freq` array is less than or equal to the frequency in the `target_freq` array, increment `required_chars`.
   - If `required_chars` is equal to the length of the target string `t`, it means all required characters are found in the current window. Move the `left` pointer to the right to try to minimize the window size.
   - Update `min_length` with the minimum of its current value and the current window size.
7. Return the minimum window substring using the `left` pointer and `min_length`.

Time Complexity:
O(n), where n is the length of the `s` string. We perform a single pass through the `s` string using the sliding window approach.

Space Complexity:
O(1), as the arrays `target_freq` and `window_freq` are of constant size 128.
*/

impl Solution {
    pub fn min_window(s: String, t: String) -> String {
        let s = s.as_bytes();
        let t = t.as_bytes();
        let mut target_freq = [0; 128];
        let mut window_freq = [0; 128];
        let mut left = 0;
        let mut min_length = usize::MAX;
        let mut start_idx = 0;
        let mut required_chars = 0;

        for &ch in t {
            target_freq[ch as usize] += 1;
            required_chars += 1;
        }

        for (right, &ch) in s.iter().enumerate() {
            window_freq[ch as usize] += 1;
            if window_freq[ch as usize] <= target_freq[ch as usize] {
                required_chars -= 1;
            }

            while required_chars == 0 {
                if right - left + 1 < min_length {
                    min_length = right - left + 1;
                    start_idx = left;
                }

                window_freq[s[left] as usize] -= 1;
                if window_freq[s[left] as usize] < target_freq[s[left] as usize] {
                    required_chars += 1;
                }

                left += 1;
            }
        }

        if min_length == usize::MAX {
            "".to_string()
        } else {
            String::from_utf8(s[start_idx..start_idx + min_length].to_vec()).unwrap()
        }
    }
}
