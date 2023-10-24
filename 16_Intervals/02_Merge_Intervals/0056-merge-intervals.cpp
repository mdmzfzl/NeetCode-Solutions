/*
Problem: LeetCode 56 - Merge Intervals

Description:
Given a collection of intervals, merge all overlapping intervals.

Intuition:
To merge overlapping intervals, we can sort the intervals based on their start times. Then, we can iterate through the sorted intervals and merge any overlapping intervals as we encounter them.

Approach:
1. Sort the given intervals based on their start times.
2. Create an empty result vector to store the merged intervals.
3. Iterate through the sorted intervals:
   a. If the result vector is empty or the current interval's start is greater than the end of the last merged interval in the result vector, add the current interval to the result vector.
   b. If there is an overlap between the current interval and the last merged interval in the result vector, update the end of the last merged interval to the maximum of both intervals' ends.
4. Return the result vector.

Time Complexity:
The time complexity is O(n log n), where n is the number of intervals. Sorting the intervals takes O(n log n) time, and merging them takes O(n) time.

Space Complexity:
The space complexity is O(1) for the result vector, and no additional data structures are used, so the overall space complexity is also O(1).
*/

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.empty()) return {};

        // Sort the intervals based on their start times
        // Uses a lambda function as the third argument of the sort function to define the custom sorting criteria.
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            vector<int> &lastInterval = result.back();

            if (intervals[i][0] > lastInterval[1]) {
                // No overlap, add the current interval to the result
                result.push_back(intervals[i]);
            } else {
                // Overlap, update the end of the last merged interval
                lastInterval[1] = max(lastInterval[1], intervals[i][1]);
            }
        }

        return result;
    }
};