"""
Problem: LeetCode 2 - Add Two Numbers

Key Idea:
To add two numbers represented by linked lists, we can simulate the addition digit by digit while considering carry. We maintain a dummy node to build the resulting linked list. We iterate through the input lists, summing the corresponding digits along with any carry from the previous digit. We update the carry and create a new node with the sum digit. After processing both lists, if there is a carry remaining, we add a new node with the carry.

Time Complexity:
The time complexity of this solution is O(max(m, n)), where m and n are the lengths of the input linked lists. We traverse both lists once.

Space Complexity:
The space complexity is O(max(m, n)), as we create a new linked list to store the result. Additionally, we use a few extra variables to keep track of nodes and values.
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode()
        current = dummy
        carry = 0

        while l1 or l2:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            total = val1 + val2 + carry

            carry = total // 10
            digit = total % 10

            current.next = ListNode(digit)
            current = current.next

            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

        if carry:
            current.next = ListNode(carry)

        return dummy.next
