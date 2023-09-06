"""
Problem: LeetCode 127 - Word Ladder

Key Idea:
This problem can be solved using a breadth-first search (BFS) approach. We start with the given beginWord and perform a BFS to explore all possible word transformations, one character change at a time. We maintain a queue to track the current word and its transformation path. For each word in the queue, we generate all possible words by changing one character at a time and check if it's in the word list. If it is, we add it to the queue and mark it as visited. We continue this process until we reach the endWord or the queue is empty.

Time Complexity:
- Constructing the set of words takes O(wordList) time.
- Performing the BFS can take up to O(n * m) time, where n is the number of words and m is the length of the words.
- Therefore, the total time complexity is O(n * m).

Space Complexity:
- The space complexity is O(n), where we store the word list and the visited set.
- The queue can temporarily hold up to O(n) elements in the worst case.
"""

from collections import deque


class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordSet = set(wordList)
        if endWord not in wordSet:
            return 0

        queue = deque([(beginWord, 1)])  # Start from the beginWord with level 1
        visited = set()

        while queue:
            word, level = queue.popleft()
            if word == endWord:
                return level

            for i in range(len(word)):
                for c in "abcdefghijklmnopqrstuvwxyz":
                    new_word = word[:i] + c + word[i + 1 :]
                    if new_word in wordSet and new_word not in visited:
                        visited.add(new_word)
                        queue.append((new_word, level + 1))

        return 0
