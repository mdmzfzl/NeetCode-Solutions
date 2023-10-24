/*
Problem: LeetCode 215 - Kth Largest Element in an Array

Key Idea:
The key idea is to use a min-heap (priority queue) to efficiently find the kth largest element in the array.

Approach:
1. Create a min-heap (priority queue) with a capacity of k elements.
2. Iterate through the array:
   - Insert each element into the min-heap.
   - If the min-heap size exceeds k, remove the smallest element (pop from the heap).
3. The top element of the min-heap (the root) will be the kth largest element.

Time Complexity:
- Heap Insertion and Extraction: O(log k) per operation, where k is the value of 'k'.
- We perform this operation for each of the 'n' elements in the array.
- Overall time complexity is O(n log k).

Space Complexity:
O(k), as the min-heap can contain at most k elements.
*/

use std::cmp::Reverse;
use std::collections::BinaryHeap;

impl Solution {
    pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
        // Create a min-heap with a capacity of k
        let mut min_heap: BinaryHeap<Reverse<i32>> = nums
            .iter()
            .take(k as usize)
            .map(|&num| Reverse(num))
            .collect();

        // Iterate through the remaining elements
        for &num in nums.iter().skip(k as usize) {
            // If the current number is larger than the smallest number in the min-heap, replace it
            if num > min_heap.peek().unwrap().0 {
                min_heap.pop();
                min_heap.push(Reverse(num));
            }
        }

        // The top of the min-heap contains the kth largest element
        min_heap.peek().unwrap().0
    }
}
