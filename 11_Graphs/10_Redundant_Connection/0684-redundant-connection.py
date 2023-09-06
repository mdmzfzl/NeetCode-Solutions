"""
Problem: LeetCode 684 - Redundant Connection

Key Idea:
This problem can be solved using the Union-Find (Disjoint Set Union) algorithm. We initialize each node as its own parent and iterate through the given edges. For each edge, we check if the nodes have the same parent. If they do, that means adding this edge will create a cycle, and it's the redundant edge. If they don't have the same parent, we merge their sets by updating one's parent to be the other.

Time Complexity:
- Initializing the parent array takes O(n) time, where n is the number of nodes.
- Iterating through the edges takes O(n) time.
- The `find` and `union` operations in the Union-Find algorithm have an amortized time complexity of approximately O(1).
- Therefore, the total time complexity is O(n).

Space Complexity:
- The space complexity is O(n), where we store the parent array and the result array.
"""


class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        parent = list(range(n + 1))  # Initialize each node as its own parent

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])  # Path compression
            return parent[x]

        def union(x, y):
            parent[find(x)] = find(y)

        for edge in edges:
            u, v = edge
            if find(u) == find(v):
                return edge
            union(u, v)

        return []
