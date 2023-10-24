"""
Problem: LeetCode 105 - Construct Binary Tree from Preorder and Inorder Traversal

Key Idea:
To construct a binary tree from its preorder and inorder traversals, we can use a recursive approach. The first element in the preorder list is the root of the current subtree. We locate its position in the inorder list to determine the left and right subtrees. We recursively construct the left and right subtrees for each subtree.

Time Complexity:
The time complexity of this solution is O(n), where n is the number of nodes in the binary tree. We visit each node once during the construction process.

Space Complexity:
The space complexity is O(n), where n is the number of nodes in the binary tree. In the worst case, the recursion stack can go as deep as the height of the tree.
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder or not inorder:
            return None

        root_val = preorder.pop(0)
        root = TreeNode(root_val)
        root_index = inorder.index(root_val)

        root.left = self.buildTree(preorder, inorder[:root_index])
        root.right = self.buildTree(preorder, inorder[root_index + 1 :])

        return root
