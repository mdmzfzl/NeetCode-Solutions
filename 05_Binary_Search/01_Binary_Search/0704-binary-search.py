"""
Problem: LeetCode 704 - Binary Search

Key Idea:
Binary search is an efficient technique to search for a target element in a sorted array. In each step, we compare the middle element of the array with the target. If the middle element is equal to the target, we have found the element and return its index. If the middle element is greater than the target, we narrow down the search to the left half of the array. If the middle element is smaller, we narrow down the search to the right half of the array. We repeat this process until we find the target element or the search space is exhausted.

Time Complexity:
The time complexity of binary search is O(log n), where n is the number of elements in the sorted array. In each step, we reduce the search space by half, which leads to a logarithmic number of steps.

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
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        return -1
