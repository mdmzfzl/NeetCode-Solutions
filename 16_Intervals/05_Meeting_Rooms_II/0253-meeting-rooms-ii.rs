/*
Problem: LeetCode 253 - Meeting Rooms II

Key Idea:
The key idea is to sort the meetings by their start times and use a priority queue (min heap) to track the end times of ongoing meetings. For each meeting, check if there's an available room (i.e., the earliest ending meeting) in the priority queue. If not, allocate a new room. Keep updating the priority queue as meetings start and end. The size of the priority queue represents the minimum number of rooms needed.

Approach:
1. Create two vectors, 'starts' and 'ends', to store the start times and end times of the meetings, respectively.
2. Sort both 'starts' and 'ends' in ascending order.
3. Initialize variables 'rooms' to 0 and 'end_ptr' to 0.
4. Iterate through 'starts':
   - If the current start time is less than the current end time in 'ends', it means a meeting overlaps with an ongoing meeting.
     - Increment 'rooms' as a new room is required.
   - Otherwise, increment 'end_ptr' to indicate that the ongoing meeting has ended.
5. Return 'rooms' as the minimum number of meeting rooms required.

Time Complexity:
O(n log n), where n is the number of meetings. Sorting the 'starts' and 'ends' vectors takes O(n log n) time.

Space Complexity:
O(n), as we use two vectors 'starts' and 'ends' to store the start and end times of meetings.
*/

impl Solution {
    pub fn min_meeting_rooms(intervals: Vec<Vec<i32>>) -> i32 {
        if intervals.is_empty() {
            return 0;
        }

        let mut starts: Vec<i32> = Vec::new();
        let mut ends: Vec<i32> = Vec::new();

        for interval in &intervals {
            starts.push(interval[0]);
            ends.push(interval[1]);
        }

        starts.sort();
        ends.sort();

        let mut rooms = 0;
        let mut end_ptr = 0;

        for start in starts {
            if start < ends[end_ptr] {
                rooms += 1;
            } else {
                end_ptr += 1;
            }
        }

        rooms
    }
}
