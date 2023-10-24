/*
Problem: LeetCode 416 - Partition Equal Subset Sum

Description:
Given a non-empty array nums containing only positive integers, determine if it can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Intuition:
To determine if the array can be partitioned into two equal subsets, we can use dynamic programming.
The problem can be broken down into smaller subproblems by considering different subsets of the input array.
We can build the solution by checking if there exists a subset with a target sum equal to half of the total sum of the array.

Approach:
1. Calculate the total sum of the array.
2. If the total sum is odd, return false. It's not possible to partition the array into equal subsets.
3. Initialize a vector dp of size (sum/2) + 1, where dp[i] represents whether a subset with sum i can be formed.
4. Initialize dp[0] as true, indicating that an empty subset with sum 0 can be formed.
5. Iterate through the array nums:
   - For each number num, iterate from (sum/2) down to num:
     - If dp[i - num] is true, set dp[i] as true, indicating that a subset with sum i can be formed.
6. Return dp[sum/2], which represents whether a subset with sum (sum/2) can be formed.

Time Complexity:
The time complexity is O(n * sum), where n is the size of the input array and sum is the total sum of the array.

Space Complexity:
The space complexity is O(sum), as we use an extra array dp of size (sum/2) + 1 to store the intermediate results.

Dynamic Programming:
- Subproblem: The subproblem is determining whether a subset with a target sum can be formed using a subset of the array.
- Recurrence Relation: dp[i] = dp[i - num] for each num in the array, if dp[i - num] is true.
- Base Case: dp[0] = true, indicating that an empty subset with sum 0 can be formed.
*/

class Solution {
  public:
    bool canPartition(vector<int> &nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0); // Calculate the total sum

        if (sum % 2 != 0) {
            return false; // If the total sum is odd, it's not possible to partition into equal subsets
        }

        int target = sum / 2;
        vector<bool> dp(target + 1, false); // Subset with sum i can be formed
        dp[0] = true; // Base case: Empty subset with sum 0 can be formed

        for (int num : nums) {
            for (int i = target; i >= num; i--) {
                if (dp[i - num]) {
                    dp[i] = true;
                }
            }
        }

        return dp[target];
    }
};