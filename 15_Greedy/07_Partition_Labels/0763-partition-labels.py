"""
Problem: LeetCode 763 - Partition Labels
 
Key Idea:
We can solve this problem using a greedy approach. The idea is to traverse the string and keep track of the last index at which each character appears. While traversing, we maintain a current partition's start and end indices. When the current index reaches the end index of the current partition, we add the length of the partition to the result list and update the start index for the next partition.

Time Complexity:
- The time complexity of this approach is O(n), where n is the length of the input string.

Space Complexity:
- The space complexity is O(1), as the result list is the only additional space used.
"""


class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        last_index = {}

        for i, char in enumerate(s):
            last_index[char] = i

        result = []
        start, end = 0, 0

        for i, char in enumerate(s):
            end = max(end, last_index[char])

            if i == end:
                result.append(end - start + 1)
                start = end + 1

        return result
