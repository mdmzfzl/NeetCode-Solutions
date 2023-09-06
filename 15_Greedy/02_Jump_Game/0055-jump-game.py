"""
Problem: LeetCode 55 - Jump Game

Key Idea:
We can solve this problem using a greedy approach. The idea is to keep track of the maximum reachable index as we iterate through the array. At each index, we update the maximum reachable index by taking the maximum of the current index plus the value at that index (which represents the maximum jump length) and the previous maximum reachable index. If the maximum reachable index surpasses or equals the last index, we know it's possible to reach the end.

Time Complexity:
- The time complexity of this approach is O(n), where n is the length of the input array.

Space Complexity:
- The space complexity is O(1), as we only use a constant amount of additional space for variables.
"""


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_reachable = 0

        for i, jump_length in enumerate(nums):
            if i > max_reachable:
                return False
            max_reachable = max(max_reachable, i + jump_length)

        return True
