/*
Problem: LeetCode 206 - Reverse Linked List

Key Idea:
The key idea is to reverse the linked list by iteratively changing the direction of the pointers.

Approach:
1. Initialize three pointers: `prev` as `None`, `curr` as the head of the linked list, and `next` as `None`.
2. Iterate through the linked list:
   - Save the next node of `curr` in `next`.
   - Update the `next` pointer of `curr` to point to the `prev` node (reverse the direction).
   - Move `prev` to `curr` and `curr` to `next`.
3. After the loop, `prev` will be the new head of the reversed linked list.
4. Return `prev` as the new head.

Time Complexity:
O(n), where n is the number of nodes in the linked list. We perform a single pass through the linked list.

Space Complexity:
O(1), as we use a constant amount of extra space for the three pointers.
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
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut prev = None;
        let mut curr = head;

        while let Some(mut node) = curr.take() {
            let next = node.next.take();
            node.next = prev.take();
            prev = Some(node);
            curr = next;
        }

        prev
    }
}
