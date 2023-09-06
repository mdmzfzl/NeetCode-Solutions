"""
Problem: LeetCode 53 - Maximum Subarray

Key Idea:
We can solve this problem using the Kadane's algorithm. The idea is to iterate through the array and keep track of two variables: `max_sum` which stores the maximum sum ending at the current index, and `current_sum` which stores the maximum sum of subarray ending at the current index. For each element, we update `current_sum` by taking the maximum of the current element itself or adding it to the `current_sum` of the previous index. If `current_sum` becomes negative, we reset it to 0. Meanwhile, we update `max_sum` with the maximum of `max_sum` and `current_sum` at each step. After iterating through the entire array, `max_sum` will hold the maximum subarray sum.

Time Complexity:
- The time complexity of this approach is O(n), where n is the length of the input array.

Space Complexity:
- The space complexity is O(1), as we only use a constant amount of additional space for variables.
"""


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = float("-inf")
        current_sum = 0

        for num in nums:
            current_sum = max(num, current_sum + num)
            max_sum = max(max_sum, current_sum)

        return max_sum
