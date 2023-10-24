"""
Problem: LeetCode 76 - Minimum Window Substring

Key Idea:
To find the minimum window in the input string 's' that contains all characters from another string 't', we can use the sliding window approach. We first create a frequency dictionary for characters in 't'. Then, we initialize two pointers, 'left' and 'right', to represent the current window in 's'. As we move the 'right' pointer to the right, we add the character to a temporary frequency dictionary and check if it contains all characters from 't'. If it does, it means we found a valid window containing all characters from 't'. We update the minimum window length and move the 'left' pointer to the right to shrink the window. We continue this process until we find the minimum window or reach the end of 's'.

Time Complexity:
The time complexity of this solution is O(n), where n is the length of 's'. The sliding window approach iterates through 's' once, and at each step, we perform constant-time operations to update the window and the frequency dictionaries.

Space Complexity:
The space complexity is O(k), where k is the number of unique characters in 't'. In the worst case, the frequency dictionaries can have k elements, one for each unique character in 't'.
"""


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t:
            return ""

        char_freq_t = {}
        for char in t:
            char_freq_t[char] = char_freq_t.get(char, 0) + 1

        left, right = 0, 0
        char_freq_temp = {}
        required_chars = len(char_freq_t)
        formed_chars = 0
        min_length = float("inf")
        min_window = ""

        while right < len(s):
            char_freq_temp[s[right]] = char_freq_temp.get(s[right], 0) + 1

            if (
                s[right] in char_freq_t
                and char_freq_temp[s[right]] == char_freq_t[s[right]]
            ):
                formed_chars += 1

            while left <= right and formed_chars == required_chars:
                if right - left + 1 < min_length:
                    min_length = right - left + 1
                    min_window = s[left : right + 1]

                char_freq_temp[s[left]] -= 1
                if (
                    s[left] in char_freq_t
                    and char_freq_temp[s[left]] < char_freq_t[s[left]]
                ):
                    formed_chars -= 1

                left += 1

            right += 1

        return min_window
