"""
Problem: LeetCode 269 - Alien Dictionary

Key Idea:
The problem can be solved using topological sorting. The given words can be thought of as directed edges between characters of adjacent words. We can build a graph where each character is a node, and the edges represent the order between characters. Then, we can perform topological sorting to find the correct order of characters.

Time Complexity:
- Building the graph takes O(N + E) time, where N is the number of words and E is the number of edges (character comparisons).
- Performing topological sorting takes O(V + E) time, where V is the number of characters and E is the number of edges.
- In the worst case, each character is compared with the next character in all words.
- Overall, the time complexity is O(N + E + V).

Space Complexity:
- The space required for the graph representation is O(V + E), where V is the number of characters and E is the number of edges.
- Other data structures used take constant space.
- Therefore, the space complexity is O(V + E).
"""

from collections import defaultdict, deque


class Solution:
    def alienOrder(self, words: List[str]) -> str:
        graph = defaultdict(list)
        in_degree = defaultdict(int)

        for i in range(len(words) - 1):
            word1, word2 = words[i], words[i + 1]
            for j in range(min(len(word1), len(word2))):
                if word1[j] != word2[j]:
                    graph[word1[j]].append(word2[j])
                    in_degree[word2[j]] += 1
                    break

        queue = deque(char for char, indeg in in_degree.items() if indeg == 0)
        result = []

        while queue:
            char = queue.popleft()
            result.append(char)
            for neighbor in graph[char]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    queue.append(neighbor)

        if len(result) < len(in_degree):
            return ""
        return "".join(result)
