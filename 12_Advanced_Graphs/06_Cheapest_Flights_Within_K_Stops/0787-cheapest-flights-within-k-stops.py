"""
Problem: LeetCode 787 - Cheapest Flights Within K Stops

Key Idea:
The problem can be solved using Dijkstra's algorithm with a modified priority queue (min-heap) and BFS (Breadth-First Search) approach. We can create a graph where each node represents a city, and the edges represent flights between cities with associated costs. We use a priority queue to explore the nodes in a way that prioritizes the minimum cost. We continue the BFS process until we reach the destination city or exhaust the maximum number of allowed stops (K+1).

Time Complexity:
- The priority queue operations take O(E * log(V)) time, where E is the number of flights and V is the number of cities.
- In the worst case, all cities are explored, and all flights are considered.
- Overall, the time complexity is O(E * log(V)).

Space Complexity:
- The space required for the graph representation is O(V + E), where V is the number of cities and E is the number of flights.
- The space for the priority queue is O(V).
- Other data structures used take constant space.
- Therefore, the space complexity is O(V + E).
"""

import heapq
import math
from typing import List


class Solution:
    def findCheapestPrice(
        self, n: int, flights: List[List[int]], src: int, dst: int, max_stops: int
    ) -> int:
        graph = [[] for _ in range(n)]
        min_heap = [
            (0, src, max_stops + 1)
        ]  # (total_cost, current_city, remaining_stops)
        distances = [[math.inf] * (max_stops + 2) for _ in range(n)]

        for u, v, w in flights:
            graph[u].append((v, w))

        while min_heap:
            total_cost, current_city, remaining_stops = heapq.heappop(min_heap)
            if current_city == dst:
                return total_cost
            if remaining_stops > 0:
                for neighbor, cost in graph[current_city]:
                    new_cost = total_cost + cost
                    if new_cost < distances[neighbor][remaining_stops - 1]:
                        distances[neighbor][remaining_stops - 1] = new_cost
                        heapq.heappush(
                            min_heap, (new_cost, neighbor, remaining_stops - 1)
                        )

        return -1
