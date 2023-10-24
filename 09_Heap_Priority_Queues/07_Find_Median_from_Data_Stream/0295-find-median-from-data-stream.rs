/*
Problem: LeetCode 295 - Find Median from Data Stream

Key Idea:
The key idea is to use two heaps (priority queues) to find the median of a data stream.

Approach:
1. Maintain two heaps: a max-heap (left_heap) to store the lower half of the elements and a min-heap (right_heap) to store the upper half.
2. Ensure that the size of the left_heap is either equal to or one greater than the size of the right_heap.
3. When inserting an element into the data stream:
   - If the element is less than or equal to the median (top of left_heap), insert it into the left_heap.
   - Otherwise, insert it into the right_heap.
   - Balance the heaps to ensure the size property mentioned in step 2.
4. To find the median:
   - If the size of the left_heap is greater than the size of the right_heap, return the top element of the left_heap as the median.
   - If the sizes are equal, return the average of the top elements of both heaps as the median.

Time Complexity:
- Insertion: O(log n), where n is the number of elements in the data stream.
- Finding the median: O(1).

Space Complexity:
O(n), where n is the number of elements in the data stream (space is used to store the elements in heaps).
*/

use std::cmp::Reverse;
use std::collections::BinaryHeap;

struct MedianFinder {
    left_heap: BinaryHeap<i32>,           // Max-heap for the lower half
    right_heap: BinaryHeap<Reverse<i32>>, // Min-heap for the upper half
}

impl MedianFinder {
    fn new() -> Self {
        MedianFinder {
            left_heap: BinaryHeap::new(),
            right_heap: BinaryHeap::new(),
        }
    }

    fn add_num(&mut self, num: i32) {
        self.left_heap.push(num);
        self.right_heap.push(Reverse(self.left_heap.pop().unwrap()));

        if self.left_heap.len() < self.right_heap.len() {
            self.left_heap.push(self.right_heap.pop().unwrap().0);
        }
    }

    fn find_median(&self) -> f64 {
        let left_len = self.left_heap.len();
        let right_len = self.right_heap.len();

        if left_len > right_len {
            self.left_heap.peek().map(|&x| x as f64).unwrap_or(0.0)
        } else if left_len < right_len {
            self.right_heap.peek().map(|&x| x.0 as f64).unwrap_or(0.0)
        } else {
            let left_top = self.left_heap.peek().map(|&x| x).unwrap_or(0);
            let right_top = self.right_heap.peek().map(|&x| x.0).unwrap_or(0);
            (left_top + right_top) as f64 / 2.0
        }
    }
}
