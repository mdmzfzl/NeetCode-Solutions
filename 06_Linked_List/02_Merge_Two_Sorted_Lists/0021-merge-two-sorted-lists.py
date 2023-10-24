"""
Problem: LeetCode 21 - Merge Two Sorted Lists

Key Idea:
To merge two sorted linked lists 'l1' and 'l2', we can create a new linked list 'dummy' to hold the merged result. We maintain two pointers, 'current' and 'prev', to traverse through the two input lists. At each step, we compare the values at the 'current' pointers of 'l1' and 'l2', and add the smaller value to the 'dummy' list. We then move the 'current' pointer of the list with the smaller value one step forward. After iterating through both lists, if any list still has remaining elements, we append them to the 'dummy' list.

Time Complexity:
The time complexity of this solution is O(n), where n is the total number of nodes in the merged list. We traverse each node once to merge the lists.

Space Complexity:
The space complexity is O(1), as no extra space is used other than a few variables to keep track of nodes and pointers.
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode()
        current = dummy

        while l1 and l2:
            if l1.val < l2.val:
                current.next = l1
                l1 = l1.next
            else:
                current.next = l2
                l2 = l2.next
            current = current.next

        if l1:
            current.next = l1
        elif l2:
            current.next = l2

        return dummy.next
