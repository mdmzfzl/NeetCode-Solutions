"""
Problem: LeetCode 208 - Implement Trie (Prefix Tree)

Key Idea:
To implement a Trie (prefix tree), we create a TrieNode class that represents each node in the trie. Each node contains a dictionary that maps characters to child nodes. We start with an empty root node and add words by traversing the characters and creating nodes as needed.

Time Complexity:
- Insertion: The time complexity of inserting a word into the trie is O(m), where m is the length of the word.
- Search: The time complexity of searching for a word in the trie is O(m), where m is the length of the word.
- StartsWith: The time complexity of checking if there is any word in the trie that starts with a given prefix is O(m), where m is the length of the prefix.

Space Complexity:
- The space complexity of the trie is O(n * m), where n is the number of words in the trie and m is the average length of the words. This is due to the space required to store the trie nodes and the characters in the words.
"""


class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end = True

    def search(self, word: str) -> bool:
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]
        return node.is_end

    def startsWith(self, prefix: str) -> bool:
        node = self.root
        for char in prefix:
            if char not in node.children:
                return False
            node = node.children[char]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
