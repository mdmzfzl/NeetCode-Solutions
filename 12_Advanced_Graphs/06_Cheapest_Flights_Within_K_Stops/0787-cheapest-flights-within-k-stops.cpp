/*
Problem: LeetCode 787 - Cheapest Flights Within K Stops

Description:
There are n cities connected by m flights. Each flight starts from city u and arrives at city v with a price w.
Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Intuition:
This problem can be solved using Dijkstra's algorithm with some modifications. Instead of stopping at the destination city, we need to find the cheapest price to reach the destination city within k stops. Therefore, we will modify Dijkstra's algorithm to allow k stops.

Approach:
1. Create an adjacency list to represent the graph where the key is the source city, and the value is a list of pairs containing the destination city and the price of the flight.
2. Use priority queue to implement Dijkstra's algorithm.
3. Push the starting city "src" into the priority queue with cost 0 and stops 0.
4. While the priority queue is not empty, do the following:
   - Pop the top element from the priority queue.
   - If the popped element is the destination city "dst", return the cost as the answer.
   - If the number of stops is less than or equal to "k", then iterate through the neighbors of the current city, and push them into the priority queue with updated cost and stops.
5. If we reach this point, it means there is no valid route, so return -1.

Time Complexity:
The time complexity of the Dijkstra's algorithm is O((E + V) * log(V)), where E is the number of flights and V is the number of cities. In the worst case, we can have E = V^2, so the time complexity is O((V^2) * log(V)).

Space Complexity:
The space complexity is O(E + V), where E is the number of flights and V is the number of cities. We use an adjacency list to represent the graph.
*/

class Solution {
  public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> adjList(n);

        for (const auto &flight : flights) {
            adjList[flight[0]].emplace_back(flight[1], flight[2]);
        }

        // Initialize the cheapestCost vector with (n x K+1) dimensions and set all values to infinity
        vector<vector<int>> cheapestCost(n, vector<int>(K + 2, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});
        cheapestCost[src][0] = 0; // Cost to reach source with 0 stops is 0

        while (!pq.empty()) {
            vector<int> cur = pq.top();
            pq.pop();
            int cost = cur[0];
            int city = cur[1];
            int stops = cur[2];

            if (city == dst) {
                return cost;
            }

            if (stops <= K) {
                for (const auto &neighbor : adjList[city]) {
                    int neighborCity = neighbor.first;
                    int neighborCost = neighbor.second;

                    // Prune if the cost exceeds the current minimum cost
                    if (cost + neighborCost >= cheapestCost[neighborCity][stops + 1]) {
                        continue;
                    }

                    pq.push({cost + neighborCost, neighborCity, stops + 1});
                    cheapestCost[neighborCity][stops + 1] = cost + neighborCost;
                }
            }
        }

        return -1;
    }
};

/*
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create an adjacency list to represent the graph
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        // Create a cost array to store the minimum cost to reach each node
        vector<int> cost(n, 1e9);
        queue<vector<int>> q; // Each entry contains: {stops, node, cost}

        cost[src] = 0; // Initialize the cost to reach the source node as 0
        q.push({0, src, 0}); // Push the source node with 0 stops and cost 0 into the queue

        while (!q.empty()) {
            auto v = q.front();
            q.pop();

            // If the number of stops exceeds k, skip this node
            if (v[0] > k) {
                continue;
            }

            for (auto it : adj[v[1]]) {
                int nbr = it.first; // Neighbor node
                int cst = it.second; // Cost to reach the neighbor node

                // If the new cost is less than the current recorded cost to reach the neighbor
                if (v[2] + cst < cost[nbr]) {
                    cost[nbr] = v[2] + cst; // Update the minimum cost to reach the neighbor
                    q.push({v[0] + 1, nbr, cost[nbr]}); // Push the neighbor with the updated cost and one more stop into the queue
                }
            }
        }

        // If the cost to reach the destination is not infinity, return the cost
        if (cost[dst] != 1e9) {
            return cost[dst];
        }

        // Otherwise, return -1 (destination is not reachable)
        return -1;
    }
};
*/