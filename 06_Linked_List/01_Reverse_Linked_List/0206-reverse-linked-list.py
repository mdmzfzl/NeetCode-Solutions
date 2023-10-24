"""
Problem: LeetCode 206 - Reverse Linked List

Key Idea:
To reverse a singly linked list, we need to reverse the direction of the pointers while traversing the list. We maintain three pointers: 'prev' (to keep track of the previous node), 'current' (to keep track of the current node), and 'next_node' (to keep track of the next node in the original list). In each iteration, we update the 'current.next' pointer to point to the 'prev' node, and then move 'prev' and 'current' pointers one step forward. We repeat this process until we reach the end of the original list, and the 'prev' pointer will be pointing to the new head of the reversed list.

Time Complexity:
The time complexity of this solution is O(n), where n is the number of nodes in the linked list. We traverse each node once to reverse the list.

Space Complexity:
The space complexity is O(1), as no extra space is used other than a few variables to keep track of nodes and pointers.
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        current = head

        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node

        return prev
