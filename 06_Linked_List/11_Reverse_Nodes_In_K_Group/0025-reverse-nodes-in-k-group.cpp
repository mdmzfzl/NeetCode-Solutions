/*
Problem: LeetCode 25 - Reverse Nodes in k-Group

Description:
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of k, then the remaining nodes should remain as it is.

Intuition:
To reverse the nodes in k-groups, we can use a recursive approach.
We start by finding the k+1-th node in the linked list, as it will be the new head of the reversed k-group.
Then we reverse the current k-group and connect it to the next reversed k-group.
We repeat this process until we reach the end of the linked list.

Approach:
1. Create a struct ListNode to represent the nodes of the linked list.
2. Implement a helper function to reverse a k-group of nodes, which takes the head and tail of the group as input and returns the new head of the reversed group.
3. Initialize a dummy ListNode to build the final result list.
4. Create a pointer current to iterate through the linked list.
5. Find the k+1-th node from the current node.
6. If the k+1-th node exists, reverse the current k-group and update the pointers accordingly.
7. Append the reversed k-group to the dummy list and move the current pointer to the k+1-th node.
8. Repeat steps 5 to 7 until we reach the end of the linked list.
9. Finally, return the next node of the dummy list, which will be the head of the modified list.

Time Complexity:
The time complexity is O(n), where n is the number of nodes in the linked list. We visit each node once during the reversal process.

Space Complexity:
The space complexity is O(1), as we use only a constant amount of extra space throughout the process.
*/

class Solution {
  public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *current = dummy;

        while (current) {
            ListNode *groupStart = current->next;
            ListNode *groupEnd = current;

            // Find k+1-th node
            for (int i = 0; i < k && groupEnd; i++) {
                groupEnd = groupEnd->next;
            }

            if (!groupEnd) {
                break; // Remaining nodes are less than k
            }

            ListNode *nextGroup = groupEnd->next;
            // Reverse the current k-group
            reverseGroup(groupStart, groupEnd);
            // Connect reversed k-group to the previous group
            current->next = groupEnd;
            groupStart->next = nextGroup;
            // Move the current pointer to the next group
            current = groupStart;
        }

        return dummy->next;
    }

  private:
    // Helper function to reverse a k-group of nodes
    void reverseGroup(ListNode *head, ListNode *tail) {
        ListNode *prev = nullptr;
        ListNode *current = head;

        while (current != tail) {
            ListNode *nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        tail->next = prev;
    }
};