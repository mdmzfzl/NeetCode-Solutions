"""
Problem: LeetCode 543 - Diameter of Binary Tree

Key Idea:
To find the diameter of a binary tree (the length of the longest path between any two nodes), we can use a recursive approach. For each node, the longest path passes either through the node or doesn't. The diameter is the maximum of three values: the diameter of the left subtree, the diameter of the right subtree, and the sum of the heights of the left and right subtrees (if the path passes through the node).

Time Complexity:
The time complexity of this solution is O(n), where n is the number of nodes in the binary tree. We visit each node once to calculate the diameter.

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
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        def height(node):
            if not node:
                return 0
            left_height = height(node.left)
            right_height = height(node.right)
            self.diameter = max(self.diameter, left_height + right_height)
            return max(left_height, right_height) + 1

        self.diameter = 0
        height(root)
        return self.diameter
