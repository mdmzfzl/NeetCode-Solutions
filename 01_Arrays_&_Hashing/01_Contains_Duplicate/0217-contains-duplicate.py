"""
Problem: LeetCode 217 - Contains Duplicate

Key Idea:
To check if there are any duplicates in the given list, we can use a hash set (set in Python) to store the unique elements as we traverse the list. For each element, we check if it is already present in the set. If it is, then we have found a duplicate, and we return True. If we traverse the entire list without finding any duplicates, we return False.

Time Complexity:
The time complexity of this approach is O(n), where n is the size of the input list. In the worst case, we might need to traverse the entire list once to find a duplicate.

Space Complexity:
The space complexity is O(n), as the hash set can potentially store all elements of the input list if they are all distinct.
"""


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        hashset = set()

        for n in nums:
            if n in hashset:
                return True
            hashset.add(n)
        return False
