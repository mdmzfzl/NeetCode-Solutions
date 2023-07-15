/*
Problem: LeetCode 91 - Decode Ways

Description:
A message containing letters from A-Z can be encoded into numbers using the following mapping:
'A' -> "1", 'B' -> "2", ..., 'Z' -> "26".
Given a string s containing only digits, return the number of ways to decode it.

Approach:
1. Initialize a vector dp of size (n + 1), where n is the length of the input string s.
   dp[i] will store the number of ways to decode a substring of s from index 0 to i.
2. Set dp[0] and dp[1] to 1, as there is only one way to decode an empty string or a string of length 1.
3. Iterate through each index i from 2 to n:
    a. Decode the current character as a single digit (ones place) using stoi(s.substr(i - 1, 1)):
        - If the digit is between 1 and 9 (inclusive), add dp[i - 1] to dp[i], as it can be decoded as a single character.
    b. Decode the current and previous characters as a double digit (tens place) using stoi(s.substr(i - 2, 2)):
        - If the double-digit number is between 10 and 26 (inclusive), add dp[i - 2] to dp[i],
          as it can be decoded as two separate characters.
4. Return dp[n], which represents the number of ways to decode the entire string s.

Time Complexity:
The time complexity of this approach is O(n), where n is the length of the input string s.
This is because we iterate through each character in the string once.

Space Complexity:
The space complexity is O(n), as we are using an additional vector dp of size (n + 1) to store the number of ways.

Let's implement the solution!
*/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') {
            return 0;
        }
        
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            // Single digit
            int ones = stoi(s.substr(i - 1, 1));
            if (0 < ones && ones < 10) {
                dp[i] += dp[i - 1];
            }

            // Double digit
            int tens = stoi(s.substr(i - 2, 2));
            if (tens >= 10 && tens <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};
