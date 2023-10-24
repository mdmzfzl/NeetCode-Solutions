/*
Problem: LeetCode 684 - Redundant Connection

Description:
In this problem, a tree is an undirected graph that is connected and has no cycles.
You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

Intuition:
The problem is asking to find the redundant connection, which is the edge that creates a cycle in the given graph. We can solve this problem using a Union-Find algorithm.

Approach:
1. Create a parent array of size n+1 to represent each node's parent.
2. Iterate through the edges:
   - Initialize variables to store the parent of each node in the current edge.
   - If the parent of both nodes is the same, it means adding this edge will create a cycle, so return the current edge.
   - Otherwise, union the nodes by setting the parent of one node to be the parent of the other node.
3. If no redundant edge is found, return an empty vector.

Time Complexity:
The time complexity is O(n * α(n)), where n is the number of nodes and α(n) is the inverse Ackermann function. In practice, α(n) is a very slow-growing function and can be considered constant. Thus, the time complexity is effectively O(n).

Space Complexity:
The space complexity is O(n), where n is the number of nodes. This is the space used for the parent array.
*/

class Solution {
  public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n = edges.size();
        vector<int> parent(n + 1);

        // Initialize the parent array
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }

        // Iterate through the edges
        for (const auto &edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            // Find the parent of each node in the current edge
            int parent1 = findParent(parent, node1);
            int parent2 = findParent(parent, node2);

            // If both nodes have the same parent, return the current edge
            if (parent1 == parent2) {
                return edge;
            }

            // Union the nodes
            parent[parent1] = parent2;
        }

        return {};
    }

  private:
    int findParent(vector<int> &parent, int node) {
        if (parent[node] != node) {
            parent[node] = findParent(parent, parent[node]);
        }

        return parent[node];
    }
};