"""
Problem: LeetCode 104 - Maximum Depth of Binary Tree

Key Idea:
To find the maximum depth of a binary tree, we can use a recursive approach. For each node, the maximum depth is the maximum of the depths of its left and right subtrees, plus one. We start from the root and recursively calculate the maximum depth for each subtree.

Time Complexity:
The time complexity of this solution is O(n), where n is the number of nodes in the binary tree. We visit each node once to calculate its depth.

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
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0

        left_depth = self.maxDepth(root.left)
        right_depth = self.maxDepth(root.right)

        return max(left_depth, right_depth) + 1
