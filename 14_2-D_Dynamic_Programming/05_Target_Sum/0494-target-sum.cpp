/*
Problem: LeetCode 494 - Target Sum

Description:
You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding or subtracting each element in nums.
Return the number of different expressions that you can build, which evaluates to the target.

Intuition:
To find the number of different expressions that evaluate to the target, we can use dynamic programming.
The problem can be converted to a subset sum problem, where we need to find a subset of elements from the array with a specific sum.
To achieve this, we can transform the problem into a 0/1 knapsack problem.
At each step, we can decide whether to include or exclude an element from the sum.

Approach:
1. Calculate the sum of all elements in the nums array, as it helps to calculate the maximum possible positive sum.
2. Initialize a 2D array dp of size (nums.size() + 1) x (2 * sum + 1), and set dp[0][sum] = 1 to represent the base case where no elements are included, and the sum is 0.
3. Iterate through the nums array and update the dp array as follows:
   - For each element nums[i], update dp[i+1][j] by adding dp[i][j + nums[i]] and dp[i][j - nums[i]], representing including and excluding the element from the sum.
4. Return dp[nums.size()][sum + target], which represents the number of different expressions that evaluate to the target.

Time Complexity:
The time complexity is O(nums.size() * sum), where nums.size() is the number of elements in the array and sum is the sum of all elements.

Space Complexity:
The space complexity is O(nums.size() * sum) as we use a 2D array to store the intermediate results.

Dynamic Programming:
- Subproblem: The subproblem is finding the number of different expressions that evaluate to a specific sum using a subset of elements from the array.
- Recurrence Relation: dp[i+1][j] = dp[i][j + nums[i]] + dp[i][j - nums[i]], where dp[i+1][j] represents the number of different expressions that evaluate to sum j using the first i elements from the array.
- Base Case: Initialize dp[0][sum] = 1 to represent the base case where no elements are included, and the sum is 0.
*/

class Solution {
  public:
    int findTargetSumWays(vector<int> &nums, int target) {
        // Calculate the sum of all elements in the nums array
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // If the target is greater than the sum or less than the negative sum, it's not possible to achieve the target
        if (target > sum || target < -sum) {
            return 0;
        }

        int n = nums.size();
        // Create a 2D dp array to store the number of ways to achieve each possible sum
        // dp[i][j] represents the number of ways to achieve sum j using the first i elements of the nums array
        // We use 2 * sum + 1 as the column size to handle negative numbers
        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));
        // Base case: There's one way to achieve a sum of 0 using an empty subset (no elements)
        dp[0][sum] = 1;

        // Loop through each element in the nums array
        for (int i = 0; i < n; i++) {
            // Loop through each possible sum in the dp array
            for (int j = nums[i]; j <= 2 * sum - nums[i]; j++) {
                // If there's a way to achieve the current sum (dp[i][j]), update the ways to achieve the sums j + nums[i] and j - nums[i]
                if (dp[i][j]) {
                    dp[i + 1][j + nums[i]] += dp[i][j]; // Add nums[i] to the sum
                    dp[i + 1][j - nums[i]] += dp[i][j]; // Subtract nums[i] from the sum
                }
            }
        }

        // Return the number of ways to achieve the target sum
        // We use dp[n][sum + target] because dp[n][sum] represents the number of ways to achieve a sum of 0, and we need to adjust it to the target
        return dp[n][sum + target];
    }
};