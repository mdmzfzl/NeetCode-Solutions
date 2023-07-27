/*
Problem: LeetCode 70 - Climbing Stairs

Description:
You are climbing a staircase that has n steps. You can either climb 1 or 2 steps at a time.
Return the number of distinct ways to climb to the top.

Intuition:
To reach the nth step, we can either take a single step from the (n-1)th step or take two steps from the (n-2)th step.
This forms the basis of our dynamic programming approach, as we can break down the problem into subproblems and build the solution from there.

Approach:
1. Initialize an array dp of size (n+1) to store the number of distinct ways to reach each step.
2. Set the base cases: dp[0] = 1 (no steps needed) and dp[1] = 1 (one step to reach the first step).
3. Iterate from 2 to n:
   - Compute dp[i] by summing up the number of ways to reach the previous two steps: dp[i] = dp[i-1] + dp[i-2].
4. Return dp[n], which represents the number of distinct ways to reach the top step.

Time Complexity:
The time complexity is O(n) since we iterate through the steps once.

Space Complexity:
The space complexity is O(n) since we use an array of size (n+1) to store the intermediate results.

Dynamic Programming:
- Subproblem: The subproblem is finding the number of distinct ways to reach the current step.
- Recurrence Relation: dp[i] = dp[i-1] + dp[i-2], where dp[i] represents the number of distinct ways to reach the ith step.
- Base Case: dp[0] = 1 and dp[1] = 1, as there is only one way to reach the first two steps.
*/

class Solution {
  public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;  // Base cases
        }

        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];  // Recurrence relation
        }

        return dp[n];
    }
};

// O(1) Space
// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n <= 2)
//             return n;

//         int first = 1, second = 2;

//         for(int  i = 2; i < n; i++) {
//             int temp = second;
//             second = first + second;
//             first = temp;
//         }
//         return second;
//     }
// };