/*
Problem: LeetCode 5 - Longest Palindromic Substring

Description:
Given a string s, return the longest palindromic substring in s.

Intuition:
To find the longest palindromic substring, we can consider dynamic programming.
A palindrome reads the same backward as forward, so we can use this property to solve the problem.
We define a 2D array dp, where dp[i][j] represents whether the substring from index i to j is a palindrome.
Using this definition, we can build the solution by considering smaller subproblems and expanding from there.

Approach:
1. Create a 2D boolean array dp of size (n x n), where n is the length of the input string s.
   - dp[i][j] will be true if the substring from index i to j is a palindrome, and false otherwise.
2. Initialize the base cases:
   - Set dp[i][i] to true, as single characters are palindromes.
   - Set dp[i][i+1] to true if s[i] is equal to s[i+1], as two identical characters are palindromes.
3. Iterate over the substring lengths from 3 to n:
   - Iterate over the starting index i from 0 to n - len:
     - Calculate the ending index j as i + len - 1.
     - Update dp[i][j] to true if s[i] is equal to s[j] and dp[i+1][j-1] is true.
4. Keep track of the longest palindromic substring by updating the start and end indices whenever a longer palindrome is found.
5. Return the substring from the start index to the end index.

Time Complexity:
The time complexity is O(n^2), where n is the length of the input string s. We iterate over the dp array, which has a size of n x n.

Space Complexity:
The space complexity is O(n^2) as well. We use a 2D array dp of size n x n to store the intermediate results.

Dynamic Programming:
- Subproblem: The subproblem is determining whether a substring from index i to j is a palindrome.
- Recurrence Relation: dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1], where dp[i][j] represents whether the substring from index i to j is a palindrome.
- Base Case: dp[i][i] = true (single character is a palindrome) and dp[i][i+1] = (s[i] == s[i+1]) (two identical characters are a palindrome).
*/

class Solution {
  public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0;
        int maxLen = 1;

        // Base case: single characters are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Base case: two identical characters are palindromes
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // Check for palindromes of length greater than 2
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;

                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLen = len;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

// Expanding around the center approach
// This approach does not utilize dynamic programming

// Consider each element as middle of a palindrome and keep expanding

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         // Two possibilities, palindrome can be even or odd length
//         for(int i = 0; i < s.size() - 1; i++) {
//             // To check odd palindromes
//             helper(s, i, i);
//             // To check even palindromes
//             helper(s, i, i+1);
//         }

//         return s.substr(start, maxLength);
//     }

// private:
//     // need the index and length to cut the string using substr
//     int start = 0, maxLength = 1;
//     void helper(string S, int L, int R) {
//         while(L >= 0 && R < S.size() && S[L] == S[R])
//             L--, R++;

//         int len = R - L - 1;
//         if(len > maxLength) {
//             start = L + 1;
//             maxLength = len;
//         }
//     }
// };