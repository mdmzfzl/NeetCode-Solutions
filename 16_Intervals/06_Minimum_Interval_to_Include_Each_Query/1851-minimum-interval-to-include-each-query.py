"""
Problem: LeetCode 1851 - Minimum Interval to Include Each Query

Key Idea:
The problem is to find the minimum interval for each query that includes at least one element from each interval in the list. We can solve this problem using a sorted list or priority queue (min-heap). First, we sort both the intervals and the queries based on their start values. Then, for each query, we iterate through the sorted intervals and add intervals to the min-heap as long as their start values are less than or equal to the current query. We also remove intervals from the min-heap whose end values are less than the start value of the current query. After processing all queries, the size of the min-heap gives us the minimum interval for each query.

Time Complexity:
- The time complexity of this approach is O((n + q) log n), where n is the number of intervals and q is the number of queries, due to the sorting and heap operations.

Space Complexity:
- The space complexity is O(n), as we store the intervals in the min-heap.
"""

import heapq


class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        intervals.sort(key=lambda x: x[0])
        queries_sorted = sorted(enumerate(queries), key=lambda x: x[1])

        min_heap = []
        ans = [-1] * len(queries)
        i = 0

        for query_index, query in queries_sorted:
            while i < len(intervals) and intervals[i][0] <= query:
                start, end = intervals[i]
                heapq.heappush(min_heap, (end - start + 1, end))
                i += 1

            while min_heap and min_heap[0][1] < query:
                heapq.heappop(min_heap)

            if min_heap:
                ans[query_index] = min_heap[0][0]

        return ans
