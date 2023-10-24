"""
Problem: LeetCode 141 - Linked List Cycle

Key Idea:
To detect a cycle in a linked list, we can use the Floyd's Tortoise and Hare algorithm. We maintain two pointers, 'slow' and 'fast', where 'slow' moves one step at a time and 'fast' moves two steps at a time. If there is a cycle in the linked list, the two pointers will eventually meet at some point. If there is no cycle, the 'fast' pointer will reach the end of the list. 

Time Complexity:
The time complexity of this solution is O(n), where n is the number of nodes in the linked list. In the worst case, both pointers traverse the entire list.

Space Complexity:
The space complexity is O(1), as no extra space is used other than a few variables to keep track of nodes and pointers.
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if not head or not head.next:
            return False

        slow = head
        fast = head.next

        while slow != fast:
            if not fast or not fast.next:
                return False
            slow = slow.next
            fast = fast.next.next

        return True
