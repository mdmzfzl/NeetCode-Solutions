"""
Problem: LeetCode 207 - Course Schedule

Key Idea:
The problem can be reduced to detecting cycles in a directed graph. We can represent the course prerequisites as directed edges between nodes (courses). If there is a cycle in the graph, it means we can't complete all courses.

Time Complexity:
- Constructing the graph takes O(numCourses + len(prerequisites)) time, where numCourses is the number of courses and len(prerequisites) is the number of prerequisites.
- Detecting a cycle in a directed graph takes O(V + E) time, where V is the number of vertices (courses) and E is the number of edges (prerequisites).
- Therefore, the total time complexity is O(numCourses + len(prerequisites)) + O(V + E), which simplifies to O(numCourses + len(prerequisites)).

Space Complexity:
- The space complexity is O(numCourses + len(prerequisites)), where we store the graph using a dictionary and maintain a set for visited nodes.
"""


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = {i: [] for i in range(numCourses)}
        in_degree = [0] * numCourses

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
            for neighbor in graph[node]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    queue.append(neighbor)

        # If any course has in-degree greater than zero, there's a cycle
        return all(degree == 0 for degree in in_degree)
