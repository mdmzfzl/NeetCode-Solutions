/*
Problem: LeetCode 5 - Longest Palindromic Substring

Key Idea:
The key idea is to use dynamic programming to find the longest palindromic substring.

Approach:
1. Initialize a 2D boolean array `dp` where `dp[i][j]` represents whether the substring from index `i` to `j` is a palindrome.
2. Initialize a variable `start` to keep track of the starting index of the longest palindromic substring found so far and `max_len` to keep track of its length.
3. Iterate through the string characters:
   - For each character at index `i`, iterate from `i` to the beginning of the string:
     - If `s[i]` is equal to `s[j]` and the substring between `i` and `j` is either empty or a palindrome (`i+1 > j-1` or `dp[i+1][j-1]` is true), set `dp[i][j]` to true.
     - If `dp[i][j]` is true and the length of the substring is greater than `max_len`, update `max_len` and `start` to the current values of `i` and `j`.
4. Return the longest palindromic substring by slicing the string from index `start` to `start + max_len`.

Time Complexity:
O(n^2), where n is the length of the input string `s`. We fill in the `dp` array for all possible substrings.

Space Complexity:
O(n^2), as we use a 2D array `dp` of size n x n.
*/

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let s_chars: Vec<char> = s.chars().collect();
        let n = s_chars.len();
        if n <= 1 {
            return s;
        }

        let mut dp = vec![vec![false; n]; n];
        let (mut start, mut max_len) = (0, 1);

        // All substrings of length 1 are palindromes.
        for i in 0..n {
            dp[i][i] = true;
        }

        // Check for palindromes of length 2.
        for i in 0..n - 1 {
            if s_chars[i] == s_chars[i + 1] {
                dp[i][i + 1] = true;
                start = i;
                max_len = 2;
            }
        }

        // Check for palindromes of length >= 3.
        for len in 3..=n {
            for i in 0..=n - len {
                let j = i + len - 1;

                if s_chars[i] == s_chars[j] && dp[i + 1][j - 1] {
                    dp[i][j] = true;

                    if len > max_len {
                        start = i;
                        max_len = len;
                    }
                }
            }
        }

        s_chars[start..start + max_len].iter().collect()
    }
}

/*
// Expanding around the center approach

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let bytes = s.as_bytes();
        let n = bytes.len();
        let (mut max_start, mut max_end) = (0, 0);

        for i in 0..n {
            let (mut left, mut right) = (i, i);

            // Expand the palindrome around the current character.
            while right + 1 < n && bytes[left] == bytes[right + 1] {
                right += 1;
            }

            // Expand the palindrome while possible.
            while left > 0 && right + 1 < n && bytes[left - 1] == bytes[right + 1] {
                left -= 1;
                right += 1;
            }

            // Check if the current palindrome is longer.
            if right - left > max_end - max_start {
                max_start = left;
                max_end = right;
            }
        }

        String::from(&s[max_start..=max_end])
    }
}
*/
