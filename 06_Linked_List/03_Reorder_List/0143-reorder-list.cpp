/*
Problem: LeetCode 143 - Reorder List

Description:
Given a singly linked list L: L0 -> L1 -> ... -> Ln-1 -> Ln,
reorder it to: L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ...

You may not modify the values in the list's nodes, only nodes itself may be changed.

Intuition:
To reorder the linked list, we can divide the problem into three main steps:
1. Find the middle of the list using the slow and fast pointer approach.
2. Reverse the second half of the list.
3. Merge the first half and the reversed second half together to form the reordered list.

Approach:
1. Use the slow and fast pointer approach to find the middle of the list.
2. Reverse the second half of the list.
3. Merge the first half and the reversed second half together to form the reordered list.

Time Complexity:
The time complexity is O(N), where N is the number of nodes in the linked list, as we need to traverse the list twice (once to find the middle and once to reverse the second half).

Space Complexity:
The space complexity is O(1) as we are using constant extra space for the pointers.
*/

class Solution {
  public:
    void reorderList(ListNode *head) {
        if (!head || !head->next || !head->next->next) {
            return;
        }

        // Step 1: Find the middle of the list
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode *prev = nullptr;
        ListNode *curr = slow->next;
        slow->next = nullptr;

        while (curr) {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3: Merge the first half and the reversed second half
        ListNode *first = head;
        ListNode *second = prev;

        while (second) {
            ListNode *nextFirst = first->next;
            ListNode *nextSecond = second->next;
            first->next = second;
            second->next = nextFirst;
            first = nextFirst;
            second = nextSecond;
        }
    }
};