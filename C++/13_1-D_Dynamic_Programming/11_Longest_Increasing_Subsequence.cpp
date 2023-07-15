/*
Problem: LeetCode 300 - Longest Increasing Subsequence

Description:
Given an integer array nums, return the length of the longest strictly increasing subsequence.

Approach:
1. Initialize a vector dp of size nums.size() and set all values to 1.
   dp[i] will store the length of the longest increasing subsequence ending at index i.
2. Iterate through each index i in the range [1, nums.size()):
    a. For each index j in the range [0, i):
        - If nums[i] is greater than nums[j], update dp[i] to the maximum of dp[i] and dp[j] + 1.
          This means that if nums[i] can extend the increasing subsequence ending at index j,
          we update the length of the increasing subsequence ending at index i.
3. Return the maximum element from the dp vector, which represents the length of the longest increasing subsequence.

Recurrence Relation:
dp[i] = max(dp[i], dp[j] + 1) for j in [0, i) if nums[i] > nums[j]

Base Case:
The base case is dp[i] = 1 for all i in the range [0, nums.size())

Time Complexity:
The time complexity of this approach is O(n^2), where n is the size of the input array nums.
This is because we have nested loops to compare each pair of elements in the array.

Space Complexity:
The space complexity is O(n), as we are using an additional vector dp of size nums.size() to store the lengths.

Let's implement the solution!
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxLen = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
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
