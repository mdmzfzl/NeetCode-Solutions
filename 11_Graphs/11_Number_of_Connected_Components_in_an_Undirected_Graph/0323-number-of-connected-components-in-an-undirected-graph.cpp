/*
Problem: LeetCode 323 - Number of Connected Components in an Undirected Graph

Description:
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Intuition:
This problem can be approached as a graph problem where the nodes represent the vertices and the edges represent the connections between the vertices. We can use depth-first search (DFS) or breadth-first search (BFS) to explore the graph and count the number of connected components.

Approach:
1. Build an adjacency list representation of the graph using the given edges.
2. Initialize a visited array to track the visited nodes during the graph traversal.
3. Initialize a count variable to keep track of the number of connected components.
4. Iterate through each node in the graph:
   - If the node is not visited, perform a DFS or BFS traversal from that node:
     - Increment the count by 1.
     - Mark all the connected nodes as visited.
5. Return the count, which represents the number of connected components.

Time Complexity:
The time complexity depends on the graph traversal algorithm used. Using DFS or BFS, the time complexity is O(V + E), where V is the number of nodes (vertices) and E is the number of edges. We visit each node and edge once.

Space Complexity:
The space complexity is O(V + E), where V is the number of nodes (vertices) and E is the number of edges. This is the space used for the adjacency list and the visited array.
*/

class Solution {
  public:
    int countComponents(int n, vector<vector<int>> &edges) {
        vector<vector<int>> graph(n);   // Adjacency list representation of the graph
        vector<int> visited(n, 0);      // Visited array to track the visited nodes
        int count = 0;                  // Number of connected components

        // Build the graph
        for (const auto &edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }

        // Perform graph traversal to count the connected components
        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                ++count;
                dfs(i, graph, visited);
                // Or use bfs(i, graph, visited) for BFS traversal
            }
        }

        return count;
    }

  private:
    void dfs(int node, vector<vector<int>> &graph, vector<int> &visited) {
        visited[node] = 1;  // Mark the current node as visited

        // Perform DFS traversal on the neighbors
        for (int neighbor : graph[node]) {
            if (visited[neighbor] == 0) {
                dfs(neighbor, graph, visited);
            }
        }
    }
};