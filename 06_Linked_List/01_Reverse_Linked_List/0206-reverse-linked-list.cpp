/*
Problem: LeetCode 206 - Reverse Linked List

Description:
Reverse a singly linked list.

Intuition:
To reverse a linked list, we need to change the direction of each node's "next" pointer. We can do this iteratively by keeping track of three nodes: current, previous, and next. We start with current pointing to the head of the original list, previous as nullptr (since there is no node before the head), and next as the next node of the current node. During each iteration, we update the "next" pointer of the current node to point to the previous node. Then, we move the previous node to be the current node and the current node to be the next node. We repeat this process until the end of the original list is reached.

Approach:
1. Create three pointers: current, previous, and next.
2. Initialize current to the head of the original list and previous as nullptr.
3. While the current node is not nullptr:
   a. Update the "next" pointer of the current node to point to the previous node.
   b. Move previous to be the current node and current to be the next node.
4. At the end of the loop, the previous node will be the new head of the reversed list.

Time Complexity:
The time complexity is O(N), where N is the number of nodes in the linked list. We visit each node once during the reversal process.

Space Complexity:
The space complexity is O(1) since we are using a constant amount of extra space for the three pointers.
*/

class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        ListNode *current = head;
        ListNode *previous = nullptr;
        ListNode *next;

        while (current) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        return previous;
    }
};