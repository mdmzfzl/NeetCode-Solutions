/*
Problem: LeetCode 19 - Remove Nth Node From End of List

Description:
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Intuition:
To remove the nth node from the end of the list, we can use the two-pointer approach. We will use two pointers, first and second, with a gap of n nodes between them. When the second pointer reaches the end of the list, the first pointer will be pointing to the nth node from the end. We can then remove that node.

Approach:
1. Create a dummy node and set it as the head of the list to handle cases where we need to remove the head.
2. Initialize both first and second pointers to the dummy node.
3. Move the second pointer n+1 times to create a gap of n nodes between first and second.
4. Move both first and second pointers simultaneously until the second pointer reaches the end.
5. Remove the nth node by updating the next pointer of the previous node to skip the nth node.

Time Complexity:
The time complexity is O(N), where N is the number of nodes in the linked list, as we need to traverse the list once to find the nth node from the end.

Space Complexity:
The space complexity is O(1) as we are using constant extra space for the pointers.
*/

class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *first = dummy;
        ListNode *second = dummy;

        // Move second pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            second = second->next;
        }

        // Move both pointers simultaneously until second reaches the end
        while (second) {
            first = first->next;
            second = second->next;
        }

        // Remove the nth node by updating the next pointer of the previous node
        ListNode *temp = first->next;
        first->next = first->next->next;
        delete temp;
        return dummy->next;
    }
};