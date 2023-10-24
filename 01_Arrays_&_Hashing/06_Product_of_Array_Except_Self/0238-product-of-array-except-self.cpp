/*
Problem: LeetCode 238 - Product of Array Except Self

Description:
Given an integer array nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Intuition:
To find the product of all elements except self, we can utilize prefix and suffix products. By calculating the prefix product from the left and the suffix product from the right, we can obtain the desired result efficiently.

Approach:
1. Initialize an output array of the same size as the input array nums.
2. Calculate the prefix product from the left side of the array and store it in the output array.
3. Calculate the suffix product from the right side of the array and multiply it with the corresponding element in the output array.
4. Return the resulting output array.

Time Complexity:
The time complexity of this approach is O(n), where n is the size of the input array nums.
This is because we iterate through the array twice, once for calculating the prefix product and once for calculating the suffix product.

Space Complexity:
The space complexity is O(1), as we are reusing the input array for storing the output.
*/

class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> output(n, 1);
        // Calculate prefix product
        int prefix = 1;

        for (int i = 0; i < n; i++) {
            output[i] *= prefix;
            prefix *= nums[i];
        }

        // Calculate suffix product and multiply with prefix product stored in the output array
        int suffix = 1;

        for (int i = n - 1; i >= 0; i--) {
            output[i] *= suffix;
            suffix *= nums[i];
        }

        return output;
    }
};

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> res(nums.size(), 1);
//         // First, compute the prefix product and store in res
//         // res[i] = product of elements in nums from index 0, 1, ... to i - 1
//         for (int i = 0; i < nums.size() - 1; i++) {
//             res[i+1] = nums[i] * res[i];
//         }
//         // Second, compute the final result
//         int suffixProduct = 1;
//         for(int j = nums.size()-1; j > 0; j--) {
//             suffixProduct *= nums[j];
//             res[j-1] *= suffixProduct;
//         }
//         return res;
//     }
// };