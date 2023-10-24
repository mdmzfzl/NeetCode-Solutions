/*
Problem: LeetCode 143 - Reorder List

Key Idea:
The key idea is to reorder the linked list by dividing it into two halves, reversing the second half, and merging the two halves.

Approach:
1. Find the middle of the linked list using the slow and fast pointer technique.
2. Split the linked list into two halves at the middle node.
3. Reverse the second half of the linked list.
4. Merge the two halves of the linked list in an interleaving manner.
   - Start with two pointers, `h1` at the head of the first half and `h2` at the head of the reversed second half.
   - While `h2` is not None, insert the node pointed to by `h2` after the node pointed to by `h1`.
   - Move `h1` and `h2` accordingly.
5. Set the next of the last node in the merged list to None.

Time Complexity:
O(n), where n is the number of nodes in the linked list. We perform a single pass through the list to find the middle and reverse the second half.

Space Complexity:
O(1), as we use a constant amount of extra space for pointers and variables.
*/

use std::cmp::Ordering;

impl Solution {
    pub fn reorder_list(head: &mut Option<Box<ListNode>>) {
        let mut second_half = Self::split_list(head);
        second_half = Self::reverse_list(second_half);
        Self::merge_lists(head, second_half);
    }

    // Function to find the middle of the list and split it
    fn split_list(head: &mut Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let (mut fast, mut slow) = (&head.clone(), head);
        while fast.is_some() {
            fast = &(fast.as_ref().unwrap().next);
            if fast.is_some() {
                fast = &fast.as_ref().unwrap().next;
                slow = &mut slow.as_mut().unwrap().next;
            }
        }
        slow.as_mut().unwrap().next.take()
    }

    // Function to reverse a linked list
    fn reverse_list(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut prev = None;
        while let Some(mut curr) = head {
            head = curr.next;
            curr.next = prev;
            prev = Some(curr);
        }
        prev
    }

    // Function to merge two lists alternately
    fn merge_lists(mut head1: &mut Option<Box<ListNode>>, mut head2: Option<Box<ListNode>>) {
        let mut h1 = head1;
        let mut h2 = head2;
        while h1.is_some() && h2.is_some() {
            let mut h1next = h1.as_mut().unwrap().next.take();
            let mut h2next = h2.as_mut().unwrap().next.take();
            h1.as_mut().unwrap().next = h2;
            h1.as_mut().unwrap().next.as_mut().unwrap().next = h1next;
            h1 = &mut h1.as_mut().unwrap().next.as_mut().unwrap().next;
            h2 = h2next;
        }
        if h2.is_some() {
            h1 = &mut h2;
        }
    }
}
