"""
Problem: LeetCode 252 - Meeting Rooms

Key Idea:
We can solve this problem by sorting the intervals based on their start times and then checking for any overlapping intervals. If the start time of the current interval is less than the end time of the previous interval, it means there is an overlap, and the person cannot attend all meetings. Otherwise, there is no overlap, and the person can attend all meetings.

Time Complexity:
- The time complexity of this approach is O(n log n) due to the sorting step, where n is the number of intervals.

Space Complexity:
- The space complexity is O(1), as we use only a constant amount of extra space.
"""


class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        if not intervals:
            return True

        intervals.sort(key=lambda x: x[0])

        for i in range(1, len(intervals)):
            if intervals[i][0] < intervals[i - 1][1]:
                return False

        return True
