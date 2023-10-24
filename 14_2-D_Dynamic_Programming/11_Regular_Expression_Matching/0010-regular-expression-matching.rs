/*
Problem: LeetCode 10 - Regular Expression Matching

Key Idea:
The key idea is to use dynamic programming to determine if a given string matches a regular expression pattern.

Approach:
1. We can approach this problem using dynamic programming. We will create a 2D array `dp` where `dp[i][j]` represents whether the first `i` characters of the string match the first `j` characters of the pattern.
2. Initialize `dp[0][0]` to true, as an empty string matches an empty pattern.
3. Iterate through the pattern characters using a nested loop:
   - If the current pattern character is not a wildcard '*', set `dp[0][j]` to false for all `j > 0` because no non-empty string can match an empty pattern.
   - If the current pattern character is a wildcard '*', set `dp[0][j]` to `dp[0][j-2]` to handle the case where the '*' acts as zero occurrences of the preceding character.
4. Iterate through the string and pattern characters using nested loops, from 1 to the length of the string and 1 to the length of the pattern.
5. For each pair of indices `i` and `j`, compare the current string character `s[i-1]` with the current pattern character `p[j-1]`:
   - If they match (or the pattern character is a '.'):
     - Set `dp[i][j]` to `dp[i-1][j-1]`.
   - If the pattern character is a '*':
     - Consider two cases:
       - Zero occurrences of the preceding character: Set `dp[i][j]` to `dp[i][j-2]`.
       - One or more occurrences of the preceding character:
         - Check if the preceding character in the pattern `p[j-2]` matches the current string character `s[i-1]` or if `p[j-2]` is a '.'.
         - If there's a match, set `dp[i][j]` to `dp[i-1][j]`.
6. After the iteration, `dp[m][n]` will contain whether the entire string matches the entire pattern.
7. Return `dp[m][n]` as the result, where `m` is the length of the string and `n` is the length of the pattern.

Time Complexity:
O(m * n), where `m` is the length of the string and `n` is the length of the pattern. We fill in the `dp` table with a nested loop.

Space Complexity:
O(m * n), as we use a 2D array of size `(m+1) x (n+1)` to store the dynamic programming values.
*/

impl Solution {
    pub fn is_match(s: String, p: String) -> bool {
        let s_chars: Vec<char> = s.chars().collect();
        let p_chars: Vec<char> = p.chars().collect();
        let m = s_chars.len();
        let n = p_chars.len();

        let mut dp = vec![vec![false; n + 1]; m + 1];
        dp[0][0] = true; // Empty string matches empty pattern

        // Initialize dp[0][j] for wildcards '*'
        for j in 2..=n {
            if p_chars[j - 1] == '*' {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for i in 1..=m {
            for j in 1..=n {
                if p_chars[j - 1] == s_chars[i - 1] || p_chars[j - 1] == '.' {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if p_chars[j - 1] == '*' {
                    dp[i][j] = dp[i][j - 2]
                        || (dp[i - 1][j]
                            && (p_chars[j - 2] == s_chars[i - 1] || p_chars[j - 2] == '.'));
                }
            }
        }

        dp[m][n]
    }
}
