"""
Problem: LeetCode 20 - Valid Parentheses

Key Idea:
To determine if a given string of parentheses 's' is valid, we can use a stack data structure. We iterate through each character in 's', and if the character is an opening parenthesis ('(', '{', '['), we push it onto the stack. If the character is a closing parenthesis (')', '}', ']'), we check if the stack is empty or if the top element of the stack does not match the current closing parenthesis. If either of these conditions is met, we know the string is not valid. Otherwise, we pop the top element from the stack. At the end, if the stack is empty, the string is valid.

Time Complexity:
The time complexity of this solution is O(n), where n is the length of the input string 's'. We iterate through the string once, and each operation (pushing or popping from the stack) takes constant time.

Space Complexity:
The space complexity is O(n), where n is the length of the input string 's'. In the worst case, the stack could store all characters of the input string.
"""


class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        parentheses_map = {")": "(", "}": "{", "]": "["}

        for char in s:
            if char in parentheses_map.values():
                stack.append(char)
            elif char in parentheses_map:
                if not stack or stack[-1] != parentheses_map[char]:
                    return False
                stack.pop()
            else:
                return False

        return not stack
