"""
Problem: LeetCode 567 - Permutation in String

Key Idea:
To check whether a string 's2' contains a permutation of another string 's1', we can use a sliding window approach. First, we create a frequency dictionary for characters in 's1'. Then, we initialize two pointers, 'left' and 'right', to represent the current window in 's2'. As we move the 'right' pointer to the right, we add the character to a temporary frequency dictionary and check if it becomes equal to the frequency dictionary of 's1'. If it does, it means we found a permutation of 's1' in 's2', and we return True. If the window size exceeds the length of 's1', we remove the character at the 'left' pointer from the temporary dictionary and move the 'left' pointer to the right to shrink the window. We continue this process until we find a permutation or reach the end of 's2'.

Time Complexity:
The time complexity of this solution is O(n), where n is the length of 's2'. The sliding window approach iterates through 's2' once, and at each step, we perform constant-time operations to update the window and the frequency dictionaries.

Space Complexity:
The space complexity is O(1) since the frequency dictionaries have a constant number of elements (the number of unique characters in 's1' or the alphabet size) regardless of the size of the input strings 's1' and 's2'.
"""


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        char_freq_s1 = {}
        for char in s1:
            char_freq_s1[char] = char_freq_s1.get(char, 0) + 1

        left, right = 0, 0
        char_freq_temp = {}

        while right < len(s2):
            char_freq_temp[s2[right]] = char_freq_temp.get(s2[right], 0) + 1

            if right - left + 1 == len(s1):
                if char_freq_temp == char_freq_s1:
                    return True
                char_freq_temp[s2[left]] -= 1
                if char_freq_temp[s2[left]] == 0:
                    del char_freq_temp[s2[left]]
                left += 1

            right += 1

        return False
