"""
Problem: LeetCode 19 - Remove Nth Node From End of List

Key Idea:
To remove the nth node from the end of a singly linked list, we can use the two-pointer approach. We maintain two pointers, 'fast' and 'slow', where 'fast' moves n nodes ahead of 'slow'. Then we move both pointers simultaneously until 'fast' reaches the end of the list. At this point, 'slow' will be pointing to the node just before the node to be removed. We update the 'slow.next' pointer to skip the node to be removed.

Time Complexity:
The time complexity of this solution is O(n), where n is the number of nodes in the linked list. We traverse the list twice, once to find the length of the list and once to remove the node.

Space Complexity:
The space complexity is O(1), as no extra space is used other than a few variables to keep track of nodes and pointers.
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        fast = slow = dummy

        # Move 'fast' n nodes ahead
        for _ in range(n):
            fast = fast.next

        # Move both pointers until 'fast' reaches the end
        while fast.next:
            fast = fast.next
            slow = slow.next

        # Remove the nth node from the end
        slow.next = slow.next.next

        return dummy.next
