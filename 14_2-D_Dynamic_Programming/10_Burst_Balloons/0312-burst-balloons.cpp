/*
Problem: LeetCode 312 - Burst Balloons

Description:
You are given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by an array nums.
You are asked to burst all the balloons.
If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins.
If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
Return the maximum coins you can collect by bursting the balloons wisely.

Intuition:
The problem can be solved using dynamic programming. We can divide the problem into smaller subproblems and find the maximum coins we can get by bursting balloons in different ranges.

Approach:
1. Create a new array "numsWithBorders" by adding 1 at the beginning and end of the "nums" array. This helps in handling edge cases where i - 1 or i + 1 goes out of bounds.
2. Create a 2D DP table of size (n+2) x (n+2), where n is the length of "numsWithBorders".
   - dp[i][j] represents the maximum coins we can get by bursting balloons in the range [i, j].
3. Initialize the DP table diagonally (for single balloons):
   - dp[i][i] represents the maximum coins we can get from bursting the balloon at index i. Since there are no adjacent balloons, dp[i][i] will be numsWithBorders[i].
4. Fill in the DP table by considering the following cases:
   - For each subarray length "len" (from 2 to n), calculate the maximum coins for each possible range [i, j] of length "len".
   - For each range [i, j], try bursting each balloon "k" in the range and calculate the coins obtained. Update dp[i][j] to the maximum coins obtained from all "k" in the range.
5. The final answer will be stored in dp[0][n+1], representing the maximum coins we can get from bursting all balloons.

Time Complexity:
The time complexity of the DP solution is O(n^3), where n is the length of the "nums" array. We need to fill in the entire DP table, and for each subarray length "len", we consider all possible ranges of length "len".

Space Complexity:
The space complexity of the DP solution is O(n^2), where n is the length of the "nums" array. We use a 2D DP table to store the maximum coins for each subproblem.

Dynamic Programming:
- Subproblem: The subproblem is finding the maximum coins we can get by bursting balloons in different ranges.
- Recurrence Relation: The maximum coins for each range [i, j] can be calculated by trying to burst each balloon "k" in the range and updating dp[i][j] with the maximum coins obtained from all "k" in the range.
- Base Case: The base cases are the diagonals of the DP table, representing single balloons without adjacent balloons.
*/

// https://leetcode.com/problems/burst-balloons/solutions/892552/for-those-who-are-not-able-to-understand-any-solution-with-diagram/

class Solution {
  public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        // Create a new array with borders containing 1 to simplify the logic
        vector<int> numsWithBorders(n + 2, 1);

        for (int i = 0; i < n; i++) {
            numsWithBorders[i + 1] = nums[i];
        }

        // Create a 2D DP table to store the maximum coins for each subarray
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // Initialize DP table diagonally for single balloons
        for (int i = 1; i <= n; i++) {
            dp[i][i] = numsWithBorders[i];
        }

        // Fill in DP table for subarrays of length 2 and more
        for (int len = 2; len <= n + 1; len++) {
            for (int i = 0; i <= n + 1 - len; i++) {
                int j = i + len;

                for (int k = i + 1; k < j; k++) {
                    // Calculate the maximum coins for the subarray [i, j] by considering
                    // each possible balloon to be the last one to be bursted in the subarray
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + numsWithBorders[i] * numsWithBorders[k] * numsWithBorders[j]);
                }
            }
        }

        // The maximum coins that can be obtained from bursting all balloons is stored in dp[0][n + 1]
        return dp[0][n + 1];
    }
};

/*
// Beats 99% in Runtime and Memory

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int dp[305][305]; // DP table to store the maximum coins obtained for each range of balloons

        for (int len = 1; len <= n; ++len) { // Iterate over all possible lengths of subarrays
            for (int start = 0; start + len <= n; ++start) { // Iterate over all possible starting positions of subarrays
                int end = start + len - 1; // Calculate the end position of the current subarray

                int leftNeighbor = (start == 0) ? 1 : nums[start - 1]; // Get the value of the left neighbor (if it exists)
                int rightNeighbor = (end + 1 == n) ? 1 : nums[end + 1]; // Get the value of the right neighbor (if it exists)

                if (len == 1) {
                    // If the subarray contains only one balloon, the maximum coins obtained will be just the value of that balloon
                    dp[start][end] = nums[start] * leftNeighbor * rightNeighbor;
                    continue;
                }

                // Calculate the maximum coins obtained by bursting each balloon in the current subarray
                int maxCoinsStart = dp[start + 1][end] + nums[start] * leftNeighbor * rightNeighbor;
                int maxCoinsEnd = dp[start][end - 1] + nums[end] * leftNeighbor * rightNeighbor;

                int maxCoinsMiddle = 0;
                for (int k = start + 1; k < end; ++k) {
                    // Calculate the maximum coins obtained by first bursting balloons in the left subarray,
                    // then bursting balloons in the right subarray, and finally bursting the balloon in the middle
                    int coinsLeft = dp[start][k - 1];
                    int coinsRight = dp[k + 1][end];
                    int coinsBurst = nums[k] * leftNeighbor * rightNeighbor;
                    maxCoinsMiddle = max(maxCoinsMiddle, coinsLeft + coinsRight + coinsBurst);
                }

                // Store the maximum coins obtained for the current subarray in the DP table
                dp[start][end] = max(maxCoinsStart, max(maxCoinsEnd, maxCoinsMiddle));
            }
        }
        return dp[0][n - 1]; // The result is stored in the top-right corner of the DP table for the whole array
    }
};
*/