/*
Problem: LeetCode 53 - Maximum Subarray

Description:
Given an integer array nums, find the contiguous subarray (containing at least one number)
which has the largest sum and return its sum.

Intuition:
To find the maximum subarray sum, we can use the Kadane's algorithm.
The idea is to keep track of the maximum sum ending at each position in the array.
At each index i, we calculate the maximum subarray sum that ends at i by considering
two cases:
1. Include the current element in the subarray (by adding it to the sum ending at i-1).
2. Start a new subarray at the current element (by taking the current element itself).

Approach:
1. Initialize two variables, max_sum and current_sum, to track the maximum sum overall
   and the maximum sum ending at the current index, respectively.
2. Iterate through the array.
3. At each index i, update the current_sum by taking the maximum of nums[i] and
   nums[i] + current_sum. This step implements the Kadane's algorithm.
4. Update the max_sum by taking the maximum of max_sum and current_sum.
5. After iterating through the array, max_sum will represent the maximum subarray sum.

Time Complexity:
The time complexity is O(n), where n is the size of the input array. We only iterate
through the array once.

Space Complexity:
The space complexity is O(1), as we use only a constant amount of extra space.
*/

class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int max_sum = nums[0]; // Initialize max_sum with the first element
        int current_sum = nums[0]; // Initialize current_sum with the first element

        for (int i = 1; i < nums.size(); i++) {
            // Calculate the maximum subarray sum ending at index i
            current_sum = max(nums[i], nums[i] + current_sum);
            // Update the overall maximum subarray sum
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};