"""
Problem: LeetCode 210 - Course Schedule II

Key Idea:
This problem is an extension of the previous Course Schedule problem (LeetCode 207). We need to return the order in which courses can be taken. We can use the topological sorting approach to solve this.

Time Complexity:
- Constructing the graph takes O(numCourses + len(prerequisites)) time, where numCourses is the number of courses and len(prerequisites) is the number of prerequisites.
- Performing topological sorting using BFS takes O(V + E) time, where V is the number of vertices (courses) and E is the number of edges (prerequisites).
- Therefore, the total time complexity is O(numCourses + len(prerequisites)) + O(V + E), which simplifies to O(numCourses + len(prerequisites)).

Space Complexity:
- The space complexity is O(numCourses + len(prerequisites)), where we store the graph using a dictionary, maintain a list for in-degrees, and use a queue for BFS traversal.
"""


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = {i: [] for i in range(numCourses)}
        in_degree = [0] * numCourses
        order = []

        # Construct the graph and count in-degrees
        for course, prereq in prerequisites:
            graph[prereq].append(course)
            in_degree[course] += 1

        # Initialize a queue with nodes having in-degree zero
        queue = collections.deque(
            [course for course, degree in enumerate(in_degree) if degree == 0]
        )

        # Perform topological sorting and update in-degrees
        while queue:
            node = queue.popleft()
            order.append(node)
            for neighbor in graph[node]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    queue.append(neighbor)

        # If the order doesn't contain all courses, there's a cycle
        return order if len(order) == numCourses else []
