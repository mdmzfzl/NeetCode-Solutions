/*
Problem: LeetCode 57 - Insert Interval

Key Idea:
The key idea is to iterate through the existing intervals and merge any overlapping intervals with the new interval to be inserted. This ensures that the resulting list remains sorted and non-overlapping.

Approach:
1. Initialize an empty vector 'result' to store the merged intervals.
2. Iterate through the intervals in 'intervals':
   - If the current interval's end is less than the new interval's start, add it to 'result'.
   - If the current interval's start is greater than the new interval's end, add the new interval to 'result' and update the new interval to the current interval.
   - If there is an overlap between the current interval and the new interval, update the new interval's start to the minimum of the two intervals' starts and its end to the maximum of the two intervals' ends.
3. After the loop, add the remaining new interval to 'result'.
4. Return 'result' as the merged intervals.

Time Complexity:
O(n), where n is the number of intervals. We perform a single pass through the intervals.

Space Complexity:
O(n), where n is the number of intervals. In the worst case, 'result' will contain all intervals.
*/

impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = Vec::new();
        let mut new_interval = new_interval;
        let mut i = 0;
        let n = intervals.len();

        // Add intervals that come before the new_interval
        while i < n && intervals[i][1] < new_interval[0] {
            result.push(intervals[i].clone());
            i += 1;
        }

        // Merge intervals with overlap
        while i < n && intervals[i][0] <= new_interval[1] {
            new_interval[0] = new_interval[0].min(intervals[i][0]);
            new_interval[1] = new_interval[1].max(intervals[i][1]);
            i += 1;
        }

        // Add the merged new_interval
        result.push(new_interval);

        // Add intervals that come after the new_interval
        while i < n {
            result.push(intervals[i].clone());
            i += 1;
        }

        result
    }
}
