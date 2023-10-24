/*
Problem: LeetCode 300 - Longest Increasing Subsequence

Description:
Given an integer array nums, return the length of the longest strictly increasing subsequence.

Intuition:
To find the length of the longest increasing subsequence, we can use dynamic programming.
The problem can be broken down into smaller subproblems by considering different subarrays.
We can build the solution by considering the length of the longest increasing subsequence ending at each position.

Approach:
1. Initialize an array dp of size n, where dp[i] represents the length of the longest increasing subsequence ending at index i.
2. Initialize dp[i] as 1 for all indices, as the minimum length of an increasing subsequence is 1 (the element itself).
3. Iterate through the array nums:
   - For each index i, iterate from 0 to i-1:
     - If nums[i] is greater than nums[j], update dp[i] as the maximum of dp[i] and dp[j] + 1.
       This means that we consider extending the increasing subsequence ending at index j with the current element at index i.
4. Return the maximum value in the dp array, which represents the length of the longest increasing subsequence.

Time Complexity:
The time complexity is O(n^2), where n is the size of the input array nums. We have nested loops to iterate through the array.

Space Complexity:
The space complexity is O(n) as we use an extra array dp of size n to store the lengths of the increasing subsequences.

Dynamic Programming:
- Subproblem: The subproblem is finding the length of the longest increasing subsequence ending at each position.
- Recurrence Relation: dp[i] = max(dp[i], dp[j] + 1) for 0 <= j < i, if nums[i] > nums[j].
- Base Case: Initialize dp[i] as 1 for all indices, as the minimum length of an increasing subsequence is 1.
*/

class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, 1);  // Length of longest increasing subsequence ending at each index

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

/**
 * ! Using Binary Search

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); // Length of the input vector
        vector<int> dp; // Stores the current increasing subsequence

        // Add the first element of nums to the subsequence vector
        dp.push_back(nums[0]);

        // Iterate through the remaining elements of nums
        for(int i = 1; i < n; i++) {
            // If the current element is greater than the last element in dp,
            // it can extend the current increasing subsequence, so add it to dp
            if(nums[i] > dp.back()) {
                dp.push_back(nums[i]);
            } else {
                // If the current element is not greater, find its correct position
                // in dp using binary search (lower_bound)
                auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
                // Update the value at the found position to nums[i]
                *it = nums[i];
            }
        }

        // Return the length of the longest increasing subsequence
        return dp.size();
    }
};
*/
