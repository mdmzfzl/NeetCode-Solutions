/*
Problem: LeetCode 10 - Regular Expression Matching

Description:
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where:
- '.' Matches any single character.
- '*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

Intuition:
This problem can be solved using dynamic programming. We can break down the problem into smaller subproblems and use a 2D DP table to store the results of these subproblems.

Approach:
1. Create a 2D DP table of size (s.length() + 1) x (p.length() + 1), where s.length() and p.length() are the lengths of the input string "s" and pattern "p", respectively.
   - dp[i][j] represents whether the substring s[0...i-1] matches the pattern p[0...j-1].
2. Initialize the DP table:
   - dp[0][0] represents whether an empty string matches an empty pattern, which is true. So, dp[0][0] = true.
   - dp[i][0] represents whether an empty string matches the pattern p[0...i-1]. For all i > 0, dp[i][0] is false because a non-empty pattern cannot match an empty string.
   - For dp[0][j], we need to handle patterns with '*', which means we should check if p[j-1] is '*' and if there's a valid pattern before it. If yes, then dp[0][j] will have the same result as dp[0][j-2].
3. Fill in the DP table by considering the following cases:
   - If p[j-1] is a regular character or '.', we need to check if s[i-1] matches p[j-1]. If yes, then dp[i][j] will be true if dp[i-1][j-1] is true.
   - If p[j-1] is '*', we have two sub-cases:
     a) If the character before '*' in the pattern (p[j-2]) matches the current character in the string (s[i-1]) or it is '.', then we have two options:
        - Ignore the '*' and the preceding character in the pattern: dp[i][j] will be true if dp[i][j-2] is true.
        - Consider the '*' and the preceding character in the pattern: dp[i][j] will be true if dp[i-1][j] is true and s[i-1] matches the preceding character in the pattern (p[j-2]).
4. The final answer will be stored in dp[s.length()][p.length()], representing whether the entire string "s" matches the entire pattern "p".

Time Complexity:
The time complexity of the DP solution is O(s.length() * p.length()), where s.length() and p.length() are the lengths of the input string "s" and pattern "p", respectively. We fill in the entire DP table of size (s.length() + 1) x (p.length() + 1).

Space Complexity:
The space complexity of the DP solution is O(s.length() * p.length()), where s.length() and p.length() are the lengths of the input string "s" and pattern "p", respectively. We use a 2D DP table to store the results of subproblems.

Dynamic Programming:
- Subproblem: The subproblem is whether a substring s[0...i-1] matches a pattern p[0...j-1].
- Recurrence Relation: The result for dp[i][j] depends on whether s[i-1] matches p[j-1] and the results of previous subproblems (dp[i-1][j-1], dp[i-1][j], dp[i][j-2]).
- Base Case: The base cases are dp[0][0], dp[i][0] (for all i > 0), and dp[0][j] (for patterns with '*').
*/

class Solution {
  public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        // Create a 2D DP table and initialize base cases
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        // Base case: an empty pattern matches an empty string
        dp[0][0] = true;

        // Initialize the first row for pattern p
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                // If the current character in pattern is '*', it can match zero or more of the preceding element
                // So, we check if it matches two characters back in the pattern (j - 2) for an empty string
                dp[0][j] = dp[0][j - 2];
            }
        }

        // Fill in the DP table row by row
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    // If the current pattern character matches the current string character or it's a '.',
                    // we take the value from the diagonal (dp[i - 1][j - 1]) as the result for the current cell
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // If the current pattern character is '*', it can match zero or more of the preceding element
                    // So, we check if it matches two characters back in the pattern (j - 2) for an empty string
                    // or if the current string character matches the preceding pattern character
                    // (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'))
                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                }
            }
        }

        return dp[m][n]; // The last cell (dp[m][n]) contains the result for the entire matching process
    }
};

/*
// Beats 100% Runtime and O(n) space complexity

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        // Create a 1D DP array to store the matching results
        vector<bool> dp(n + 1, false);

        // Base case: an empty pattern matches an empty string
        dp[0] = true;

        // Initialize the DP array for the first row (when i = 0)
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                // If the current character is '*', it can match zero or more of the preceding element
                // So, we check if it matches two characters back in the pattern (j - 2)
                dp[j] = dp[j - 2];
            }
        }

        // Fill in the DP array row by row
        for (int i = 1; i <= m; i++) {
            bool prevDiagonal = dp[0]; // Store the value of the diagonal element (dp[i - 1][j - 1]) before updating it
            dp[0] = false; // Update the base case for each row, as a non-empty pattern cannot match an empty string

            // Iterate through the pattern characters
            for (int j = 1; j <= n; j++) {
                bool temp = dp[j]; // Store the current value of dp[i][j] before updating it

                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    // If the current pattern character matches the current string character or it's a '.',
                    // we take the value from the diagonal (dp[i - 1][j - 1]) as the result for the current cell
                    dp[j] = prevDiagonal;
                } else if (p[j - 1] == '*') {
                    // If the current pattern character is '*', it can match zero or more of the preceding element
                    // So, we check if it matches two characters back in the pattern (j - 2) or if the current string
                    // character matches the preceding pattern character (dp[j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'))
                    dp[j] = dp[j - 2] || (dp[j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    // If the characters don't match and there's no wildcard, update the cell to false
                    dp[j] = false;
                }

                prevDiagonal = temp; // Update the diagonal element for the next iteration
            }
        }

        return dp[n]; // The last cell (dp[m][n]) contains the result for the entire matching process
    }
};
*/