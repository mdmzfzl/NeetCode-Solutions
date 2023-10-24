"""
Problem: LeetCode 235 - Lowest Common Ancestor of a Binary Search Tree

Key Idea:
To find the lowest common ancestor (LCA) of two nodes in a binary search tree (BST), we can use a recursive approach. We compare the values of the two nodes with the current node's value. If both nodes are in the left subtree, we move to the left child. If both nodes are in the right subtree, we move to the right child. If one node is in the left subtree and the other is in the right subtree, we've found the LCA.

Time Complexity:
The time complexity of this solution is O(h), where h is the height of the BST. In the worst case, we might need to traverse the height of the tree to find the LCA.

Space Complexity:
The space complexity is O(h), where h is the height of the BST. In the worst case, the recursion stack can go as deep as the height of the tree.
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def lowestCommonAncestor(
        self, root: TreeNode, p: TreeNode, q: TreeNode
    ) -> TreeNode:
        if root.val > p.val and root.val > q.val:
            return self.lowestCommonAncestor(root.left, p, q)
        elif root.val < p.val and root.val < q.val:
            return self.lowestCommonAncestor(root.right, p, q)
        else:
            return root
