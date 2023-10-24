/*
Problem: LeetCode 19 - Remove Nth Node From End of List

Key Idea:
The key idea is to use two pointers, `fast` and `slow`, to find the Nth node from the end.

Approach:
1. Initialize two pointers, `fast` and `slow`, to the head of the linked list.
2. Move the `fast` pointer N nodes ahead, effectively creating a gap of N nodes between `fast` and `slow`.
3. Move both `fast` and `slow` one node at a time until `fast` reaches the end of the list.
4. Now, `slow` is at the Nth node from the end.
5. To remove the Nth node, update the `next` pointer of the node before `slow` to skip `slow`.
6. If N is equal to the length of the list, remove the head node.
7. Return the modified linked list.

Time Complexity:
O(N), where N is the number of nodes in the linked list. We perform a single pass through the list.

Space Complexity:
O(1), as we use a constant amount of extra space for pointers and variables.
*/

impl Solution {
    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
        let mut dummy = Box::new(ListNode::new(0));
        dummy.next = head;

        let mut fast = dummy.clone();
        let mut slow = dummy.as_mut();

        // Move the fast pointer N nodes ahead
        for _ in 0..n {
            fast = fast.next.unwrap();
        }

        // Move both pointers until fast reaches the end
        while fast.next.is_some() {
            fast = fast.next.unwrap();
            slow = slow.next.as_mut().unwrap();
        }

        // Remove the Nth node
        let next = slow.next.as_mut().unwrap();
        slow.next = next.next.clone();

        dummy.next
    }
}
