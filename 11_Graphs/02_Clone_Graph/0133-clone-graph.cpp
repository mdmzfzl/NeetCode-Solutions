/*
Problem: LeetCode 133 - Clone Graph

Description:
Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.
Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

Intuition:
To clone a graph, we can use a depth-first search (DFS) or breadth-first search (BFS) approach. The idea is to traverse the original graph and create a copy of each node and its neighbors. We can store the visited nodes in a map to ensure that we don't create duplicate copies.

Approach:
1. Define a helper function `cloneNode`:
   - Create a copy of the current node.
   - Iterate through the neighbors of the current node:
     - If a neighbor is not visited, recursively call `cloneNode` to create a copy of the neighbor and add it to the neighbors of the current node.
     - If a neighbor is already visited, add the corresponding copy from the map to the neighbors of the current node.
2. Create an empty map to store the copies of the nodes.
3. Call the `cloneNode` function with the given reference node.
4. Return the copy of the reference node.

Time Complexity:
The time complexity is O(V + E), where V is the number of nodes (vertices) and E is the number of edges in the graph. We visit each node and each edge once.

Space Complexity:
The space complexity is O(V), where V is the number of nodes (vertices) in the graph. This is the space used to store the copies of the nodes and the recursion stack.
*/

class Solution {
  public:
    Node *cloneGraph(Node *node) {
        if (node == nullptr) {
            return nullptr;
        }

        unordered_map<Node *, Node *> nodeMap; // Map to store copies of nodes
        return cloneNode(node, nodeMap);
    }

  private:
    Node *cloneNode(Node *node, unordered_map<Node *, Node *> &nodeMap) {
        // If a copy of the current node already exists, return it
        if (nodeMap.find(node) != nodeMap.end()) {
            return nodeMap[node];
        }

        Node *newNode = new Node(node->val);  // Create a new copy of the current node
        nodeMap[node] = newNode;  // Add the current node to the map

        // Recursively clone the neighbors of the current node
        for (Node *neighbor : node->neighbors) {
            newNode->neighbors.push_back(cloneNode(neighbor, nodeMap));
        }

        return newNode;
    }
};