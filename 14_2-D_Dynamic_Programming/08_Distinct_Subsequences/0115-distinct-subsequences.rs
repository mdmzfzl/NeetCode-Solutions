/*
Problem: LeetCode 115 - Distinct Subsequences

Key Idea:
The key idea is to use dynamic programming to count the number of distinct subsequences of string `s` that are equal to string `t`.

Approach:
1. Initialize a 2D vector `dp` of size `(m+1) x (n+1)`, where `dp[i][j]` represents the number of distinct subsequences of the first `i` characters of string `s` that are equal to the first `j` characters of string `t`.
2. Initialize the first row of `dp` with all zeros because there is no way to form a non-empty string `t` from an empty string `s`.
3. Initialize `dp[0][0]` to 1 because an empty string `s` can form an empty string `t` in one way (by not selecting any characters).
4. Iterate through the characters of string `s` and string `t` using nested loops, from 1 to `m` and 1 to `n`.
5. For each pair of indices `i` and `j`, compare `s[i-1]` and `t[j-1]`:
   - If `s[i-1]` is equal to `t[j-1]`, we have two choices:
     - We can include the current character `s[i-1]` in the subsequence. In this case, add `dp[i-1][j-1]` to `dp[i][j]`, which represents selecting the current character.
     - We can exclude the current character `s[i-1]` from the subsequence. In this case, add `dp[i-1][j]` to `dp[i][j]`, which represents not selecting the current character.
   - If `s[i-1]` is not equal to `t[j-1]`, we can only exclude the current character `s[i-1]`, so add `dp[i-1][j]` to `dp[i][j]`.
6. After the iteration, `dp[m][n]` will contain the number of distinct subsequences of string `s` equal to string `t`.
7. Return `dp[m][n]` as the result.

Time Complexity:
O(m * n), where `m` is the length of string `s` and `n` is the length of string `t`. We fill in the `dp` table with a nested loop.

Space Complexity:
O(m * n), as we use a 2D vector of size `(m+1) x (n+1)` to store the dynamic programming values.
*/

impl Solution {
    pub fn num_distinct(s: String, t: String) -> i32 {
        let s_chars: Vec<char> = s.chars().collect();
        let t_chars: Vec<char> = t.chars().collect();
        let m = s_chars.len();
        let n = t_chars.len();

        if m < n {
            return 0;
        }

        let mut dp = vec![vec![0; n + 1]; m + 1];

        for i in 0..=m {
            dp[i][0] = 1; // Any string can form an empty string in one way.
        }

        for i in 1..=m {
            for j in 1..=n {
                if s_chars[i - 1] == t_chars[j - 1] {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        dp[m][n]
    }
}

/*
impl Solution {
    pub fn num_distinct(s: String, t: String) -> i32 {
        let s_bytes = s.as_bytes();
        let t_bytes = t.as_bytes();

        let mut dp = vec![0; s.len()];
        let mut result = 1;

        for &char_t in t_bytes {
            let mut temp = result;
            result = 0;

            for i in (0..s.len()).rev() {
                temp -= dp[i];
                dp[i] = (s_bytes[i] == char_t) as i32 * temp;
                result += dp[i];
            }
        }

        result
    }
}
*/
