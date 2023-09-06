"""
Problem: LeetCode 152 - Maximum Product Subarray

Key Idea:
The key idea is to use dynamic programming to keep track of the maximum and minimum product ending at each position in the array. Since multiplying a negative number by a negative number results in a positive number, we need to keep track of both the maximum and minimum products to handle negative numbers.

Time Complexity:
The time complexity is O(n), where 'n' is the length of the input array. We iterate through the array once to find the maximum product subarray.

Space Complexity:
The space complexity is O(1) because we use only a few variables to store the maximum and minimum products at each position.
"""


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # Initialize variables to keep track of the maximum and minimum product ending at the current position.
        max_product = min_product = result = nums[0]

        # Iterate through the array starting from the second element.
        for i in range(1, len(nums)):
            # If the current element is negative, swap max_product and min_product
            # because multiplying a negative number can turn the maximum into the minimum.
            if nums[i] < 0:
                max_product, min_product = min_product, max_product

            # Update max_product and min_product based on the current element.
            max_product = max(nums[i], max_product * nums[i])
            min_product = min(nums[i], min_product * nums[i])

            # Update the overall result with the maximum product found so far.
            result = max(result, max_product)

        return result
