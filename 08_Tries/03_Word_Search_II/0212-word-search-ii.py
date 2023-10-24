"""
Problem: LeetCode 212 - Word Search II

Key Idea:
To find all the words from a given list that can be formed by a 2D board of characters, we can use a Trie (prefix tree) to efficiently search for words while traversing the board. We start by building a Trie from the given list of words. Then, we perform a depth-first search (DFS) on the board, checking if the current path forms a valid prefix in the Trie. If it does, we continue the DFS until we find words or reach dead ends.

Time Complexity:
- Building Trie: The time complexity of building the Trie is O(n * m), where n is the number of words in the list and m is the average length of the words.
- DFS: The time complexity of the DFS traversal on the board is O(n * m * 4^k), where n and m are the dimensions of the board and k is the maximum length of the words.

Space Complexity:
- The space complexity of the Trie is O(n * m), where n is the number of words in the list and m is the average length of the words.
- The space complexity of the DFS recursion stack is O(n * m) as well, due to the potential depth of the recursion.
"""

from collections import Counter
from itertools import chain, product
from typing import List


class TrieNode:
    def __init__(self):
        self.children = {}  # Store child nodes for each character
        self.refcnt = 0  # Count of references to this node
        self.is_word = False  # Flag to indicate if a complete word ends at this node
        self.is_rev = False  # Flag to indicate if a word should be reversed


class Trie:
    def __init__(self):
        self.root = TrieNode()  # Initialize the root of the trie

    def insert(self, word, rev):
        node = self.root
        for c in word:
            node = node.children.setdefault(c, TrieNode())
            node.refcnt += 1
        node.is_word = True
        node.is_rev = rev

    def remove(self, word):
        node = self.root
        for i, c in enumerate(word):
            parent = node
            node = node.children[c]

            if node.refcnt == 1:
                path = [(parent, c)]
                for c in word[i + 1 :]:
                    path.append((node, c))
                    node = node.children[c]
                for parent, c in path:
                    parent.children.pop(c)
                return
            node.refcnt -= 1
        node.is_word = False


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        res = []
        n, m = len(board), len(board[0])
        trie = Trie()

        # Count characters on the board
        boardcnt = Counter(chain(*board))

        # Insert words into trie with appropriate orientation
        for w, wrdcnt in ((w, Counter(w)) for w in words):
            if any(wrdcnt[c] > boardcnt[c] for c in wrdcnt):
                continue  # Skip if the word cannot be formed from the board
            if wrdcnt[w[0]] < wrdcnt[w[-1]]:
                trie.insert(w, False)
            else:
                trie.insert(w[::-1], True)

        def dfs(r, c, parent) -> None:
            if not (node := parent.children.get(board[r][c])):
                return
            path.append(board[r][c])
            board[r][c] = "#"  # Mark visited cell

            if node.is_word:
                word = "".join(path)
                res.append(word[::-1] if node.is_rev else word)
                trie.remove(word)

            # Explore neighboring cells
            if r > 0:
                dfs(r - 1, c, node)
            if r < n - 1:
                dfs(r + 1, c, node)
            if c > 0:
                dfs(r, c - 1, node)
            if c < m - 1:
                dfs(r, c + 1, node)

            board[r][c] = path.pop()  # Backtrack and unmark cell

        path = []
        for r, c in product(range(n), range(m)):
            dfs(r, c, trie.root)
        return res
