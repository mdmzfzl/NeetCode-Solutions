/*
Problem: LeetCode 56 - Merge Intervals

Key Idea:
The key idea is to first sort the intervals by their start times. Then, iterate through the sorted intervals and merge overlapping ones by updating the end time of the merged interval. Keep track of non-overlapping intervals and return the merged result.

Approach:
1. Sort the intervals based on their start values.
2. Initialize an empty vector 'result' to store the merged intervals.
3. Iterate through the sorted intervals:
   - If 'result' is empty or the current interval's start is greater than the last interval's end in 'result', add the current interval to 'result'.
   - If there is an overlap between the current interval and the last interval in 'result', merge them by updating the last interval's end to the maximum of the two intervals' ends.
4. Return 'result' as the merged intervals.

Time Complexity:
O(n log n), where n is the number of intervals. The sorting step takes O(n log n) time.

Space Complexity:
O(n), where n is the number of intervals. 'result' can have a maximum of n merged intervals.
*/

impl Solution {
    pub fn merge(intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        if intervals.is_empty() {
            return vec![];
        }

        let mut intervals = intervals;
        intervals.sort_by_key(|x| x[0]);

        let mut result: Vec<Vec<i32>> = Vec::new();
        result.push(intervals[0].clone());

        for i in 1..intervals.len() {
            let current = intervals[i].clone();
            let last = result.last_mut().unwrap();

            if current[0] > last[1] {
                result.push(current);
            } else {
                last[1] = last[1].max(current[1]);
            }
        }

        result
    }
}
