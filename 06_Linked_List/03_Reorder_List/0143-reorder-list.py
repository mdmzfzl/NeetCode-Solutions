"""
Proble: LeetCode 143 - Reorder List

Key Idea:
To reorder a singly linked list, we can break the list into two halves, reverse the second half, and then merge the two halves alternatively. First, we find the middle of the list using the slow and fast pointer technique. We reverse the second half of the list in place. Finally, we merge the two halves by alternating nodes from each half.

Time Complexity:
The time complexity of this solution is O(n), where n is the number of nodes in the linked list. We traverse the list to find the middle, reverse the second half, and merge the two halves.

Space Complexity:
The space complexity is O(1), as no extra space is used other than a few variables to keep track of nodes and pointers.
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def reorderList(self, head: ListNode) -> None:
        if not head or not head.next or not head.next.next:
            return

        # Find the middle of the list
        slow, fast = head, head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        # Reverse the second half of the list
        prev, current = None, slow.next
        slow.next = None
        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node

        # Merge the two halves alternately
        p1, p2 = head, prev
        while p2:
            next_p1, next_p2 = p1.next, p2.next
            p1.next = p2
            p2.next = next_p1
            p1, p2 = next_p1, next_p2
