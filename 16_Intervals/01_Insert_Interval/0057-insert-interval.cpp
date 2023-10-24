/*
Problem: LeetCode 57 - Insert Interval

Description:
Given a set of non-overlapping intervals sorted by their start times,
insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Intuition:
The key idea is to find the correct position to insert the new interval and merge any overlapping intervals if necessary.

Approach:
1. Create an empty result vector to store the merged intervals.
2. Iterate through the given intervals:
   a. If the current interval's end is less than the new interval's start, add the current interval to the result vector.
   b. If the current interval's start is greater than the new interval's end, it means we have found the correct position to insert the new interval.
      Add the new interval to the result vector and merge any remaining intervals if needed.
   c. If there is an overlap between the current interval and the new interval, update the new interval's start and end to cover the overlapping region.
3. Add any remaining intervals to the result vector if needed.
4. Return the result vector.

Time Complexity:
The time complexity is O(n), where n is the number of intervals.

Space Complexity:
The space complexity is O(1) for the result vector, and no additional data structures are used, so the overall space complexity is also O(1).
*/

class Solution {
  public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();

        // Add intervals that end before the new interval starts
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // Merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        // Add the merged interval
        result.push_back(newInterval);

        // Add remaining intervals
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};