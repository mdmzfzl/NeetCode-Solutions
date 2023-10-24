/*
Problem: LeetCode 435 - Non-overlapping Intervals

Description:
Given an array of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Intuition:
To find the minimum number of intervals to remove, we can use a greedy approach. If two intervals overlap, we should keep the one with the smaller end time, as this will leave more space for other intervals. If we keep intervals with smaller end times, we have a better chance of fitting more intervals in the remaining space.

Approach:
1. Sort the given intervals based on their end times in ascending order.
2. Initialize a variable "end" to store the end time of the last non-overlapping interval.
3. Initialize a variable "count" to keep track of the number of intervals to remove (initialize to 0).
4. Iterate through the sorted intervals:
   a. If the current interval's start time is greater than or equal to "end", it means it doesn't overlap with the last non-overlapping interval, so we update "end" to be the end time of the current interval.
   b. If the current interval's start time is less than "end", it means there is an overlap, and we need to remove one of the intervals. We increment the "count" variable and continue to the next interval.
5. Return the value of "count", which represents the minimum number of intervals to remove.

Time Complexity:
The time complexity is O(n log n), where n is the number of intervals. Sorting the intervals based on their end times takes O(n log n) time.

Space Complexity:
The space complexity is O(1) as we only use a constant amount of additional space.
*/

class Solution {
  public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.empty()) {
            return 0;
        }

        // Sort the intervals based on their end times in ascending order
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        int end = intervals[0][1]; // End time of the last non-overlapping interval
        int count = 0; // Number of intervals to remove

        for (int i = 1; i < intervals.size(); i++) {
            // If the current interval's start time is less than "end", there is an overlap
            if (intervals[i][0] < end) {
                count++;
            } else {
                // No overlap, update "end" to be the end time of the current interval
                end = intervals[i][1];
            }
        }

        return count;
    }
};