/*
Problem: LeetCode 261 - Graph Valid Tree

Description:
You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.
Return true if the edges of the given graph make up a valid tree, and false otherwise.

Intuition:
A valid tree is a connected graph with no cycles. To determine if the given graph is a valid tree, we can perform a depth-first search (DFS) or breadth-first search (BFS) traversal and check if there are any cycles and if all the nodes are reachable from a single source node.

Approach:
1. Build an adjacency list representation of the graph using the given edges.
2. Initialize a visited array to track the visited nodes during the graph traversal.
3. Perform a DFS or BFS traversal from any node in the graph:
   - Mark the current node as visited.
   - Visit all the neighbors of the current node:
     - If a neighbor is already visited and not the parent of the current node, it means there is a cycle, so return false.
     - If a neighbor is not visited, perform a recursive DFS or enqueue it in the BFS queue.
4. After the traversal, check if all the nodes are visited. If not, return false.
5. Return true if no cycle is found and all nodes are visited.

Time Complexity:
The time complexity depends on the graph traversal algorithm used. Using DFS or BFS, the time complexity is O(V + E), where V is the number of nodes (vertices) and E is the number of edges. We visit each node and edge once.

Space Complexity:
The space complexity is O(V + E), where V is the number of nodes (vertices) and E is the number of edges. This is the space used for the adjacency list and the visited array.
*/

class Solution {
  public:
    bool validTree(int n, vector<vector<int>> &edges) {
        vector<vector<int>> graph(n);   // Adjacency list representation of the graph
        vector<int> visited(n, 0);      // Visited array to track the visited nodes

        // Build the graph
        for (const auto &edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }

        // Perform graph traversal to check for cycles and reachability
        if (!dfs(0, -1, graph, visited)) {
            return false;
        }

        // Check if all nodes are visited
        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                return false;
            }
        }

        return true;
    }

  private:
    bool dfs(int node, int parent, vector<vector<int>> &graph, vector<int> &visited) {
        visited[node] = 1;  // Mark the current node as visited

        // Perform DFS traversal on the neighbors
        for (int neighbor : graph[node]) {
            if (visited[neighbor] == 0) {
                if (!dfs(neighbor, node, graph, visited)) {
                    return false;
                }
            } else if (neighbor != parent) {
                return false;
            }
        }

        return true;
    }
};