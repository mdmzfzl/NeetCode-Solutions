"""
Problem: LeetCode 98 - Validate Binary Search Tree

Key Idea:
To validate if a binary tree is a valid binary search tree (BST), we can perform an in-order traversal and check if the values are in ascending order. During the in-order traversal, we keep track of the previously visited node's value and compare it with the current node's value.

Time Complexity:
The time complexity of this solution is O(n), where n is the number of nodes in the binary tree. We visit each node once during the in-order traversal.

Space Complexity:
The space complexity is O(h), where h is the height of the binary tree. In the worst case, the recursion stack can go as deep as the height of the tree.
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def inorder_traversal(node, prev):
            if not node:
                return True

            if not inorder_traversal(node.left, prev):
                return False

            if prev[0] is not None and node.val <= prev[0]:
                return False
            prev[0] = node.val

            return inorder_traversal(node.right, prev)

        prev = [None]
        return inorder_traversal(root, prev)
