"""
Problem: LeetCode 131 - Palindrome Partitioning

Key Idea:
To partition a given string into palindromic substrings, we can use backtracking. Starting from each position in the string, we check if the substring from that position to the end is a palindrome. If it is, we recursively partition the remaining substring and continue the process. We keep track of the current partition in a list and store valid partitions in the result.

Time Complexity:
- In the worst case, for each position in the string, we recursively generate all possible partitions. Therefore, the time complexity is O(2^n), where n is the length of the string.

Space Complexity:
- The space complexity is O(n), where n is the length of the string. This is due to the space required for the recursive call stack and the space for storing the current partition.
"""


class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def is_palindrome(sub):
            return sub == sub[::-1]

        def backtrack(start, partition):
            if start == len(s):
                result.append(partition[:])  # Append a copy of the current partition
                return

            for end in range(start + 1, len(s) + 1):
                sub = s[start:end]
                if is_palindrome(sub):
                    partition.append(sub)
                    backtrack(end, partition)
                    partition.pop()  # Backtrack

        result = []
        backtrack(0, [])
        return result
