/*
Problem: LeetCode 72 - Edit Distance

Description:
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
1. Insert a character
2. Delete a character
3. Replace a character

Intuition:
The problem can be solved using dynamic programming. We can break down the problem into smaller subproblems and find the minimum number of operations required to transform prefixes of the two strings into each other.

Approach:
1. Create a 2D DP table of size (m+1) x (n+1), where m and n are the lengths of word1 and word2, respectively.
   - dp[i][j] represents the minimum number of operations required to convert the first i characters of word1 to the first j characters of word2.
2. Initialize the first row and first column of the DP table as follows:
   - dp[i][0] represents the minimum number of operations required to convert the first i characters of word1 to an empty string (i deletions).
   - dp[0][j] represents the minimum number of operations required to convert an empty string to the first j characters of word2 (j insertions).
3. Fill in the DP table by considering the following cases:
   - If word1[i-1] is equal to word2[j-1], dp[i][j] will be the same as dp[i-1][j-1] since no operation is required.
   - If word1[i-1] is not equal to word2[j-1], dp[i][j] will be the minimum of the following three cases:
     a. dp[i-1][j] + 1 (deletion in word1)
     b. dp[i][j-1] + 1 (insertion in word1)
     c. dp[i-1][j-1] + 1 (replacement in word1)
4. The final answer will be stored in dp[m][n], representing the minimum number of operations required to convert word1 to word2.

Time Complexity:
The time complexity of the DP solution is O(m*n), where m and n are the lengths of word1 and word2, respectively. We need to fill in the entire DP table.

Space Complexity:
The space complexity of the DP solution is O(m*n), where m and n are the lengths of word1 and word2, respectively. We use a 2D DP table to store the minimum number of operations for each subproblem.

Dynamic Programming:
- Subproblem: The subproblem is finding the minimum number of operations required to convert prefixes of word1 to prefixes of word2.
- Recurrence Relation: The minimum number of operations is determined by three cases: insertion, deletion, or replacement.
- Base Case: The base cases are the first row and the first column of the DP table, representing conversions to and from empty strings.
*/

class Solution {
  public:
    int minDistance(string word1, string word2) {
        if (word1.empty() && word2.empty()) {
            return 0;
        }

        if (word1.empty() || word2.empty()) {
            return 1;
        }

        int m = word1.size();
        int n = word2.size();
        // Create a 2D DP table to store the minimum edit distance for subproblems
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Initialize the first row and first column of the DP table
        // dp[i][0] represents the minimum edit distance between word1[0:i] and an empty string
        // dp[0][j] represents the minimum edit distance between an empty string and word2[0:j]
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }

        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        // Fill in the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    // If the characters at the current positions are equal, no operation is needed
                    // So, the minimum edit distance is the same as the previous subproblem
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // If the characters at the current positions are different, we have three options:
                    // 1. Insert: dp[i][j - 1] represents the minimum edit distance if we insert a character from word2
                    // 2. Delete: dp[i - 1][j] represents the minimum edit distance if we delete a character from word1
                    // 3. Replace: dp[i - 1][j - 1] represents the minimum edit distance if we replace a character in word1
                    // Take the minimum of these three options and add 1 to account for the current operation
                    dp[i][j] = 1 + min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
                }
            }
        }

        // The final result is stored in dp[m][n], which represents the minimum edit distance between the two words
        return dp[m][n];
    }
};

// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();

//         // Create a 2D DP table to store the minimum edit distance for subproblems
//         int dp[n + 1][m + 1];

//         // Initialize the DP table
//         for (int i = 0; i <= n; i++) {
//             for (int j = 0; j <= m; j++) {
//                 if (i == 0 || j == 0) {
//                     // Base case: If one of the strings is empty, the minimum edit distance is the length of the non-empty string
//                     dp[i][j] = max(i, j);
//                 } else if (word1[i - 1] == word2[j - 1]) {
//                     // If the characters at the current positions are equal, no operation is needed
//                     dp[i][j] = dp[i - 1][j - 1];
//                 } else {
//                     // If the characters at the current positions are different
//                     dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
//                 }
//             }
//         }

//         // The final result is stored in dp[n][m], which represents the minimum edit distance between the two words
//         return dp[n][m];
//     }
// };