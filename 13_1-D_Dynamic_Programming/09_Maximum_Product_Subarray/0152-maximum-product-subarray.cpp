/*
Problem: LeetCode 152 - Maximum Product Subarray

Description:
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) that has the largest product.

Intuition:
To find the maximum product subarray, we can use dynamic programming.
The problem can be broken down into smaller subproblems by considering different subarrays.
We can build the solution by considering the maximum product of subarrays ending at each position.

Approach:
1. Initialize variables maxProduct, minProduct, and result to store the maximum product, minimum product, and final result, respectively.
2. Iterate through the array nums:
   - For each number, update maxProduct and minProduct:
     - maxProduct is the maximum of the current number, maxProduct * number, and minProduct * number.
     - minProduct is the minimum of the current number, maxProduct * number, and minProduct * number.
   - Update the result with the maximum of result and maxProduct.
3. Return the result, which represents the maximum product subarray.

Time Complexity:
The time complexity is O(n), where n is the size of the input array nums. We iterate through each element of the array once.

Space Complexity:
The space complexity is O(1) as we only need a few variables to store the intermediate results.

Dynamic Programming:
- Subproblem: The subproblem is finding the maximum product of subarrays ending at each position.
- Recurrence Relation:
    - maxProduct = max(nums[i], maxProduct * nums[i], minProduct * nums[i])
    - minProduct = min(nums[i], maxProduct * nums[i], minProduct * nums[i])
- Base Case: Initialize maxProduct and minProduct with the first element of the array.
*/

class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        int maxProduct = nums[0];  // Maximum product of subarrays ending at each position
        int minProduct = nums[0];  // Minimum product of subarrays ending at each position
        int result = nums[0];      // Final result

        for (int i = 1; i < n; i++) {
            // Update maxProduct and minProduct
            int tempMax = maxProduct;
            maxProduct = max({nums[i], maxProduct *nums[i], minProduct *nums[i]});
            minProduct = min({nums[i], tempMax *nums[i], minProduct *nums[i]});
            // Update the result
            result = max(result, maxProduct);
        }

        return result;
    }
};