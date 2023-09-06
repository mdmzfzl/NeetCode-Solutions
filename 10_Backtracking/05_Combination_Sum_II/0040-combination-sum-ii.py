"""
Problem: LeetCode 40 -  Combination Sum II

Key Idea:
To find all unique combinations that sum up to a target value, accounting for duplicates, we can use a backtracking approach. Starting from each candidate element, we explore all possible combinations by adding the element to the current combination and recursively searching for the remaining sum. To handle duplicates, we skip adding the same element if it has already been processed at the same depth level.

Time Complexity:
- The total number of subsets is still 2^n, but the presence of duplicates may reduce the number of valid subsets. Therefore, the time complexity is O(2^n), as we need to generate all possible subsets.

Space Complexity:
- The space complexity is O(target), as the recursive call stack can go up to the target value.
"""


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def backtrack(start, target, combination):
            if target == 0:
                result.append(
                    combination[:]
                )  # Append a copy of the current combination
                return

            for i in range(start, len(candidates)):
                if i > start and candidates[i] == candidates[i - 1]:
                    continue  # Skip duplicates at the same depth level

                if candidates[i] > target:
                    continue  # Skip if the candidate is too large

                combination.append(candidates[i])
                backtrack(i + 1, target - candidates[i], combination)
                combination.pop()  # Backtrack

        candidates.sort()  # Sort the input to handle duplicates
        result = []
        backtrack(0, target, [])
        return result
