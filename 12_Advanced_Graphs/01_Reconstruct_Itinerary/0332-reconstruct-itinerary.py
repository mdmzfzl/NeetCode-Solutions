"""
Problem: LeetCode 332 - Reconstruct Itinerary

Key Idea:
The problem can be approached using a depth-first search (DFS) approach. We start from the "JFK" airport and explore all possible routes by visiting each airport exactly once. We use a dictionary to store the destinations for each source airport, and for each source airport, we sort the destinations in lexicographical order. This ensures that we visit the airports in the desired order.

Time Complexity:
- Building the graph (destination dictionary) takes O(n * log n) time due to sorting the destinations.
- The DFS traversal takes O(n) time in the worst case since we visit each ticket exactly once.
- Therefore, the overall time complexity is O(n * log n + n), which simplifies to O(n * log n).

Space Complexity:
- We use a dictionary to store the graph, which takes O(n) space.
- The recursive stack for DFS can go as deep as the number of tickets, which is O(n).
- Therefore, the space complexity is O(n).
"""


class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph = collections.defaultdict(list)

        for start, end in sorted(tickets, reverse=True):
            graph[start].append(end)

        route = []

        def dfs(node):
            while graph[node]:
                dfs(graph[node].pop())
            route.append(node)

        dfs("JFK")

        return route[::-1]
