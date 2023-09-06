"""
Problem: LeetCode 242 - Valid Anagram 

Key Idea:
To determine if two given strings are anagrams of each other, we can compare their character frequencies. An anagram of a string contains the same characters with the same frequency, just arranged differently. We can use a hash map (dictionary in Python) to keep track of the character frequencies for each string. If the character frequencies of both strings match, then they are anagrams.

Time Complexity:
The time complexity of this approach is O(n), where n is the length of the input strings. We need to traverse both strings once to build the character frequency maps.

Space Complexity:
The space complexity is O(1) because the hash map will have at most 26 entries (one for each lowercase English letter) regardless of the input string lengths. Therefore, the space complexity is constant.
"""


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        char_frequency = {}

        # Build character frequency map for string s
        for char in s:
            char_frequency[char] = char_frequency.get(char, 0) + 1

        # Compare with string t
        for char in t:
            if char not in char_frequency or char_frequency[char] == 0:
                return False
            char_frequency[char] -= 1

        return True
