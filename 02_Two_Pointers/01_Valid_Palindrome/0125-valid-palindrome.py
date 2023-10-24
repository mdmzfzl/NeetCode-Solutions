"""
Problem: LeetCode 125 - Valid Palindrome

Key Idea:
To determine if a given string is a valid palindrome, we can use two pointers approach. We initialize two pointers, one at the beginning of the string (left) and the other at the end of the string (right). We then compare characters at these two pointers. If they are both alphanumeric characters and equal in value (ignoring case), we move both pointers towards the center of the string. If they are not equal, we know the string is not a palindrome. We continue this process until the two pointers meet or cross each other.

Time Complexity:
The time complexity of this solution is O(n), where n is the length of the input string 's'. In the worst case, we might need to traverse the entire string once to determine if it is a valid palindrome.

Space Complexity:
The space complexity is O(1) since we are not using any additional data structures that depend on the input size. We only use a constant amount of extra space for the two pointers and other variables.
"""


class Solution:
    def isPalindrome(self, s: str) -> bool:
        left, right = 0, len(s) - 1

        while left < right:
            while left < right and not s[left].isalnum():
                left += 1
            while left < right and not s[right].isalnum():
                right -= 1

            if s[left].lower() != s[right].lower():
                return False

            left += 1
            right -= 1

        return True
