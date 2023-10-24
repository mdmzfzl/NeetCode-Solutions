/*
Problem: LeetCode 198 - House Robber

Description:
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed, and the only constraint stopping you from robbing each of them is that adjacent houses have a security system connected,
and it will automatically contact the police if two adjacent houses are broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Intuition:
To maximize the amount of money robbed, we can consider dynamic programming.
At each house, we have two options: either rob the current house or skip it.
If we rob the current house, we cannot rob the previous house, so we take the maximum amount between the current house's value and the amount robbed from the previous house.
If we skip the current house, we take the maximum amount robbed from the previous house.
We want to maximize the total amount of money robbed, so we choose the maximum between these two options.

Approach:
1. Create an array dp of size (n+1), where n is the size of the nums array.
   - dp[i] represents the maximum amount of money that can be robbed up to the ith house.
2. Set the base cases: dp[0] = 0 and dp[1] = nums[0].
3. Iterate from 2 to n:
   - Compute dp[i] by taking the maximum amount between the current house's value plus the amount robbed from the house two steps back and the amount robbed from the previous house:
     dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]).
4. Return dp[n], which represents the maximum amount of money that can be robbed.

Time Complexity:
The time complexity is O(n), where n is the size of the nums array. We iterate through the nums array once.

Space Complexity:
The space complexity is O(n). We use an array of size (n+1) to store the intermediate results.

Dynamic Programming:
- Subproblem: The subproblem is finding the maximum amount of money that can be robbed up to the current house.
- Recurrence Relation: dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]), where dp[i] represents the maximum amount of money that can be robbed up to the ith house.
- Base Case: dp[0] = 0 and dp[1] = nums[0], as there is no house to rob initially, and robbing the first house is the only option.
*/

class Solution {
  public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = nums[0];

        for (int i = 2; i <= n; ++i) {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }

        return dp[n];
    }
};

// Space: O(1)

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int prev = 0;
//         int curr = 0;
//         int next = 0;

//         for (int i = 0; i < nums.size(); i++) {
//             next = max(prev + nums[i], curr);
//             prev = curr;
//             curr = next;
//         }

//         return curr;
//     }
// };