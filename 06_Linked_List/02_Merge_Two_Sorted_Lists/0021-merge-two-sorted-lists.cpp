/*
Problem: LeetCode 21 - Merge Two Sorted Lists

Description:
Merge two sorted linked lists and return it as a new sorted list.
The new list should be made by splicing together the nodes of the first two lists.

Intuition:
To merge two sorted linked lists, we can use a simple approach where we compare the values of the nodes at the head of both lists.
We create a dummy node to serve as the new merged list's head. Then, we compare the values of the current nodes from both lists.
Whichever node's value is smaller, we append that node to the merged list and move its pointer to the next node.
We repeat this process until we have traversed both input lists completely.

Approach:
1. Create a dummy node as the merged list's head.
2. Initialize two pointers, "curr" and "dummy," both pointing to the dummy node.
3. While both input lists are not empty:
   a. Compare the values of the current nodes from both lists.
   b. Append the node with the smaller value to the merged list.
   c. Move the pointer of the merged list and the pointer of the selected node's list to their next nodes.
4. If any of the input lists still has nodes remaining, append the rest of that list to the merged list.
5. Return the merged list's head, which is the next node of the dummy node.

Time Complexity:
The time complexity is O(N+M), where N and M are the number of nodes in the input lists, as we need to visit each node once.

Space Complexity:
The space complexity is O(1), as we only use a constant amount of extra space for the pointers.
*/

class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }

            curr = curr->next;
        }

        if (l1) {
            curr->next = l1;
        } else {
            curr->next = l2;
        }

        return dummy->next;
    }
};