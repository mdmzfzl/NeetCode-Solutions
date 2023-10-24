"""
Problem: LeetCode 230 - Kth Smallest Element in a BST

Key Idea:
To find the kth smallest element in a binary search tree (BST), we can perform an in-order traversal and keep track of the count of visited nodes. When the count reaches k, we've found the kth smallest element.

Time Complexity:
The time complexity of this solution is O(h + k), where h is the height of the binary tree. In the average case, when the tree is balanced, the height is O(log n), where n is the number of nodes in the tree. In the worst case, when the tree is skewed, the height is O(n). The additional factor of k is due to the in-order traversal.

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
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        def inorder_traversal(node):
            if not node:
                return []

            left = inorder_traversal(node.left)
            right = inorder_traversal(node.right)

            return left + [node.val] + right

        inorder_values = inorder_traversal(root)
        return inorder_values[k - 1]
