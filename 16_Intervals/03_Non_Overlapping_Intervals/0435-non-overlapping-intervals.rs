/*
Problem: LeetCode 435 - Non-overlapping Intervals

Key Idea:
The key idea is to sort the intervals by their end times and then use greedy selection. Choose intervals that end earliest and remove overlapping intervals. This ensures that you retain as many non-overlapping intervals as possible.

Approach:
1. Sort the intervals based on their end values in ascending order.
2. Initialize a variable 'count' to 0 to keep track of non-overlapping intervals.
3. Initialize a variable 'prev_end' to -inf to store the end value of the last added interval.
4. Iterate through the sorted intervals:
   - If the current interval's start is greater than or equal to 'prev_end', it means it does not overlap with the previous interval.
     - Increment 'count' by 1.
     - Update 'prev_end' to the end value of the current interval.
   - If the current interval overlaps with the previous interval, skip it.
5. Return the value of 'count' as the maximum number of non-overlapping intervals.

Time Complexity:
O(n log n), where n is the number of intervals. The sorting step takes O(n log n) time.

Space Complexity:
O(1), as we use only a constant amount of extra space.
*/

impl Solution {
    pub fn erase_overlap_intervals(intervals: Vec<Vec<i32>>) -> i32 {
        if intervals.is_empty() {
            return 0;
        }

        let mut intervals = intervals;
        intervals.sort_by_key(|x| x[1]);

        let mut count = 1;
        let mut prev_end = intervals[0][1];

        for i in 1..intervals.len() {
            if intervals[i][0] >= prev_end {
                count += 1;
                prev_end = intervals[i][1];
            }
        }

        intervals.len() as i32 - count
    }
}
