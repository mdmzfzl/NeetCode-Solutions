"""
Problem: LeetCode 435 - Non-overlapping Intervals
 
Key Idea:
We can solve this problem by first sorting the intervals based on their end times. Then, we iterate through the sorted intervals and count the number of overlapping intervals. If the start of the current interval is less than the end of the previous interval, it means there is an overlap, so we increment the count and skip adding the current interval to the non-overlapping set. If there is no overlap, we update the end of the previous interval to be the end of the current interval.

Time Complexity:
- The time complexity of this approach is O(n log n) due to the sorting step, where n is the number of intervals.

Space Complexity:
- The space complexity is O(1), as we use only a constant amount of extra space.
"""


class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0

        intervals.sort(key=lambda x: x[1])
        non_overlapping = 1  # Count of non-overlapping intervals
        prev_end = intervals[0][1]

        for i in range(1, len(intervals)):
            if intervals[i][0] >= prev_end:
                non_overlapping += 1
                prev_end = intervals[i][1]

        return len(intervals) - non_overlapping
