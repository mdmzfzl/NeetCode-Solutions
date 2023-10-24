/*
Problem: LeetCode 2 - Add Two Numbers

Description:
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

Intuition:
We can traverse the two linked lists simultaneously, adding the digits at the same position and keeping track of the carry. As we move forward, we create a new node for the sum and update the carry for the next iteration. If any linked list has more digits left, we continue the process until both lists are fully traversed.

Approach:
1. Initialize a dummy node to the head of the result list.
2. Initialize variables `carry` and `sum` to 0.
3. Traverse both linked lists simultaneously until both are fully traversed.
4. At each step, compute the sum of digits and the carry for the next iteration.
5. Create a new node with the sum and attach it to the result list.
6. Move the current pointers of both input lists to the next nodes.
7. If any list has remaining digits, continue adding them to the result.
8. Return the head of the result list after skipping the dummy node.

Time Complexity:
The time complexity is O(max(N, M)), where N and M are the number of nodes in the input linked lists. We traverse both lists once.

Space Complexity:
The space complexity is O(max(N, M)), where N and M are the number of nodes in the input linked lists. The extra space is used to store the result list.
*/

class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *current = dummy;
        int carry = 0;

        while (l1 || l2) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        if (carry) {
            current->next = new ListNode(carry);
        }

        return dummy->next;
    }
};