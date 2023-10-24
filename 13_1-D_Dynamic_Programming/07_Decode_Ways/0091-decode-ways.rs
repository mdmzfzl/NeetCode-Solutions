/*
Problem: LeetCode 91 - Decode Ways

Key Idea:
The key idea is to use dynamic programming to count the number of ways to decode a given string.

Approach:
1. Initialize a vector `dp` of size n+1, where n is the length of the input string.
   - `dp[i]` will represent the number of ways to decode the substring from index i to n-1.
2. Set `dp[n]` to 1, as there is one way to decode an empty string.
3. Iterate through the characters of the input string in reverse order:
   - For each character at index `i`, calculate the number of ways to decode the substring starting from index `i`:
     - If the current character is '0', set `dp[i]` to 0 because '0' cannot be decoded as a single character.
     - Otherwise, set `dp[i]` to `dp[i+1]` because the current character can be decoded as a single character.
     - If the current character and the next character form a valid two-digit number (between '10' and '26'), add `dp[i+2]` to `dp[i]` because the two characters can be decoded as a single unit.
4. Finally, `dp[0]` will contain the number of ways to decode the entire string.
5. Return `dp[0]` as the result.

Time Complexity:
O(n), where n is the length of the input string. We perform a single pass through the string.

Space Complexity:
O(n), as we use a vector of size n+1 to store the dynamic programming values.
*/

impl Solution {
    pub fn num_decodings(s: String) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        let mut dp = vec![0; n + 1];
        dp[n] = 1;

        for i in (0..n).rev() {
            if s[i] == b'0' {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1];
                if i + 1 < n && (s[i] == b'1' || (s[i] == b'2' && s[i + 1] <= b'6')) {
                    dp[i] += dp[i + 2];
                }
            }
        }

        dp[0]
    }
}
