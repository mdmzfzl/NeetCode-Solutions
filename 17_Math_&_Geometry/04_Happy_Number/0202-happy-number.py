"""
Problem: LeetCode 202 - Happy Number

Key Idea:
A number is a happy number if, after repeatedly replacing it with the sum of the square of its digits, the process eventually reaches 1. To determine if a number is a happy number, we can use Floyd's Cycle Detection Algorithm. We use two pointers: a slow pointer that advances one step at a time and a fast pointer that advances two steps at a time. If the fast pointer eventually reaches the slow pointer, we have a cycle, indicating that the number is not a happy number.

Time Complexity:
- The time complexity of the Floyd's Cycle Detection Algorithm is O(log n), where n is the input number.

Space Complexity:
- The space complexity is O(1), as we use a constant amount of space.
"""


class Solution:
    def isHappy(self, n: int) -> bool:
        def get_next(num):
            next_num = 0
            while num > 0:
                num, digit = divmod(num, 10)
                next_num += digit**2
            return next_num

        slow, fast = n, get_next(n)

        while fast != 1 and slow != fast:
            slow = get_next(slow)
            fast = get_next(get_next(fast))

        return fast == 1
