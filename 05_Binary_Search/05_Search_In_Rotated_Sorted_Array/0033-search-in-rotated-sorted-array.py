"""
Problem: LeetCode 33 - Search in Rotated Sorted Array

Key Idea:
The key idea is to perform binary search to find the target element in the rotated sorted array. We compare the middle element with the target and the endpoints of the subarray to determine which part of the array is sorted. Depending on the comparison, we narrow down the search to the sorted part of the array.

Time Complexity:
The time complexity of this solution is O(log n), where n is the number of elements in the input array. Binary search reduces the search space by half in each step.

Space Complexity:
The space complexity is O(1), as no extra space is used other than a few variables to keep track of indices and values.
"""


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1

        while left <= right:
            mid = left + (right - left) // 2

            if nums[mid] == target:
                return mid

            if nums[left] <= nums[mid]:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1

        return -1
