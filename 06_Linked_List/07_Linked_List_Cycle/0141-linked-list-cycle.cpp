/*
Problem: LeetCode 141 - Linked List Cycle

Description:
Given a linked list, determine if it has a cycle in it.
To represent a cycle in the given linked list, we use an integer pos,
which represents the position (0-indexed) in the linked list where the tail connects to.
If pos is -1, there is no cycle in the linked list.

Intuition:
To detect if there is a cycle in a linked list, we can use the two-pointer technique.
We maintain two pointers, slow and fast. The slow pointer moves one step at a time,
while the fast pointer moves two steps at a time. If there is a cycle in the linked list,
the fast pointer will eventually catch up to the slow pointer, and they will meet.

Approach:
1. Initialize two pointers, slow and fast, to the head of the linked list.
2. Move the slow pointer one step and the fast pointer two steps at a time.
3. If there is a cycle, the fast pointer will eventually catch up to the slow pointer.
4. If the fast pointer becomes null, there is no cycle in the linked list.
5. Return true if the two pointers meet, otherwise return false.

Time Complexity:
The time complexity is O(n), where n is the number of nodes in the linked list.
In the worst case, the fast pointer traverses the linked list twice.

Space Complexity:
The space complexity is O(1) since we only use two pointers to detect the cycle.
*/

class Solution {
  public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};