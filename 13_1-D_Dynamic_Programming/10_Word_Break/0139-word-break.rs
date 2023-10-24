/*
Problem: LeetCode 139 - Word Break

Key Idea:
The key idea is to use dynamic programming to determine if a given string can be segmented into words from a dictionary.

Approach:
1. Initialize a boolean vector `dp` of size `n + 1`, where `n` is the length of the input string `s`.
   - `dp[i]` will represent whether the substring from index 0 to `i-1` can be segmented into words from the dictionary.
2. Set `dp[0]` to `true` because an empty string can always be segmented.
3. Iterate through the input string `s` from the first character to the last character:
   - For each index `i`, iterate through the dictionary words and check if a word `word` can be found such that:
     - `dp[i - len]` is `true`, where `len` is the length of `word`.
     - The substring from index `i - len` to `i-1` (inclusive) is equal to `word`.
   - If such a word is found, set `dp[i]` to `true`.
4. After the iteration, `dp[n]` will be `true` if and only if the entire string `s` can be segmented into words from the dictionary.
5. Return `dp[n]` as the result.

Time Complexity:
O(n^2), where `n` is the length of the input string `s`. In the worst case, we have nested loops over `i` and `j` such that `i * j <= n`.

Space Complexity:
O(n), as we use a boolean vector of size `n + 1` to store the dynamic programming values.
*/

impl Solution {
    pub fn word_break(s: String, word_dict: Vec<String>) -> bool {
        let n = s.len();
        let mut dp = vec![false; n + 1];
        dp[0] = true;

        let word_set: std::collections::HashSet<String> = word_dict.into_iter().collect();

        for i in 1..=n {
            for j in 0..i {
                if dp[j] && word_set.contains(&s[j..i]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        dp[n]
    }
}
