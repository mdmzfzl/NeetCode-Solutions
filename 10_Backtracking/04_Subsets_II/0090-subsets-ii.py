"""
Problem: LeetCode 90 - Subsets II

Key Idea:
To generate all possible subsets of a given list of integers, accounting for duplicates, we can use a backtracking approach. Similar to the previous subset problem, we explore all possible choices for each element: either include it in the current subset or exclude it. To handle duplicates, we skip adding the same element if it has already been processed at the same depth level.

Time Complexity:
- The total number of subsets is still 2^n, but the presence of duplicates may reduce the number of valid subsets. Therefore, the time complexity is O(2^n), as we need to generate all possible subsets.

Space Complexity:
- The space complexity is O(n), where n is the number of elements in the input list. This is due to the space required for the recursive call stack.
"""


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        def backtrack(start, subset):
            subsets.append(subset[:])  # Append a copy of the current subset

            for i in range(start, len(nums)):
                if i > start and nums[i] == nums[i - 1]:
                    continue  # Skip duplicates at the same depth level
                subset.append(nums[i])
                backtrack(i + 1, subset)
                subset.pop()  # Backtrack

        nums.sort()  # Sort the input to handle duplicates
        subsets = []
        backtrack(0, [])
        return subsets
