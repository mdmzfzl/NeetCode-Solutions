/*
Problem: LeetCode 91 - Decode Ways

Description:
A message containing letters from A-Z can be encoded into numbers using the following mapping:
'A' -> "1", 'B' -> "2", ..., 'Z' -> "26".
Given a string s containing only digits, return the number of ways to decode it.
Note: The grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is not mapped to any letter.

Intuition:
To count the number of ways to decode a given string, we can use dynamic programming.
The problem can be broken down into smaller subproblems where we consider different lengths of substrings.
We can build the solution by considering the number of ways to decode smaller substrings and combine them to get the final answer.

Approach:
1. Initialize an array dp of size n+1, where n is the length of the input string s.
   - dp[i] will represent the number of ways to decode the substring s[0:i].
2. Initialize dp[0] to 1 as there is one way to decode an empty string.
3. Iterate through the characters of the string:
   - If the current character is not '0', update dp[i] by adding dp[i-1] to account for single-digit decoding.
   - If the current character, along with the previous character, forms a valid two-digit number, update dp[i] by adding dp[i-2].
4. Return dp[n], which represents the number of ways to decode the entire string.

Time Complexity:
The time complexity is O(n), where n is the length of the input string s. We iterate through each character of the string once.

Space Complexity:
The space complexity is O(n) as well. We use an array dp of size n+1 to store the intermediate results.

Dynamic Programming:
- Subproblem: The subproblem is calculating the number of ways to decode a substring of length i.
- Recurrence Relation: dp[i] = dp[i-1] + dp[i-2], if the current character and the previous character form a valid two-digit number.
- Base Case: dp[0] = 1 (empty string has one way to decode).
*/

class Solution {
  public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;  // Base case: empty string has one way to decode

        for (int i = 1; i <= n; i++) {
            // Check if current character is not '0'
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];  // Add the number of ways for single-digit decoding
            }

            // Check if current character and the previous character form a valid two-digit number
            if (i > 1 && isValidTwoDigit(s[i - 2], s[i - 1])) {
                dp[i] += dp[i - 2];  // Add the number of ways for two-digit decoding
            }
        }

        return dp[n];
    }

    bool isValidTwoDigit(char c1, char c2) {
        int num = (c1 - '0') * 10 + (c2 - '0');
        return num >= 10 && num <= 26;
    }
};

// class Solution {
// public:
//     int numDecodings(string s) {
//         int n = s.size();
//         if (n == 0 || s[0] == '0') {
//             return 0;
//         }

//         vector<int> dp(n + 1);
//         dp[0] = 1;
//         dp[1] = 1;

//         for (int i = 2; i <= n; i++) {
//             // Single digit
//             int ones = stoi(s.substr(i - 1, 1));
//             if (0 < ones && ones < 10) {
//                 dp[i] += dp[i - 1];
//             }

//             // Double digit
//             int tens = stoi(s.substr(i - 2, 2));
//             if (tens >= 10 && tens <= 26) {
//                 dp[i] += dp[i - 2];
//             }
//         }
//         return dp[n];
//     }
// };
