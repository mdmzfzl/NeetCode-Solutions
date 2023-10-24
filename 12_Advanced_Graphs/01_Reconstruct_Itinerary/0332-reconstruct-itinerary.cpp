/*
Problem: LeetCode 332 - Reconstruct Itinerary

Description:
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order.
All of the tickets belong to a man who departs from "JFK", thus the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

Intuition:
To reconstruct the itinerary, we need to find a valid sequence of flights that starts from "JFK" and covers all the tickets. We can approach this problem as a graph traversal, where each airport is a node, and each ticket is an edge from one airport to another.

Approach:
1. Create a graph representation using a hashmap, where the key is the departure airport, and the value is a list of arrival airports. The list should be sorted in lexical order to find the smallest lexical order itinerary.
2. Perform a Depth-First Search (DFS) traversal on the graph, starting from the "JFK" airport.
3. During the DFS, for each airport visited, remove the used ticket (edge) from the graph to avoid using it again.
4. Continue the DFS until all the tickets are used up, and we have a valid itinerary.

Time Complexity:
The time complexity of the DFS approach is O(E * log E), where E is the total number of tickets. Sorting the list of arrival airports for each departure airport takes O(log E) time.

Space Complexity:
The space complexity is O(E), where E is the total number of tickets. We use a hashmap to represent the graph, which can contain E entries.
*/

class Solution {
  public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        // Create a graph representation using hashmap
        unordered_map<string, multiset<string>> graph;

        for (const auto &ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }

        vector<string> itinerary;
        dfs("JFK", graph, itinerary);
        // Reverse the itinerary to get the correct order
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }

    void dfs(string airport, unordered_map<string, multiset<string>> &graph, vector<string> &itinerary) {
        while (!graph[airport].empty()) {
            string nextAirport = *graph[airport].begin();
            graph[airport].erase(graph[airport].begin());
            dfs(nextAirport, graph, itinerary);
        }

        itinerary.push_back(airport);
    }
};

/*
// Beats 100% Runtime
class Solution {
public:
    // Using a map to represent the graph where key is the departure airport
    // and value is a priority queue to store the arrival airports in sorted order
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> airportGraph;
    vector<string> itinerary;

    void dfs(string airport) {
        auto& destinations = airportGraph[airport];
        while (!destinations.empty()) {
            string nextAirport = destinations.top();
            destinations.pop();
            dfs(nextAirport);
        }
        itinerary.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Build the graph
        for (const auto& ticket : tickets) {
            airportGraph[ticket[0]].push(ticket[1]);
        }

        // Start DFS from "JFK" airport
        dfs("JFK");

        // Reverse the itinerary to get the correct order
        reverse(itinerary.begin(), itinerary.end());

        return itinerary;
    }
};
*/