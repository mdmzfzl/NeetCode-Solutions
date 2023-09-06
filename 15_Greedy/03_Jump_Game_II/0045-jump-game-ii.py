"""
Problem: LeetCode 45 - Jump Game II

Key Idea:
We can solve this problem using a greedy approach. The idea is to keep track of the farthest reachable index and the current end of the interval. As we iterate through the array, we update the farthest reachable index based on the maximum jump length at the current index. When the current index reaches the end of the interval, we update the end of the interval to the farthest reachable index and increment the jump count. This ensures that we always make the jump with the maximum reach.

Time Complexity:
- The time complexity of this approach is O(n), where n is the length of the input array.

Space Complexity:
- The space complexity is O(1), as we only use a constant amount of additional space for variables.
"""


class Solution:
    def jump(self, nums: List[int]) -> int:
        jumps = 0
        cur_end = 0
        farthest_reachable = 0

        for i in range(len(nums) - 1):
            farthest_reachable = max(farthest_reachable, i + nums[i])
            if i == cur_end:
                jumps += 1
                cur_end = farthest_reachable

        return jumps
