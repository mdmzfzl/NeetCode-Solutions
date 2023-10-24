/*
Problem: LeetCode 1143 - Longest Common Subsequence

Key Idea:
The key idea is to use dynamic programming to find the longest common subsequence (LCS) between two strings.

Approach:
1. Initialize a 2D vector `dp` of size `(text1.len() + 1) x (text2.len() + 1)`, where `dp[i][j]` represents the length of the LCS of `text1[0..i]` and `text2[0..j]`.
2. Initialize the first row and the first column of `dp` to 0 because the LCS of any string with an empty string is 0.
3. Iterate through the characters of `text1` and `text2` using nested loops from 1 to `text1.len()` and 1 to `text2.len()`.
4. For each pair of characters `text1[i-1]` and `text2[j-1]`:
   - If they are equal, set `dp[i][j]` to `dp[i-1][j-1] + 1` because we can extend the LCS.
   - If they are not equal, set `dp[i][j]` to the maximum of `dp[i-1][j]` and `dp[i][j-1]` because we take the maximum length LCS without the current characters.
5. After the iteration, `dp[text1.len()][text2.len()]` will contain the length of the LCS.
6. Return `dp[text1.len()][text2.len()]` as the result.

Time Complexity:
O(m * n), where `m` is the length of `text1` and `n` is the length of `text2`. We fill in the `dp` table with a nested loop.

Space Complexity:
O(m * n), as we use a 2D vector of size `(text1.len() + 1) x (text2.len() + 1)` to store the dynamic programming values.
*/

impl Solution {
    pub fn longest_common_subsequence(text1: String, text2: String) -> i32 {
        let m = text1.len();
        let n = text2.len();

        let mut dp = vec![vec![0; n + 1]; m + 1];

        for i in 1..=m {
            for j in 1..=n {
                let char1 = text1.chars().nth(i - 1).unwrap();
                let char2 = text2.chars().nth(j - 1).unwrap();

                if char1 == char2 {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = dp[i - 1][j].max(dp[i][j - 1]);
                }
            }
        }

        dp[m][n]
    }
}

/*
// Faster solution

impl Solution {
    pub fn longest_common_subsequence(text1: String, text2: String) -> i32 {
        let text1_bytes = text1.as_bytes();
        let text2_bytes = text2.as_bytes();
        let (m, n) = (text1_bytes.len(), text2_bytes.len());

        let mut dp = vec![vec![0; n + 1]; m + 1];

        for i in 1..=m {
            for j in 1..=n {
                dp[i][j] = if text1_bytes[i - 1] == text2_bytes[j - 1] {
                    dp[i - 1][j - 1] + 1
                } else {
                    std::cmp::max(dp[i - 1][j], dp[i][j - 1])
                };
            }
        }

        dp[m][n]
    }
}
*/
