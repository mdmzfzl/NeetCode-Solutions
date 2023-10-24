"""
Problem: LeetCode 153 - Find Minimum in Rotated Sorted Array

Key Idea:
The key idea is to perform binary search to find the minimum element in the rotated sorted array. We compare the middle element with its neighbors to determine if it is the minimum element. Depending on the comparison, we narrow down the search to the unsorted part of the array.

Time Complexity:
The time complexity of this solution is O(log n), where n is the number of elements in the input array. Binary search reduces the search space by half in each step.

Space Complexity:
The space complexity is O(1), as no extra space is used other than a few variables to keep track of indices and values.
"""


class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1

        while left < right:
            mid = left + (right - left) // 2

            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid

        return nums[left]
