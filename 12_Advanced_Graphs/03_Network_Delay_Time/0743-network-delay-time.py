"""
Problem: LeetCode 743 - Network Delay Time

Key Idea:
The problem can be solved using Dijkstra's algorithm to find the shortest paths from a source node to all other nodes in a weighted graph. We start by creating an adjacency list representation of the graph. We maintain a priority queue to select the next node to visit based on the minimum distance. We initialize distances to all nodes as infinity except for the source node, which is set to 0. We continue exploring nodes and updating distances until the priority queue is empty. The maximum distance among all nodes will be the answer.

Time Complexity:
- Constructing the adjacency list takes O(n + m) time, where n is the number of nodes and m is the number of edges.
- Initializing distances takes O(n) time.
- The priority queue operations take O(n * log(n)) time in total (amortized) as we insert each node once.
- Overall, the time complexity is dominated by the priority queue operations and is O(n * log(n) + n + m).

Space Complexity:
- The adjacency list takes O(n + m) space.
- The priority queue takes O(n) space.
- The distances array takes O(n) space.
- Therefore, the space complexity is O(n + m).
"""

import heapq
from collections import defaultdict


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        # Create an adjacency list representation of the graph
        graph = defaultdict(list)
        for u, v, w in times:
            graph[u].append((v, w))

        # Initialize distances to all nodes as infinity except for the source node
        distances = [float("inf")] * (n + 1)
        distances[k] = 0

        # Priority queue to select the next node to visit based on the minimum distance
        pq = [(0, k)]

        while pq:
            distance, node = heapq.heappop(pq)
            if distance > distances[node]:
                continue
            for neighbor, weight in graph[node]:
                if distance + weight < distances[neighbor]:
                    distances[neighbor] = distance + weight
                    heapq.heappush(pq, (distances[neighbor], neighbor))

        # Find the maximum distance among all nodes
        max_distance = max(distances[1:])

        return max_distance if max_distance < float("inf") else -1
