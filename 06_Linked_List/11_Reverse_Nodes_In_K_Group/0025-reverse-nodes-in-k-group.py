"""
Problem: LeetCode 25 - Reverse Nodes in k-Group

Key Idea:
To reverse nodes in k-group, we can use a recursive approach. We traverse the linked list in groups of k nodes, reversing each group. For each group, we maintain pointers to the group's first node ('start') and the group's last node ('end'). We reverse the group in-place and connect the previous group's 'end' to the reversed group's 'start'. We then recursively reverse the remaining part of the linked list.

Time Complexity:
The time complexity of this solution is O(n), where n is the number of nodes in the linked list. We process each node exactly once in groups of k nodes.

Space Complexity:
The space complexity is O(k), as we use a constant amount of extra space for the pointers and variables during the recursion.
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if not head or k == 1:
            return head

        # Count the number of nodes in the list
        count = 0
        current = head
        while current:
            count += 1
            current = current.next

        if count < k:
            return head

        # Reverse the first k nodes
        prev, current = None, head
        for _ in range(k):
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node

        # Recursively reverse the remaining part of the list
        head.next = self.reverseKGroup(current, k)

        return prev
