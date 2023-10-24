/*
Problem: LeetCode 252 - Meeting Rooms

Key Idea:
The key idea is to sort the meetings by their start times and then check if there are any overlaps by comparing the end time of one meeting with the start time of the next. If there are no overlaps, you can schedule all the meetings.

Approach:
1. Sort the intervals based on their start times in ascending order.
2. Iterate through the sorted intervals:
   - If the end time of the current interval is greater than or equal to the start time of the next interval, it indicates an overlap.
   - Return false, as overlapping intervals mean that a room is double-booked.
3. If there are no overlaps after the loop, return true, indicating that all meetings can be scheduled without conflicts.

Time Complexity:
O(n log n), where n is the number of intervals. The sorting step takes O(n log n) time.

Space Complexity:
O(1), as we use only a constant amount of extra space.
*/

impl Solution {
    pub fn can_attend_meetings(intervals: Vec<Vec<i32>>) -> bool {
        if intervals.is_empty() {
            return true;
        }

        let mut intervals = intervals;
        intervals.sort_by_key(|x| x[0]);

        for i in 0..intervals.len() - 1 {
            if intervals[i][1] > intervals[i + 1][0] {
                return false; // Overlapping intervals
            }
        }

        true
    }
}
