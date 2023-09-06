"""
Problem: LeetCode 261 - Graph Valid Tree

Key Idea:
This problem can be solved using Depth-First Search (DFS) or Union-Find algorithm. We represent the given edges as an adjacency list, where each node points to its neighboring nodes. To determine whether the graph is a valid tree, we need to check two conditions:
1. The graph must be connected, i.e., there is a path between every pair of nodes.
2. There should be no cycles in the graph.

Time Complexity:
- Constructing the adjacency list takes O(n + m) time, where n is the number of nodes and m is the number of edges.
- Both DFS and Union-Find algorithms take O(n) time.
- Therefore, the total time complexity is O(n + m).

Space Complexity:
- The space complexity is O(n + m) to store the adjacency list and Union-Find data structures.
"""


class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) != n - 1:
            return False

        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        visited = set()

        def dfs(node, parent):
            visited.add(node)
            for neighbor in graph[node]:
                if neighbor != parent:
                    if neighbor in visited or not dfs(neighbor, node):
                        return False
            return True

        # Check if the graph is connected
        if not dfs(0, -1):
            return False

        return len(visited) == n
