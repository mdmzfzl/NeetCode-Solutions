"""
Problem: LeetCode 56 - Merge Intervals

Key Idea:
We can solve this problem by first sorting the intervals based on their start times. Then, we iterate through the sorted intervals and merge overlapping intervals. We initialize an empty list `result` to store the merged intervals. For each interval, if it overlaps with the previous interval (i.e., the end of the previous interval is greater than or equal to the start of the current interval), we update the end of the previous interval to be the maximum of the end of both intervals. If there is no overlap, we add the previous interval to the result and update the previous interval to be the current interval. After iterating through all intervals, we add the last interval (or the merged interval) to the result.

Time Complexity:
- The time complexity of this approach is O(n log n) due to the sorting step, where n is the number of intervals.

Space Complexity:
- The space complexity is O(n), as we store the merged intervals in the result list.
"""


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []

        intervals.sort(key=lambda x: x[0])
        result = [intervals[0]]

        for interval in intervals[1:]:
            if interval[0] <= result[-1][1]:
                result[-1][1] = max(result[-1][1], interval[1])
            else:
                result.append(interval)

        return result
