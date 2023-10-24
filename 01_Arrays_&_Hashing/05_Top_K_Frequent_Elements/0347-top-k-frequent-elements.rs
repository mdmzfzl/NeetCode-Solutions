/*
Problem: LeetCode 347 - Top K Frequent Elements

Key Idea:
The key idea is to use a combination of a hashmap to count the frequency of each element and a min heap (priority queue) to efficiently maintain the top k frequent elements.

Approach:
1. Create a hashmap to count the frequency of each element in the input array.
2. Create a min heap (priority queue) of size k to store pairs of elements and their frequencies.
3. Iterate through the hashmap:
   - For each element, if the heap size is less than k, insert it into the heap.
   - If the heap size is already k, compare the element's frequency with the smallest frequency in the heap. If the element's frequency is greater, pop the smallest element from the heap and insert the current element.
4. Extract the elements from the heap to obtain the top k frequent elements.

Time Complexity:
O(n log k), where n is the number of elements in the input array and k is the given value. Inserting an element into the heap takes O(log k) time, and we perform this operation for each of the n elements.

Space Complexity:
O(n), as we use a hashmap to store the frequency of elements, which can have up to n distinct keys.
*/

use std::cmp::Reverse;
use std::collections::{BinaryHeap, HashMap};

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut freq_map: HashMap<i32, i32> = HashMap::new();

        // Count the frequency of each element
        for num in &nums {
            *freq_map.entry(*num).or_insert(0) += 1;
        }

        // Create a min heap of size k to store the top k frequent elements
        let mut min_heap: BinaryHeap<Reverse<(i32, i32)>> = BinaryHeap::new();

        // Insert elements into the heap
        for (num, freq) in freq_map.iter() {
            if min_heap.len() < k as usize {
                min_heap.push(Reverse((*freq, *num)));
            } else if freq > &min_heap.peek().unwrap().0 .0 {
                min_heap.pop();
                min_heap.push(Reverse((*freq, *num)));
            }
        }

        // Extract the elements from the heap
        let result: Vec<i32> = min_heap.into_iter().map(|rev| rev.0 .1).collect();

        result
    }
}
