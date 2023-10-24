/*
Problem: LeetCode 567 - Permutation in String

Key Idea:
The key idea is to use a sliding window approach with two frequency maps. Create a frequency map of characters in the pattern string, then slide a window of the same length over the main string and maintain a frequency map of characters within the window. Compare the two frequency maps at each step to check for a permutation.

Approach:
1. Initialize two arrays, `target_freq` and `window_freq`, each of size 26 to represent the frequency of characters in the target string and the current window, respectively.
2. Convert the input strings to byte arrays to work with ASCII values.
3. Initialize two pointers, `left` and `right`, representing the start and end of the current window.
4. Iterate through the `s2` string using the `right` pointer:
   - Update the frequency of the character at position `right` in the `window_freq` array.
   - If the window size is greater than or equal to the length of `s1`, decrement the frequency of the character at position `left` in the `window_freq` array and move the `left` pointer to the right.
   - If the frequencies of characters in `window_freq` match the frequencies in `target_freq`, it means a permutation of `s1` is found.
5. Return `true` if a permutation is found, otherwise return `false`.

Time Complexity:
O(n), where n is the length of the `s2` string. We perform a single pass through the `s2` string using the sliding window approach.

Space Complexity:
O(1), as the arrays `target_freq` and `window_freq` are of constant size 26.
*/

impl Solution {
    pub fn check_inclusion(s1: String, s2: String) -> bool {
        let s1 = s1.as_bytes();
        let s2 = s2.as_bytes();
        let mut target_freq = [0; 26];
        let mut window_freq = [0; 26];

        for i in 0..s1.len() {
            target_freq[(s1[i] - b'a') as usize] += 1;
            window_freq[(s2[i] - b'a') as usize] += 1;
        }

        let mut left = 0;

        for right in s1.len()..s2.len() {
            if window_freq == target_freq {
                return true;
            }

            window_freq[(s2[left] - b'a') as usize] -= 1;
            left += 1;
            window_freq[(s2[right] - b'a') as usize] += 1;
        }

        window_freq == target_freq
    }
}
