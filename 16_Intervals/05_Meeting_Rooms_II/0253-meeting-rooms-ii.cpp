/*
Problem: LeetCode 253 - Meeting Rooms II

Description:
Given an array of meeting time intervals where intervals[i] = [starti, endi], find the minimum number of conference rooms required.

Intuition:
To find the minimum number of conference rooms required, we can simulate the process of scheduling the meetings in a room.

Approach:
1. Sort the given intervals based on their start times in ascending order.
2. Use a priority queue to keep track of the end times of the meetings currently scheduled in different rooms.
3. Iterate through the sorted intervals:
   a. If the priority queue is empty or the start time of the current interval is greater than the end time of the earliest meeting in the queue, it means we can schedule this meeting in one of the existing rooms. Pop the earliest meeting from the queue and push the end time of the current interval.
   b. If the start time of the current interval is less than or equal to the end time of the earliest meeting in the queue, it means we need to allocate a new room for this meeting. Push the end time of the current interval into the queue.
4. The size of the priority queue at any time represents the number of conference rooms needed to accommodate the meetings.

Time Complexity:
The time complexity is O(n log n), where n is the number of intervals. Sorting the intervals based on their start times takes O(n log n) time, and pushing and popping elements from the priority queue takes O(log n) time for each meeting.

Space Complexity:
The space complexity is O(n) as we use a priority queue to store the end times of the meetings.
*/

class Solution {
  public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        if (intervals.empty()) {
            return 0;
        }

        // Sort the intervals based on their start times in ascending order
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        // Use a priority queue to keep track of end times of the meetings in different rooms
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]); // Push the end time of the first meeting

        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            // Check if the current meeting can be accommodated in an existing room
            if (start >= pq.top()) {
                pq.pop();
            }

            // Push the end time of the current meeting into the queue
            pq.push(end);
        }

        // The size of the priority queue represents the minimum number of conference rooms needed
        return pq.size();
    }
};