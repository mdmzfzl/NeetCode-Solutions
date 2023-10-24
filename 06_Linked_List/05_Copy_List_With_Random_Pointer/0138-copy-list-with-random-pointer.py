"""
Problem: LeetCode 138 - Copy List with Random Pointer

Key Idea:
To create a deep copy of a linked list with random pointers, we can follow a three-step approach. First, we duplicate each node in the original list and insert the duplicates right after their corresponding original nodes. Second, we update the random pointers of the duplicate nodes to point to the correct nodes. Finally, we split the combined list into two separate lists: the original list and the duplicated list.

Time Complexity:
The time complexity of this solution is O(n), where n is the number of nodes in the linked list. We traverse the list three times, once to duplicate the nodes, once to update the random pointers, and once to split the lists.

Space Complexity:
The space complexity is O(n), as we need to create a duplicate node for each original node. Additionally, we use a dictionary to map original nodes to their corresponding duplicate nodes, which takes up O(n) extra space.
"""

# Definition for a Node.
# class Node:
#     def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
#         self.val = int(x)
#         self.next = next
#         self.random = random


class Solution:
    def copyRandomList(self, head: "Node") -> "Node":
        if not head:
            return None

        # Step 1: Duplicate nodes and insert them in between the original nodes
        current = head
        while current:
            duplicate = Node(current.val)
            duplicate.next = current.next
            current.next = duplicate
            current = duplicate.next

        # Step 2: Update random pointers for the duplicate nodes
        current = head
        while current:
            if current.random:
                current.next.random = current.random.next
            current = current.next.next

        # Step 3: Split the combined list into two separate lists
        original = head
        duplicate_head = head.next
        current = duplicate_head
        while original:
            original.next = original.next.next
            if current.next:
                current.next = current.next.next
            original = original.next
            current = current.next

        return duplicate_head
