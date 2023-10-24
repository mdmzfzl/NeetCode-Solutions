/*
Problem: LeetCode 139 - Word Break

Description:
Given a string s and a dictionary of strings wordDict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Intuition:
To determine if a string can be segmented into words from a dictionary, we can use dynamic programming.
The problem can be broken down into smaller subproblems by considering different prefixes of the input string.
We can build the solution by checking if each prefix of the string can be segmented using words from the dictionary.

Approach:
1. Initialize a vector dp of size n+1, where dp[i] represents whether the prefix s[0...i-1] can be segmented using words from the dictionary.
2. Initialize dp[0] as true, indicating that an empty string can be segmented.
3. Iterate through the string from left to right:
   - For each index i, iterate from 0 to i:
     - Check if dp[j] is true and the substring s[j...i-1] is in the dictionary.
     - If both conditions are satisfied, set dp[i] as true.
4. Return dp[n], which represents whether the entire string can be segmented.

Time Complexity:
The time complexity is O(n^2), where n is the length of the input string. We have nested loops to iterate through the string and its prefixes.

Space Complexity:
The space complexity is O(n) as we use an extra array dp of size n+1 to store the intermediate results.

Dynamic Programming:
- Subproblem: The subproblem is determining whether a prefix s[0...i-1] can be segmented using words from the dictionary.
- Recurrence Relation: dp[i] = dp[j] && (s[j...i-1] is in the dictionary) for 0 <= j < i.
- Base Case: dp[0] = true, indicating that an empty string can be segmented.
*/

class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        int n = s.length();
        vector<bool> dp(n + 1, false); // Dynamic programming array to store if substring from 0 to i-1 can be segmented
        dp[0] = true;  // Base case: empty string can be segmented

        for (int i = 1; i <= n; i++) { // Iterate through each position in the string
            for (int j = 0; j < i; j++) { // Iterate over all possible substrings ending at index i
                // Check if substring from j to i-1 is in the word dictionary and if substring from 0 to j-1 can be segmented
                if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true; // Set dp[i] to true if substring from 0 to i-1 can be segmented
                    break; // No need to check further substrings ending at index i
                }
            }
        }

        return dp[n]; // Return whether the entire string can be segmented
    }
};

// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         int n = s.length();
//         vector<bool> dp(n, false);
//         dp[0] = true;

//         for (int i = 0; i <= n; i++) {
//             for (auto word: wordDict) {
//                 if (dp[i] && s.substr(i, word.size()).compare(word) == 0) {
//                     dp[i + word.size()] = true;
//                 }
//             }
//         }

//         return dp[n];
//     }
// };