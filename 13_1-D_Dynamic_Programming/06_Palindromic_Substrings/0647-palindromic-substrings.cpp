/*
Problem: LeetCode 647 - Palindromic Substrings

Description:
Given a string s, return the number of palindromic substrings in s.
A substring is a contiguous sequence of characters within the string.

Intuition:
To count the number of palindromic substrings, we can use a two-pointer approach.
We iterate through each character in the string and treat it as a potential center of a palindrome.
By expanding from the center, we check if the substring formed is a palindrome and count it as a valid palindrome.

Approach:
1. Initialize a variable count to keep track of the number of palindromic substrings.
2. Iterate through each character in the string:
   - Consider each character as the center of a potential palindrome.
   - Expand around the center using two pointers, one on each side.
   - Count all valid palindromes found during expansion.
3. Return the count of palindromic substrings.

Time Complexity:
The time complexity is O(n^2), where n is the length of the input string s. We iterate through the string and perform expansion for each character.

Space Complexity:
The space complexity is O(1) since we only use a few variables to store indices and counts.
*/

// Better solution but not dynamic programming
class Solution {
  public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            count += countPalindromes(s, i, i);      // Odd-length palindromes
            count += countPalindromes(s, i, i + 1);  // Even-length palindromes
        }

        return count;
    }

    int countPalindromes(string s, int left, int right) {
        int count = 0;

        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }

        return count;
    }
};

/*
Dynamic Programming Approach

Intuition:
To count the number of palindromic substrings, we can consider dynamic programming.
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
4. Count the number of true values in the dp array, which represents the number of palindromic substrings.

Time Complexity:
The time complexity is O(n^2), where n is the length of the input string s. We iterate over the dp array, which has a size of n x n.

Space Complexity:
The space complexity is O(n^2) as well. We use a 2D array dp of size n x n to store the intermediate results.

Dynamic Programming:
- Subproblem: The subproblem is determining whether a substring from index i to j is a palindrome.
- Recurrence Relation: dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1], where dp[i][j] represents whether the substring from index i to j is a palindrome.
- Base Case: dp[i][i] = true (single character is a palindrome) and dp[i][i+1] = (s[i] == s[i+1]) (two identical characters are a palindrome).
*/

// class Solution {
// public:
//     int countSubstrings(string s) {
//         int n = s.length();
//         vector<vector<bool>> dp(n, vector<bool>(n, false));

//         int count = 0;

//         // Base case: single characters are palindromes
//         for (int i = 0; i < n; i++) {
//             dp[i][i] = true;
//             count++;
//         }

//         // Base case: two identical characters are palindromes
//         for (int i = 0; i < n - 1; i++) {
//             if (s[i] == s[i + 1]) {
//                 dp[i][i + 1] = true;
//                 count++;
//             }
//         }

//         // Check for palindromes of length greater than 2
//         for (int len = 3; len <= n; len++) {
//             for (int i = 0; i < n - len + 1; i++) {
//                 int j = i + len - 1;

//                 if (s[i] == s[j] && dp[i + 1][j - 1]) {
//                     dp[i][j] = true;
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }
// };