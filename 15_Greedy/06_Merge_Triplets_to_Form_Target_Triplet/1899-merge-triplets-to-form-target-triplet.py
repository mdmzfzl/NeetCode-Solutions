"""
Problem: LeetCode 1899 - Merge Triplets to Form Target Triplet

Key Idea:
We can solve this problem by iterating through the triplets and checking if each triplet can contribute to forming the target triplet. The idea is to keep track of the maximum values encountered for each element in the triplet. At the end, if the maximum values for each element are greater than or equal to the corresponding values in the target triplet, then it's possible to form the target triplet.

Time Complexity:
- The time complexity of this approach is O(n), where n is the number of triplets.

Space Complexity:
- The space complexity is O(1), as we only use a constant amount of additional space for variables.
"""


class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        max_values = [0, 0, 0]

        for triplet in triplets:
            if (
                triplet[0] <= target[0]
                and triplet[1] <= target[1]
                and triplet[2] <= target[2]
            ):
                max_values = [max(max_values[i], triplet[i]) for i in range(3)]

        return max_values == target
