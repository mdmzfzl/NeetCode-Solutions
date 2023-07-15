/*
Problem: LeetCode 416 - Partition Equal Subset Sum

Description:
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into
two subsets such that the sum of elements in both subsets is equal.

Approach:
1. Calculate the total sum of all elements in the array.
2. If the total sum is odd, return false because it cannot be divided equally into two subsets.
3. Set the target sum to half of the total sum.
4. Initialize a boolean vector dp of size (targetSum + 1) and set dp[0] to true.
   dp[i] will represent whether a subset sum of i can be achieved using elements from the given array.
5. Iterate through each element num in the array:
    a. For each sum j in the range [targetSum, num]:
        - If dp[j - num] is true, set dp[j] to true, indicating that a subset sum of j can be achieved.
6. Return dp[targetSum], which represents whether the array can be partitioned into two equal subsets.

Time Complexity:
The time complexity of this approach is O(n * targetSum), where n is the size of the input array nums.
This is because we have nested loops to iterate through each element and each possible sum.

Space Complexity:
The space complexity is O(targetSum), as we are using an additional boolean vector dp of size (targetSum + 1) to store the results.

Let's implement the solution!
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum % 2 != 0) {
            return false; // Cannot divide odd sum equally into two subsets
        }

        int targetSum = totalSum / 2;
        vector<bool> dp(targetSum + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int j = targetSum; j >= num; j--) {
                if (dp[j - num]) {
                    dp[j] = true;
                }
            }
        }

        return dp[targetSum];
    }
};