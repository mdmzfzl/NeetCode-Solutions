"""
Problem: LeetCode 39 - Combination Sum

Key Idea:
To find all unique combinations that sum up to a target value, we can use a backtracking approach. Starting from each candidate element, we explore all possible combinations by adding the element to the current combination and recursively searching for the remaining sum. If the sum becomes equal to the target, we add the current combination to the result. This process is repeated for each candidate element.

Time Complexity:
- In the worst case, each candidate element can be used multiple times to reach the target sum. Therefore, the time complexity is O(k * 2^n), where k is the average number of times each element can be used and n is the number of candidate elements.

Space Complexity:
- The space complexity is O(target), as the recursive call stack can go up to the target value.
"""


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def backtrack(start, target, combination):
            if target == 0:
                result.append(
                    combination[:]
                )  # Append a copy of the current combination
                return

            for i in range(start, len(candidates)):
                if candidates[i] > target:
                    continue  # Skip if the candidate is too large

                combination.append(candidates[i])
                backtrack(i, target - candidates[i], combination)
                combination.pop()  # Backtrack

        result = []
        backtrack(0, target, [])
        return result
