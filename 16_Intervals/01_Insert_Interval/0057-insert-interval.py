"""
Problem: LeetCode 57 - Insert Interval

Key Idea:
We can solve this problem by iterating through the intervals and keeping track of the merged intervals. We initialize an empty list `result` to store the merged intervals. We iterate through the intervals, and for each interval, we compare its end with the start of the new interval and the new interval's end with the start of the current interval. If they overlap, we update the start and end of the new interval accordingly. If they don't overlap, we add the current interval to the result and reset the new interval. After iterating through all intervals, we add the new interval (if not added already) and return the result.

Time Complexity:
- The time complexity of this approach is O(n), where n is the number of intervals.

Space Complexity:
- The space complexity is O(n), as we store the merged intervals in the result list.
"""


class Solution:
    def insert(
        self, intervals: List[List[int]], newInterval: List[int]
    ) -> List[List[int]]:
        result = []
        new_start, new_end = newInterval

        for interval in intervals:
            if interval[1] < new_start:
                result.append(interval)
            elif interval[0] > new_end:
                result.append([new_start, new_end])
                new_start, new_end = interval
            else:
                new_start = min(new_start, interval[0])
                new_end = max(new_end, interval[1])

        result.append([new_start, new_end])
        return result
