"""
Problem: LeetCode 287 - Find the Duplicate Number

Key Idea:
To find the duplicate number in an array, we can treat the array as a linked list where each value points to the next value in the array. This problem is then reduced to finding the cycle in the linked list. We use the Floyd's Tortoise and Hare algorithm to detect the cycle. Once the cycle is detected, we find the entrance of the cycle, which represents the duplicate number.

Time Complexity:
The time complexity of this solution is O(n), where n is the number of elements in the array. The Floyd's Tortoise and Hare algorithm takes linear time to detect the cycle.

Space Complexity:
The space complexity is O(1), as no extra space is used other than a few variables to keep track of indices and values.
"""


class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow = nums[0]
        fast = nums[0]

        # Move slow and fast pointers
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break

        # Find the entrance of the cycle
        slow = nums[0]
        while slow != fast:
            slow = nums[slow]
            fast = nums[fast]

        return slow
