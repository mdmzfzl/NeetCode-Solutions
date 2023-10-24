/*
Problem: LeetCode 1046 - Last Stone Weight

Key Idea:
The key idea is to use a max-heap (priority queue) to efficiently simulate the process of smashing stones until only one stone remains or no stones are left.

Approach:
1. Create a max-heap (priority queue) to store the weights of the stones.
2. Insert all stone weights into the max-heap.
3. While there are at least two stones in the max-heap:
   - Pop the two largest stones from the max-heap.
   - Calculate their difference (smash them together).
   - If the difference is not zero, insert it back into the max-heap.
4. If there is exactly one stone left in the max-heap, return its weight; otherwise, return 0.

Time Complexity:
- Heap Insertion and Extraction: O(log n) per operation, where n is the number of stones.
- In the worst case, we perform n-1 iterations of the while loop, resulting in O(n log n) time complexity for the entire process.

Space Complexity:
O(n), where n is the number of stones, as we use a max-heap to store the stone weights.
*/

use std::collections::BinaryHeap;

impl Solution {
    pub fn last_stone_weight(stones: Vec<i32>) -> i32 {
        let mut max_heap = BinaryHeap::new();

        // Insert all stone weights into the max-heap
        for stone in stones {
            max_heap.push(stone);
        }

        // Simulate stone smashing until only one stone remains or none
        while max_heap.len() >= 2 {
            let stone1 = max_heap.pop().unwrap();
            let stone2 = max_heap.pop().unwrap();
            let diff = stone1 - stone2;

            if diff > 0 {
                max_heap.push(diff);
            }
        }

        // Return the remaining stone weight or 0
        max_heap.pop().unwrap_or(0)
    }
}
