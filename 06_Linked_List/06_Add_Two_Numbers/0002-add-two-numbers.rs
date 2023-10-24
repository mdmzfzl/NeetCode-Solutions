/*
Problem: LeetCode 2 - Add Two Numbers

Key Idea:
The key idea is to simulate the addition of two numbers, taking care of carry values.

Approach:
1. Initialize a dummy node as the head of the result linked list.
2. Initialize two pointers, `p` and `q`, to the heads of the input linked lists `l1` and `l2`.
3. Initialize a carry variable as 0.
4. Iterate through both `l1` and `l2` simultaneously:
   - Calculate the sum of the current nodes' values and the carry.
   - Update the carry for the next iteration.
   - Create a new node with the value of (sum % 10) and append it to the result linked list.
   - Move `p`, `q`, and the result pointer accordingly.
5. After the loop, if there is a carry, create a new node with the carry value and append it to the result linked list.
6. Return the next of the dummy node as the head of the result linked list.

Time Complexity:
O(max(N, M)), where N and M are the lengths of the input linked lists `l1` and `l2`. We perform a single pass through the longer list.

Space Complexity:
O(max(N, M)), as the result linked list can have a maximum length of max(N, M) + 1.
*/

impl Solution {
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut dummy = ListNode::new(0);
        let (mut p, mut q, mut carry) = (l1, l2, 0);
        let mut current = &mut dummy;

        while p.is_some() || q.is_some() {
            let x = p.as_ref().map_or(0, |node| node.val);
            let y = q.as_ref().map_or(0, |node| node.val);
            let sum = x + y + carry;

            carry = sum / 10;
            current.next = Some(Box::new(ListNode::new(sum % 10)));

            if let Some(ref mut node) = current.next {
                current = &mut *node;
            }

            if let Some(ref mut node) = p {
                p = node.next.take();
            }

            if let Some(ref mut node) = q {
                q = node.next.take();
            }
        }

        if carry > 0 {
            current.next = Some(Box::new(ListNode::new(carry)));
        }

        dummy.next
    }
}
