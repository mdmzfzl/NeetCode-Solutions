"""
Problem: LeetCode 78 - Subsets

Key Idea:
To generate all possible subsets of a given set of distinct integers, we can use a recursive approach. For each element, we have two choices: either include it in the current subset or exclude it. We explore both choices recursively to generate all subsets.

Time Complexity:
- The total number of subsets is 2^n, where n is the number of elements in the input set. Therefore, the time complexity is O(2^n), as we need to generate all possible subsets.

Space Complexity:
- The space complexity is O(n), where n is the number of elements in the input set. This is due to the space required for the recursive call stack.
"""


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def backtrack(start, subset):
            subsets.append(subset[:])  # Append a copy of the current subset

            for i in range(start, len(nums)):
                subset.append(nums[i])
                backtrack(i + 1, subset)
                subset.pop()  # Backtrack

        subsets = []
        backtrack(0, [])
        return subsets
