"""
Problem: LeetCode 49 - Group Anagrams

Key Idea:
To group anagrams together, we can use a hash map (dictionary in Python) where the key is a sorted version of each word, and the value is a list of words that are anagrams of each other. By iterating through the list of words, we can group them into the hash map based on their sorted versions.

Time Complexity:
The time complexity of this approach depends on the number of words (n) and the maximum length of a word (m). Sorting each word takes O(m*log(m)) time, and we do this for n words. Therefore, the overall time complexity is O(n * m * log(m)).

Space Complexity:
The space complexity is O(n * m), where n is the number of words, and m is the maximum length of a word. In the worst case, all words are unique, and the hash map will contain n entries, each with a list of words of length m.
"""


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams_map = {}

        for word in strs:
            sorted_word = "".join(sorted(word))
            if sorted_word in anagrams_map:
                anagrams_map[sorted_word].append(word)
            else:
                anagrams_map[sorted_word] = [word]

        return list(anagrams_map.values())
