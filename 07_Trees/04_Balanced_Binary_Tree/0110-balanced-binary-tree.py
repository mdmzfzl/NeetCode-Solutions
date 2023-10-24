"""
Problem: LeetCode 110 - Balanced Binary Tree

Key Idea:
To check if a binary tree is balanced, we can use a recursive approach. For each node, we calculate the height of its left and right subtrees. If the difference in heights is greater than 1, the tree is not balanced. We continue this process for all nodes, recursively checking each subtree.

Time Complexity:
The time complexity of this solution is O(n), where n is the number of nodes in the binary tree. We visit each node once to calculate its height.

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
    def isBalanced(self, root: TreeNode) -> bool:
        def height(node):
            if not node:
                return 0
            left_height = height(node.left)
            right_height = height(node.right)
            if abs(left_height - right_height) > 1:
                return float("inf")  # Indicate imbalance
            return max(left_height, right_height) + 1

        return height(root) != float("inf")
