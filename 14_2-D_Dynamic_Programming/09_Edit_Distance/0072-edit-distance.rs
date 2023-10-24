/*
Problem: LeetCode 72 - Edit Distance

Key Idea:
The key idea is to use dynamic programming to find the minimum number of operations (insert, delete, or replace) required to convert one string into another.

Approach:
1. Initialize a 2D vector `dp` of size `(m+1) x (n+1)`, where `dp[i][j]` represents the minimum edit distance between the first `i` characters of string `word1` and the first `j` characters of string `word2`.
2. Initialize the first row and the first column of `dp` to represent the case where one of the strings is empty. For example, `dp[i][0]` represents the edit distance between the first `i` characters of `word1` and an empty string, which is simply `i` (deletions).
   Similarly, `dp[0][j]` represents the edit distance between an empty string and the first `j` characters of `word2`, which is simply `j` (insertions).
3. Iterate through the characters of `word1` and `word2` using nested loops from 1 to `m` and 1 to `n`.
4. For each pair of indices `i` and `j`, compare `word1[i-1]` and `word2[j-1]`:
   - If they are equal, no operation is needed, so `dp[i][j] = dp[i-1][j-1]`.
   - If they are not equal, calculate `dp[i][j]` as the minimum of three options:
     - Deletion: `dp[i-1][j] + 1` (delete a character from `word1`).
     - Insertion: `dp[i][j-1] + 1` (insert a character into `word1`).
     - Replacement: `dp[i-1][j-1] + 1` (replace `word1[i-1]` with `word2[j-1]`).
5. After the iteration, `dp[m][n]` will contain the minimum edit distance between `word1` and `word2`.
6. Return `dp[m][n]` as the result.

Time Complexity:
O(m * n), where `m` is the length of `word1` and `n` is the length of `word2`. We fill in the `dp` table with a nested loop.

Space Complexity:
O(m * n), as we use a 2D vector of size `(m+1) x (n+1)` to store the dynamic programming values.
*/

impl Solution {
    pub fn min_distance(word1: String, word2: String) -> i32 {
        let word1_chars: Vec<char> = word1.chars().collect();
        let word2_chars: Vec<char> = word2.chars().collect();
        let m = word1_chars.len();
        let n = word2_chars.len();

        let mut dp = vec![vec![0; n + 1]; m + 1];

        // Initialize the first row and first column
        for i in 0..=m {
            dp[i][0] = i;
        }
        for j in 0..=n {
            dp[0][j] = j;
        }

        for i in 1..=m {
            for j in 1..=n {
                if word1_chars[i - 1] == word2_chars[j - 1] {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + dp[i - 1][j - 1].min(dp[i][j - 1].min(dp[i - 1][j]));
                }
            }
        }

        dp[m][n] as i32
    }
}
