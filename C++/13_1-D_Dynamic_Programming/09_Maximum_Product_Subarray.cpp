/*
Problem: LeetCode 152 - Maximum Product Subarray

Description:
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product,
and return the product.

Approach:
1. Initialize variables maxProduct and minProduct to track the maximum and minimum products ending at the current index.
2. Initialize a variable answer to store the final result.
3. Iterate through each element in the array:
    a. If the current element is negative, swap the values of maxProduct and minProduct.
       This is because multiplying by a negative number can change the maximum product to the minimum product.
    b. Update maxProduct by taking the maximum of the current element and the product of the current element and the previous maxProduct.
    c. Update minProduct by taking the minimum of the current element and the product of the current element and the previous minProduct.
    d. Update the answer by taking the maximum of answer and maxProduct at each step.
4. Return the answer, which represents the maximum product of a subarray.

Time Complexity:
The time complexity of this approach is O(n), where n is the size of the input array nums, as we iterate through the array once.

Space Complexity:
The space complexity is O(1), as we only use a constant amount of extra space to store the variables maxProduct, minProduct, and answer.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        
        int maxProduct = 1;
        int minProduct = 1;
        int answer = 0;
        
        // Iterate through the array starting from the second element
        for (auto i: nums) {
            // If the current element is negative, swap maxProduct and minProduct
            if (i < 0) {
                swap(maxProduct, minProduct);
            }
            
            // Update maxProduct and minProduct
            maxProduct = max(i, maxProduct * i);
            minProduct = min(i, minProduct * i);
            
            answer = max(answer, maxProduct);
        }
        
        return answer;
    }
};

