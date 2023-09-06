"""
Problem: LeetCode 133 - Clone Graph

Key Idea:
The problem is to clone an undirected graph. We can solve this using Depth-First Search (DFS) or Breadth-First Search (BFS). Here, I'm use DFS to traverse the original graph and create a new graph.

Time Complexity:
- In the worst case, we visit each node and each edge in the graph exactly once. Therefore, the time complexity is O(V + E), where V is the number of nodes (vertices) and E is the number of edges in the graph.

Space Complexity:
- The space complexity is O(V), where V is the number of nodes in the graph. This is the maximum space required for the recursive call stack during DFS traversal, as well as for the hash map used to store the cloned nodes.
"""

"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""


class Solution:
    def cloneGraph(self, node: "Node") -> "Node":
        if not node:
            return None

        visited = {}  # Dictionary to store the cloned nodes

        def dfs(original_node):
            if original_node in visited:
                return visited[original_node]

            new_node = Node(original_node.val)
            visited[original_node] = new_node

            for neighbor in original_node.neighbors:
                new_neighbor = dfs(neighbor)
                new_node.neighbors.append(new_neighbor)

            return new_node

        return dfs(node)
