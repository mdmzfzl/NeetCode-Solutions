/*
Problem: LeetCode 743 - Network Delay Time

Description:
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times
as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node,
and wi is the time it takes for a signal to travel from source to target.
We will send a signal from a given node k. Return the time it takes for all the n nodes to receive
the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Intuition:
This problem can be solved using Dijkstra's algorithm, which finds the shortest paths
from a source node to all other nodes in a weighted graph.

Approach:
1. Create a graph representation using an adjacency list, where graph[u] contains a list
   of pairs (v, w), representing an edge from node u to node v with weight w.
2. Use Dijkstra's algorithm to find the shortest path from the source node k to all other
   nodes in the graph.
3. Initialize a min heap (priority queue) to keep track of the nodes to visit, and set the
   distance of the source node k to 0 and distances of all other nodes to infinity.
4. Push the source node k into the min heap.
5. While the min heap is not empty, pop the node with the minimum distance from the heap.
6. For each neighbor of the current node, update the distance if a shorter path is found
   and push the neighbor into the min heap if it hasn't been visited yet.
7. After processing all nodes, the distance array will contain the shortest time to reach
   each node from the source node k. Return the maximum value in the distance array, which
   represents the time it takes for all nodes to receive the signal.
8. If there are nodes that cannot be reached from the source node k, the distance array
   will have some nodes with infinite distance. In this case, return -1.

Time Complexity:
The time complexity of Dijkstra's algorithm is O(E*logV), where E is the number of edges
and V is the number of vertices.

Space Complexity:
The space complexity is O(V+E), where V is the number of vertices and E is the number of edges,
due to the adjacency list representation of the graph.
*/

class Solution {
  public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        // Create a graph representation using an adjacency list
        unordered_map<int, vector<pair<int, int>>> graph;

        for (const auto &time : times) {
            graph[time[0]].push_back({time[1], time[2]});
        }

        // Initialize a min heap (priority queue) to track nodes to visit
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(n + 1, INT_MAX);
        // Set distance of source node k to 0 and push it into the min heap
        distance[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();

            // Check if the node has been visited already
            if (dist > distance[node]) {
                continue;
            }

            // Update the distances for neighbors
            for (const auto &neighbor : graph[node]) {
                int nextNode = neighbor.first;
                int newDist = dist + neighbor.second;

                if (newDist < distance[nextNode]) {
                    distance[nextNode] = newDist;
                    pq.push({newDist, nextNode});
                }
            }
        }

        // Find the maximum distance, which represents the time for all nodes to receive the signal
        int maxDist = 0;

        for (int i = 1; i <= n; ++i) {
            maxDist = max(maxDist, distance[i]);
        }

        // If some nodes cannot be reached, return -1
        return maxDist == INT_MAX ? -1 : maxDist;
    }
};
