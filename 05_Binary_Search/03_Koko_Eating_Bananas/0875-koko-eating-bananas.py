"""
Problem: LeetCode 875 - Koko Eating Bananas

Key Idea:
The key idea is to perform binary search to find the minimum value of the integer 'k' such that Koko can eat all the bananas within 'hours' hours. We can define a binary search space for 'k' and perform binary search to find the smallest 'k' that satisfies the given condition.

Time Complexity:
The time complexity of this solution is O(n * log(max_pile)), where n is the number of piles and max_pile is the maximum size of a pile. The binary search iterates log(max_pile) times, and for each iteration, we perform a linear search through 'piles' to calculate the total hours.

Space Complexity:
The space complexity is O(1), as no extra space is used other than a few variables to keep track of indices and values.
"""


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left, right = 1, max(piles)

        while left < right:
            mid = left + (right - left) // 2
            hours = sum((pile + mid - 1) // mid for pile in piles)

            if hours > h:
                left = mid + 1
            else:
                right = mid

        return left
