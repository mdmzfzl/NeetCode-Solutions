/*
Problem: LeetCode 213 - House Robber II

Description:
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed, and the only constraint stopping you from robbing each of them is that adjacent houses have a security system connected,
and it will automatically contact the police if two adjacent houses are broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
Note: This problem is a variation of LeetCode 198 - House Robber with a circular street, where the first and last houses are adjacent.

Intuition:
To maximize the amount of money robbed, we can consider dynamic programming.
The problem becomes more complex due to the circular nature of the street.
Since the first and last houses are adjacent, we have two possibilities: either rob the first house and skip the last house or skip the first house and rob the last house.
We can solve this problem by splitting it into two separate subproblems:
1. Rob houses from the first to the second-to-last house.
2. Rob houses from the second to the last house.
The maximum amount of money robbed will be the maximum between the two subproblems.

Approach:
1. If the size of the nums array is 1, return nums[0] as it is the only house.
2. Compute the maximum amount of money robbed by considering the two subproblems:
   a. Rob houses from the first to the second-to-last house using the same approach as in the House Robber problem (LeetCode 198).
   b. Rob houses from the second to the last house using the same approach as in the House Robber problem (LeetCode 198).
3. Return the maximum amount between the two subproblems.

Time Complexity:
The time complexity is O(n), where n is the size of the nums array. We iterate through the nums array twice: once for each subproblem.

Space Complexity:
The space complexity is O(1) since we use constant extra space to store the intermediate results.

Dynamic Programming:
- Subproblem: The subproblem is finding the maximum amount of money that can be robbed from a range of houses.
- Recurrence Relation: dp[i] = max(dp[i-2] + nums[i], dp[i-1]), where dp[i] represents the maximum amount of money that can be robbed up to the ith house.
- Base Case: dp[0] = nums[0] and dp[1] = max(nums[0], nums[1]), as the maximum amount to rob the first two houses depends on their values.
*/

class Solution {
  public:
    int rob(vector<int> &nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        int max1 = robRange(nums, 0, n - 2);
        int max2 = robRange(nums, 1, n - 1);
        return max(max1, max2);
    }

    int robRange(vector<int> &nums, int start, int end) {
        int prev1 = 0;
        int prev2 = 0;

        for (int i = start; i <= end; ++i) {
            int current = max(prev1 + nums[i], prev2);
            prev1 = prev2;
            prev2 = current;
        }

        return prev2;
    }
};