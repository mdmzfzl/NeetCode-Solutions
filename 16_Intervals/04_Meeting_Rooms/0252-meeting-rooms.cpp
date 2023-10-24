/*
Problem: LeetCode 252 - Meeting Rooms

Description:
Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.

Intuition:
To determine if a person could attend all meetings, we need to check if there are any overlapping intervals. If any two intervals overlap, the person cannot attend all meetings.

Approach:
1. Sort the given intervals based on their start times in ascending order.
2. Iterate through the sorted intervals:
   a. For each interval (except the first one), check if its start time is less than the end time of the previous interval. If so, it means there is an overlap, and the person cannot attend all meetings. Return false.
3. If there are no overlaps, return true.

Time Complexity:
The time complexity is O(n log n), where n is the number of intervals. Sorting the intervals based on their start times takes O(n log n) time.

Space Complexity:
The space complexity is O(1) as we only use a constant amount of additional space.
*/

class Solution {
  public:
    bool canAttendMeetings(vector<vector<int>> &intervals) {
        if (intervals.empty()) {
            return true;
        }

        // Sort the intervals based on their start times in ascending order
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });

        for (int i = 1; i < intervals.size(); i++) {
            // Check if there is an overlap
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }

        return true;
    }
};