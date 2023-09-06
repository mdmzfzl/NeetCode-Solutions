"""
Problem: LeetCode 46 - Permutations

Key Idea:
To generate all permutations of a given list of distinct integers, we can use a backtracking approach. Starting from each element, we explore all possible permutations by swapping the current element with other elements and recursively generating permutations for the remaining elements. Once we reach the end of the list, we add the current permutation to the result.

Time Complexity:
- The total number of permutations is n!, where n is the number of elements in the input list. Therefore, the time complexity is O(n!).

Space Complexity:
- The space complexity is O(n), where n is the number of elements in the input list. This is due to the space required for the recursive call stack.
"""


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def backtrack(start):
            if start == len(nums) - 1:
                permutations.append(nums[:])  # Append a copy of the current permutation

            for i in range(start, len(nums)):
                nums[start], nums[i] = nums[i], nums[start]  # Swap elements
                backtrack(start + 1)
                nums[start], nums[i] = nums[i], nums[start]  # Backtrack

        permutations = []
        backtrack(0)
        return permutations
