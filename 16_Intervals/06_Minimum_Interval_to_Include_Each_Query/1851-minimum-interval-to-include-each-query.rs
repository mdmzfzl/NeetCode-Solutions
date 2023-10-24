/*
Problem: LeetCode 1851 - Minimum Interval to Include Each Query

Key Idea:
The main idea is to find, for each query, the smallest interval from a sorted list of intervals that contains that query point. This is achieved by maintaining a BinaryHeap (priority queue) of intervals that can potentially contain each query point.

Approach:
1. Convert input intervals into a vector of Interval structs and sort them by start points.
2. Initialize a HashMap to store query results.
3. Initialize a BinaryHeap to hold intervals overlapping the current query.
4. Iterate through sorted queries:
   - Add intervals with start points less than or equal to the query to the heap.
   - Find the minimum interval containing the query point:
     - If the top interval in the heap contains the query, store its length in the result map.
     - If the heap is empty, mark the query as not containing any interval.
     - Otherwise, remove the top interval from the heap.
5. Collect results in the original order and return them.

Time Complexity:
O(N * log(N)), due to sorting.

Space Complexity:
O(N + Q), for intervals and sorted_queries.
*/

use std::cmp::Ordering;
use std::collections::{BinaryHeap, HashMap};

#[derive(Debug, PartialEq, Eq)]
struct Interval {
    start: i32,
    end: i32,
}

impl Solution {
    pub fn min_interval(intervals: Vec<Vec<i32>>, queries: Vec<i32>) -> Vec<i32> {
        let mut intervals = intervals
            .into_iter()
            .map(|v| Interval {
                start: v[0],
                end: v[1],
            })
            .collect::<Vec<Interval>>();

        intervals.sort_by(|a, b| a.start.cmp(&b.start));

        let mut result_map = HashMap::new();
        let mut heap = BinaryHeap::new();
        let mut i = 0;

        let mut sorted_queries = queries.clone();
        sorted_queries.sort();

        for query in sorted_queries {
            while i < intervals.len() && intervals[i].start <= query {
                heap.push(&intervals[i]);
                i += 1;
            }

            loop {
                if let Some(top_interval) = heap.peek() {
                    if top_interval.start <= query && query <= top_interval.end {
                        result_map.insert(query, top_interval.length());
                        break;
                    } else {
                        heap.pop();
                    }
                } else {
                    result_map.insert(query, -1);
                    break;
                }
            }
        }

        queries.into_iter().map(|x| result_map[&x]).collect()
    }
}

impl Ord for Interval {
    fn cmp(&self, other: &Self) -> Ordering {
        if self.length() == other.length() {
            return self.end.cmp(&other.end).reverse();
        }
        return self.length().cmp(&other.length()).reverse();
    }
}

impl PartialOrd for Interval {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Interval {
    fn length(&self) -> i32 {
        self.end - self.start + 1
    }
}
