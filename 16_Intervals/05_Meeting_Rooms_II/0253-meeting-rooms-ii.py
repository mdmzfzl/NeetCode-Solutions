"""
Problem: LeetCode 253 - Meeting Rooms II

Key Idea:
We can solve this problem using a priority queue (min-heap). First, we sort the intervals based on their start times. We then iterate through the sorted intervals and maintain a min-heap of end times of ongoing meetings. For each interval, if the start time is greater than or equal to the smallest end time in the min-heap, it means the current meeting can reuse an existing room, so we pop the smallest end time from the min-heap. If not, we need to allocate a new room. After processing all intervals, the size of the min-heap gives us the minimum number of meeting rooms required.

Time Complexity:
- The time complexity of this approach is O(n log n) due to the sorting step and the heap operations, where n is the number of intervals.

Space Complexity:
- The space complexity is O(n), as we store the end times in the min-heap.
"""

import heapq


class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0

        intervals.sort(key=lambda x: x[0])
        min_heap = []
        heapq.heappush(min_heap, intervals[0][1])

        for i in range(1, len(intervals)):
            if intervals[i][0] >= min_heap[0]:
                heapq.heappop(min_heap)
            heapq.heappush(min_heap, intervals[i][1])

        return len(min_heap)
