/*
Problem: LeetCode 746 - Min Cost Climbing Stairs

Description:
You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
Once you pay the cost, you can either climb one or two steps.
You can either start from the 0th step or the 1st step.
Return the minimum cost to reach the top of the floor.

Intuition:
To reach the top of the floor with minimum cost, we can consider dynamic programming.
At each step, we have two options: either take one step from the current step or take two steps from the previous step.
We want to minimize the total cost, so we choose the minimum cost between these two options.

Approach:
1. Create an array dp of size (n+1), where n is the size of the cost array.
   - dp[i] represents the minimum cost to reach the ith step.
2. Set the base cases: dp[0] = cost[0] and dp[1] = cost[1].
3. Iterate from 2 to n:
   - Compute dp[i] by taking the minimum cost between the (i-1)th step and the (i-2)th step, plus the cost of the current step:
     dp[i] = min(dp[i-1], dp[i-2]) + cost[i].
4. Return the minimum cost between reaching the (n-1)th step and the nth step: min(dp[n-1], dp[n]).

Time Complexity:
The time complexity is O(n), where n is the size of the cost array. We iterate through the cost array once.

Space Complexity:
The space complexity is O(n). We use an array of size (n+1) to store the intermediate results.

Dynamic Programming:
- Subproblem: The subproblem is finding the minimum cost to reach the current step.
- Recurrence Relation: dp[i] = min(dp[i-1], dp[i-2]) + cost[i], where dp[i] represents the minimum cost to reach the ith step.
- Base Case: dp[0] = cost[0] and dp[1] = cost[1], as the minimum cost to reach the first two steps is the cost of those steps.
*/

class Solution {
  public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        vector<int> dp(n + 1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i <= n; ++i) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }

        return min(dp[n - 1], dp[n]);
    }
};

// O(1) space
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int prev1 = cost[0];
//         int prev2 = cost[1];

//         for (int i = 2; i < cost.size(); i++) {
//             int current = cost[i] + min(prev1, prev2);
//             prev1 = prev2;
//             prev2 = current;
//         }

//         return min(prev1, prev2);
//     }
// };