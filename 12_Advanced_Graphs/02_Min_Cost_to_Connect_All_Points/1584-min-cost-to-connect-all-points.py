"""
Problem: LeetCode 1584 - Min Cost to Connect All Points

Key Idea:
The problem can be solved using Kruskal's algorithm for finding the Minimum Spanning Tree (MST) of a graph. We start by calculating the distances between all pairs of points and then sort these distances along with their corresponding pairs. We initialize an empty MST and iterate through the sorted distances. For each distance, we check if the two points belong to different connected components in the MST using Union-Find. If they do, we add the distance to the MST and merge the components. We continue this process until all points are connected.

Time Complexity:
- Calculating distances between all pairs takes O(n^2) time.
- Sorting the distances takes O(n^2 * log(n^2)) = O(n^2 * log n) time.
- Union-Find operations take nearly constant time (amortized), and we perform it n times.
- Therefore, the overall time complexity is dominated by sorting and is O(n^2 * log n).

Space Complexity:
- We store distances and the edges in O(n^2) space.
- Union-Find data structure uses O(n) space.
- Therefore, the space complexity is O(n^2).
"""


class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        def distance(p1, p2):
            return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

        n = len(points)
        distances = []

        for i in range(n):
            for j in range(i + 1, n):
                distances.append((distance(points[i], points[j]), i, j))

        distances.sort()
        parent = list(range(n))
        rank = [0] * n
        mst_cost = 0

        def find(node):
            if parent[node] != node:
                parent[node] = find(parent[node])
            return parent[node]

        def union(node1, node2):
            root1 = find(node1)
            root2 = find(node2)
            if root1 != root2:
                if rank[root1] > rank[root2]:
                    parent[root2] = root1
                else:
                    parent[root1] = root2
                    if rank[root1] == rank[root2]:
                        rank[root2] += 1

        for distance, u, v in distances:
            if find(u) != find(v):
                union(u, v)
                mst_cost += distance

        return mst_cost
