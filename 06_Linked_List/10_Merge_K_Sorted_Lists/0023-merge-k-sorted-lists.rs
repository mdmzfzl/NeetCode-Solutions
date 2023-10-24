/*
Problem: LeetCode 23 - Merge k Sorted Lists

Key Idea:
The key idea is to use a min-heap (priority queue) to efficiently merge the k sorted lists.

Approach:
1. Initialize an empty min-heap (priority queue).
2. Push the head of each sorted list (if it's not None) into the min-heap along with its list index.
3. Initialize a dummy node as the head of the merged list.
4. While the min-heap is not empty:
   - Pop the smallest element (with the list index) from the min-heap.
   - Add this element to the merged list.
   - Move the pointer in the corresponding list to its next element (if it exists) and push it into the min-heap.
5. Return the merged list.

Time Complexity:
O(N log k), where N is the total number of elements across all lists, and k is the number of lists.
   - The min-heap can have at most k elements, and extracting the minimum element takes O(log k) time.
   - We perform this extraction for all N elements.

Space Complexity:
O(k), as the min-heap can have at most k elements.
*/

// Solution: https://leetcode.com/problems/merge-k-sorted-lists/solutions/1427861/Rust-Two-solutions-using-priority-queue-and-merging-the-lists-one-by-one/

use std::cmp::{Ordering, Reverse};
use std::collections::BinaryHeap;

impl Solution {
    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        let mut merged_head = ListNode::new(0);
        let mut tail = &mut merged_head.next;

        // Create a min-heap to keep track of the smallest nodes
        let mut min_heap = BinaryHeap::with_capacity(lists.len());

        // Initialize the min-heap with the heads of all lists
        for list in lists {
            if let Some(node) = list {
                min_heap.push(Reverse(NodeWrapper(node)));
            }
        }

        // Merge nodes from the min-heap
        while let Some(Reverse(mut node)) = min_heap.pop() {
            // Push the next node from the same list into the min-heap if it exists
            if let Some(next) = node.0.next.take() {
                min_heap.push(Reverse(NodeWrapper(next)));
            }

            // Add the current smallest node to the merged list
            tail.replace(node.0);
            tail = &mut tail.as_mut().unwrap().next;
        }

        // Return the merged list starting from the real head (skip the dummy head)
        merged_head.next.take()
    }
}

struct NodeWrapper(Box<ListNode>);
impl PartialOrd<NodeWrapper> for NodeWrapper {
    fn partial_cmp(&self, other: &NodeWrapper) -> Option<Ordering> {
        self.0.val.partial_cmp(&other.0.val)
    }
}

impl Ord for NodeWrapper {
    fn cmp(&self, other: &Self) -> Ordering {
        self.0.val.cmp(&other.0.val)
    }
}

impl PartialEq<NodeWrapper> for NodeWrapper {
    fn eq(&self, other: &NodeWrapper) -> bool {
        self.0.val.eq(&other.0.val)
    }
}

impl Eq for NodeWrapper {}
