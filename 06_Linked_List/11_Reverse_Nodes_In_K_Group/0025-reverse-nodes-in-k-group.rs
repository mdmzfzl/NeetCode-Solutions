/*
Problem: LeetCode 25 - Reverse Nodes in k-Group

Key Idea:
The key idea is to reverse k-node groups in a linked list using recursion. We need to reverse each group, connect them together, and stop when there are fewer than k nodes left.

Approach:
1. Initialize `original_head` as a mutable reference to the head of the original linked list. This reference will be used to keep track of the current group of nodes.
2. Advance the `current_group` pointer by k nodes using a loop. This loop serves two purposes:
   - It ensures that `current_group` points to the kth node if there are at least k nodes remaining.
   - If there are fewer than k nodes left, return the `original_head` as there is no need to reverse this group.
3. Recursively reverse the next group of nodes (i.e., the portion of the list after the current k nodes). This is done by calling `Self::reverse_k_group` with `current_group` as the new head of the list. The result is stored in `reversed_next_group`.
4. Reverse the current group of k nodes:
   - Initialize a new variable `new_head` as `None` to store the new head of the reversed group.
   - Use a loop to reverse the nodes one by one:
     - Take a node from `original_head`.
     - Update `original_head` to point to the next node.
     - Set the `next` pointer of the taken node to point to the current `new_head`.
     - Update `new_head` to point to the taken node.
   - After the loop, `new_head` will contain the reversed k nodes.
5. Connect the reversed current group to the reversed next group:
   - Initialize a mutable reference `current` to the end of `new_head`.
   - Traverse `current` until it reaches the end of the reversed current group (where `next` is `None`).
   - Set `current`'s `next` to point to `reversed_next_group`.
6. Return the `new_head`, which is the head of the fully reversed linked list.

Time Complexity:
O(N), where N is the number of nodes in the linked list. We traverse each node exactly once.

Space Complexity:
O(1), as we use a constant amount of extra space for pointers and variables.
*/

impl Solution {
    pub fn reverse_k_group(head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
        let mut original_head = head;
        let mut current_group = &mut original_head;

        // Advance the current_group pointer by k nodes
        for _ in 0..k {
            if let Some(node) = current_group {
                current_group = &mut node.next;
            } else {
                // If there are fewer than k nodes left, return the original head
                return original_head;
            }
        }

        // Recursively reverse the next group and get its head
        let mut reversed_next_group = Self::reverse_k_group(current_group.take(), k);

        // Reverse the current group and attach it to the reversed_next_group
        let mut new_head = None;
        while let Some(mut node) = original_head.take() {
            original_head = node.next.take();
            node.next = new_head;
            new_head = Some(node);
        }

        // Connect the reversed current group to the reversed next group
        let mut current = &mut new_head;
        while current.as_ref().is_some() {
            current = &mut current.as_mut().unwrap().next;
        }
        *current = reversed_next_group;

        new_head
    }
}
