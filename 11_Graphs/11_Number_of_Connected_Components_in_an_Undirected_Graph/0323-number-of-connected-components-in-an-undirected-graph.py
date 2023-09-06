"""
Problem: LeetCode 323 - Number of Connected Components in an Undirected Graph

Key Idea:
This problem can be solved using Depth-First Search (DFS) or Breadth-First Search (BFS). We represent the given edges as an adjacency list, where each node points to its neighboring nodes. We then iterate through all nodes and perform a DFS/BFS from each unvisited node to explore all connected components. The number of times we need to start a new DFS/BFS corresponds to the number of connected components in the graph.

Time Complexity:
- Constructing the adjacency list takes O(n + m) time, where n is the number of nodes and m is the number of edges.
- Performing DFS/BFS for each unvisited node takes O(n + m) time.
- Therefore, the total time complexity is O(n + m).

Space Complexity:
- The space complexity is O(n + m) to store the adjacency list and visited set.
"""

from collections import defaultdict, deque


class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        def dfs(node):
            visited.add(node)
            for neighbor in graph[node]:
                if neighbor not in visited:
                    dfs(neighbor)

        visited = set()
        components = 0

        for node in range(n):
            if node not in visited:
                components += 1
                dfs(node)

        return components
