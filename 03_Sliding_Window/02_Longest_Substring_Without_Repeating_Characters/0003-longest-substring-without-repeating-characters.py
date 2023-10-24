"""
Problem: LeetCode 3 - Longest Substring Without Repeating Characters

Key Idea:
To find the length of the longest substring without repeating characters in the input string 's', we can use the sliding window approach. We use two pointers, 'left' and 'right', to represent the current window. As we move the 'right' pointer to the right, we expand the window and add characters to a set to keep track of unique characters in the window. If we encounter a repeating character, we move the 'left' pointer to the right to shrink the window until the repeating character is no longer in the window. At each step, we update the maximum length of the window (i.e., the length of the longest substring without repeating characters).

Time Complexity:
The time complexity of this solution is O(n), where n is the length of the input string 's'. The sliding window approach iterates through the string once, and at each step, we perform constant-time operations to update the window and the maximum length.

Space Complexity:
The space complexity is O(k), where k is the number of unique characters in the input string 's'. In the worst case, the entire string can be composed of unique characters, so the set storing the characters in the window would have k elements.
"""


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left, right = 0, 0
        max_length = 0
        unique_chars = set()

        while right < len(s):
            if s[right] not in unique_chars:
                unique_chars.add(s[right])
                max_length = max(max_length, right - left + 1)
                right += 1
            else:
                unique_chars.remove(s[left])
                left += 1

        return max_length
