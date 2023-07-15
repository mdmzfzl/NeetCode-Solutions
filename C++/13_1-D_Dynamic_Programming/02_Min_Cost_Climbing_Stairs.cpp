/*
Problem: LeetCode 746 - Min Cost Climbing Stairs

Description:
You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0 or the step with index 1.
Return the minimum cost to reach the top of the floor.

Approach:
1. Initialize two variables, prev1 and prev2, to represent the minimum cost of reaching the previous two steps.
   Initially, set prev1 and prev2 to cost[0] and cost[1] respectively.
2. Iterate through the steps starting from index 2:
    - For each step, calculate the minimum cost to reach it:
        - current = cost[i] + min(prev1, prev2)
        - Update prev1 = prev2 and prev2 = current for the next iteration.
3. Return the minimum of prev1 and prev2, which represents the minimum cost to reach the top of the floor.

Time Complexity:
The time complexity of this approach is O(n), where n is the size of the input array cost.
This is because we iterate through the array once to calculate the minimum cost.

Space Complexity:
The space complexity is O(1), as we are using only a constant amount of extra space.

Let's implement the solution!
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev1 = cost[0];
        int prev2 = cost[1];

        for (int i = 2; i < cost.size(); i++) {
            int current = cost[i] + min(prev1, prev2);
            prev1 = prev2;
            prev2 = current;
        }

        return min(prev1, prev2);
    }
};
