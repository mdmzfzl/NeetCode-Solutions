"""
Problem: LeetCode 211 - Design Add and Search Words Data Structure

Key Idea:
To design a data structure that supports adding and searching words, we can use a Trie (prefix tree) with a special character '.' to represent any character. When searching, we traverse the Trie and recursively search in all child nodes for matching characters or '.'.

Time Complexity:
- Insertion: The time complexity of adding a word to the Trie is O(m), where m is the length of the word.
- Search: The time complexity of searching for a word in the Trie is O(m), where m is the length of the word.

Space Complexity:
- The space complexity of the Trie is O(n * m), where n is the number of words in the Trie and m is the average length of the words. This is due to the space required to store the Trie nodes and the characters in the words.
"""


class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False


class WordDictionary:
    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end = True

    def search(self, word: str) -> bool:
        def search_in_node(node, word):
            for i, char in enumerate(word):
                if char not in node.children:
                    if char == ".":
                        for child in node.children:
                            if search_in_node(node.children[child], word[i + 1 :]):
                                return True
                    return False
                else:
                    node = node.children[char]
            return node.is_end

        return search_in_node(self.root, word)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)

# class WordDictionary:

#     def __init__(self):
#         self.word_set = set()

#     def addWord(self, word: str) -> None:
#         self.word_set.add(word)
#         for i in range(len(word)):
#             # Add all possible variations with a '.' in each position
#             self.word_set.add(word[:i] + '.' + word[i + 1:])

#     def search(self, word: str) -> bool:
#         if word in self.word_set:
#             return True

#         # Check if the word contains a '.'
#         if '.' not in word:
#             return False

#         # Split the word into two parts at the first occurrence of '.'
#         first_part, rest_part = word.split('.', 1)

#         # Iterate over lowercase letters and create variations to search
#         for char in 'abcdefghijklmnopqrstuvwxyz':
#             new_word = first_part + char + rest_part
#             if new_word in self.word_set:
#                 return True

#         return False
