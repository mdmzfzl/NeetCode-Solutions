/*
Problem: LeetCode 21 - Merge Two Sorted Lists

Key Idea:
The key idea is to create a new linked list while comparing and merging nodes from both input lists in a sorted manner.

Approach:
1. Start by handling the base cases:
   - If both `l1` and `l2` are `None`, there are no elements to merge, so return `None`.
   - If either `l1` or `l2` is `None`, return the other list because a single linked list is always sorted.
2. Initialize a pattern match on `(l1, l2)` to handle the different cases:
   - If `l1` is not `None` and `l2` is `None`, return `l1`.
   - If `l1` is `None` and `l2` is not `None`, return `l2`.
   - If both `l1` and `l2` are not `None`, proceed with the merging process.
3. Initialize mutable references `node1` and `node2` to the values in `l1` and `l2`.
4. Compare the values of `node1` and `node2`. Take the smaller of the two and set it as the `next` node for the current result node.
5. Recursively call `Solution::merge_two_lists` to continue merging the remaining elements. Update the references `node1` and `node2` accordingly based on which value was selected in the previous step.
6. Repeat steps 4 and 5 until one of the input lists becomes empty.
7. After the loop, one of the input lists might have remaining elements. Append the remaining elements to the merged list.
8. Finally, return the merged list starting from the `next` node of the dummy node.

Time Complexity:
O(n), where n is the total number of nodes in the two input linked lists. We perform a single pass through both lists.

Space Complexity:
O(1), as we use a constant amount of extra space for pointers and nodes.
*/

// Definition for singly-linked list

// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//     pub val: i32,
//     pub next: Option<Box<ListNode>>,
// }

// impl ListNode {
//     #[inline]
//     fn new(val: i32) -> Self {
//         ListNode { next: None, val }
//     }
// }

impl Solution {
    pub fn merge_two_lists(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        match (l1, l2) {
            (None, None) => None,
            (Some(node1), None) => Some(node1),
            (None, Some(node2)) => Some(node2),
            (Some(mut node1), Some(mut node2)) => {
                if node1.val < node2.val {
                    node1.next = Solution::merge_two_lists(node1.next, Some(node2));
                    Some(node1)
                } else {
                    node2.next = Solution::merge_two_lists(Some(node1), node2.next);
                    Some(node2)
                }
            }
        }
    }
}
