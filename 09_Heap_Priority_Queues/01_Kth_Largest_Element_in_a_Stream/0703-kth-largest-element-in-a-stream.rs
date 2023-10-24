/*
Problem: LeetCode 703 - Kth Largest Element in a Stream

Key Idea:
The key idea is to use a min-heap (priority queue) to efficiently maintain the k largest elements from the stream.

Approach:
1. Initialize a min-heap with a capacity of k elements.
2. As new elements are added to the stream:
   - If the min-heap is not at capacity (i.e., less than k elements), simply push the new element into the heap.
   - If the min-heap is at capacity, compare the new element with the smallest element in the heap (the root).
     - If the new element is larger, remove the smallest element (pop from the heap) and push the new element.
     - Otherwise, ignore the new element.
3. The top element of the min-heap (the root) will be the kth largest element.

Time Complexity:
- Add Operation: O(log k), where k is the capacity of the min-heap. Inserting into a heap takes O(log k) time.
- Get Kth Largest Operation: O(1), as the top element of the min-heap is the kth largest element.

Space Complexity:
O(k), where k is the capacity of the min-heap.
*/

use std::cmp::Reverse;
use std::collections::BinaryHeap;

struct KthLargest {
    k: usize,
    max_heap: BinaryHeap<Reverse<i32>>,
}

impl KthLargest {
    fn new(k: i32, nums: Vec<i32>) -> Self {
        let mut obj = KthLargest {
            k: k as usize,
            max_heap: BinaryHeap::new(),
        };
        for num in nums {
            obj.max_heap.push(Reverse(num));
        }
        obj
    }

    fn add(&mut self, val: i32) -> i32 {
        self.max_heap.push(Reverse(val));
        while self.max_heap.len() > self.k {
            self.max_heap.pop();
        }

        if let Some(&Reverse(kth_largest)) = self.max_heap.peek() {
            kth_largest
        } else {
            0
        }
    }
}
