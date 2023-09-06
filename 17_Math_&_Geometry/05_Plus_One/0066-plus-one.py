"""
Problem: LeetCode 66 - Plus One

Key Idea:
Given a non-empty array representing a non-negative integer, we need to add one to the integer. We can perform this addition by starting from the least significant digit (the last element of the array) and moving towards the most significant digit. If the current digit is less than 9, we can simply increment it and return the modified array. Otherwise, we set the current digit to 0 and continue the process with the previous digit.

Time Complexity:
- The time complexity is O(n), where n is the length of the input array.

Space Complexity:
- The space complexity is O(1), as we perform the addition in-place without using any additional space.
"""


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)

        for i in range(n - 1, -1, -1):
            if digits[i] < 9:
                digits[i] += 1
                return digits
            digits[i] = 0

        return [1] + digits
