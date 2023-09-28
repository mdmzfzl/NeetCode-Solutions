/*
Problem: LeetCode 141 - Linked List Cycle

Key Idea:
The key idea is to use two pointers, one slow and one fast, to detect the presence of a cycle in the linked list.

Approach:
1. Initialize two pointers, `slow` and `fast`, to the head of the linked list.
2. Traverse the linked list with the pointers:
   - Move `slow` one step at a time.
   - Move `fast` two steps at a time.
3. If there is a cycle in the linked list, `fast` will eventually catch up to `slow`, and they will meet at some point in the cycle.
4. If there is no cycle, `fast` will reach the end of the list (i.e., become None) before `slow`.
5. Return true if there is a cycle, and false if there is no cycle.

Time Complexity:
O(N), where N is the number of nodes in the linked list. In the worst case, both pointers traverse the entire list once.

Space Complexity:
O(1), as we use a constant amount of extra space for the two pointers.
*/

// No option to solve this problem in Rust