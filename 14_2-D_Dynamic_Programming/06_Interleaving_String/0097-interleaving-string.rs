/*
Problem: LeetCode 97 - Interleaving String

Key Idea:
The key idea is to use dynamic programming to determine whether a third string is formed by interleaving two given strings.

Approach:
1. Initialize a 2D vector `dp` of size `(s1.len() + 1) x (s2.len() + 1)`, where `dp[i][j]` represents whether the first `i` characters of `s1` and the first `j` characters of `s2` can interleave to form the first `i+j` characters of the result string.
2. Initialize `dp[0][0]` to `true` because two empty strings can interleave to form an empty string.
3. Initialize the first row and the first column of `dp`:
   - For `dp[i][0]`, it is `true` if `s1[i-1] == s3[i-1]` and `dp[i-1][0]` is `true` (meaning the previous characters interleaved correctly).
   - For `dp[0][j]`, it is `true` if `s2[j-1] == s3[j-1]` and `dp[0][j-1]` is `true` (meaning the previous characters interleaved correctly).
4. Iterate through the characters of `s1` and `s2` using nested loops from 1 to `s1.len()` and 1 to `s2.len()`.
5. For each pair of indices `i` and `j`, calculate `k = i + j` (the current index in `s3`).
6. Update `dp[i][j]` as `true` if any of the following conditions is met:
   - `s1[i-1] == s3[k-1]` and `dp[i-1][j]` is `true` (meaning the previous characters interleaved correctly).
   - `s2[j-1] == s3[k-1]` and `dp[i][j-1]` is `true` (meaning the previous characters interleaved correctly).
7. After the iteration, `dp[s1.len()][s2.len()]` will indicate whether `s1` and `s2` can interleave to form `s3`.
8. Return `dp[s1.len()][s2.len()]` as the result.

Time Complexity:
O(s1.len() * s2.len()), where `s1.len()` is the length of string `s1` and `s2.len()` is the length of string `s2`. We fill in the `dp` table with a nested loop.

Space Complexity:
O(s1.len() * s2.len()), as we use a 2D vector of size `(s1.len() + 1) x (s2.len() + 1)` to store the dynamic programming values.
*/

impl Solution {
    pub fn is_interleave(s1: String, s2: String, s3: String) -> bool {
        let s1 = s1.as_bytes();
        let s2 = s2.as_bytes();
        let s3 = s3.as_bytes();
        let len1 = s1.len();
        let len2 = s2.len();
        let len3 = s3.len();

        if len1 + len2 != len3 {
            return false;
        }

        let mut dp = vec![vec![false; len2 + 1]; len1 + 1];
        dp[0][0] = true;

        for i in 1..=len1 {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }

        for j in 1..=len2 {
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        }

        for i in 1..=len1 {
            for j in 1..=len2 {
                let k = i + j;
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[k - 1])
                    || (dp[i][j - 1] && s2[j - 1] == s3[k - 1]);
            }
        }

        dp[len1][len2]
    }
}
