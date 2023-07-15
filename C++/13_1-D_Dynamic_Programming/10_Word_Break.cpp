/*
Problem: LeetCode 139 - Word Break

Description:
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated
sequence of one or more dictionary words.

Approach:
1. Initialize a boolean array dp of size (s.length() + 1) and set dp[0] to true.
   dp[i] will represent whether a prefix of s ending at index i (exclusive) can be segmented into words from wordDict.
2. Iterate through each index i in the range [0, n], where n is the length of the input string s:
    a. For each word in the wordDict:
        - If dp[i] is true and the substring from index i to (i + word.size()) in s matches the current word,
          set dp[i + word.size()] to true, indicating that the prefix of s ending at index (i + word.size()) can be segmented.
3. Return dp[n], which represents whether the entire string s can be segmented.

Time Complexity:
The time complexity of this approach is O(n * m), where n is the length of the input string s and m is the size of the wordDict.
This is because we iterate through each character of the string and for each character, iterate through the wordDict.

Space Complexity:
The space complexity is O(n), as we are using an additional boolean array dp of size (s.length() + 1) to store the results.
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n, false);
        dp[0] = true;

        for (int i = 0; i <= n; i++) {
            for (auto word: wordDict) {
                if (dp[i] && s.substr(i, word.size()).compare(word) == 0) {
                    dp[i + word.size()] = true;
                }
            }
        }

        return dp[n];
    }
};