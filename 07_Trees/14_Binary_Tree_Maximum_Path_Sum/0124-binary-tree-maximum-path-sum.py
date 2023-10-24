"""
Problem: LeetCode 124 - Binary Tree Maximum Path Sum

Key Idea:
To find the maximum path sum in a binary tree, we can use a recursive approach. For each node, we calculate the maximum path sum that includes that node. This can be either the node's value itself or the value plus the maximum path sum from its left and right subtrees. We update the global maximum as we traverse the tree.

Time Complexity:
The time complexity of this solution is O(n), where n is the number of nodes in the binary tree. We visit each node once during the traversal.

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
    def maxPathSum(self, root: TreeNode) -> int:
        def maxPathSumHelper(node):
            if not node:
                return 0

            left_sum = max(0, maxPathSumHelper(node.left))
            right_sum = max(0, maxPathSumHelper(node.right))

            self.max_sum = max(self.max_sum, left_sum + right_sum + node.val)

            return max(left_sum, right_sum) + node.val

        self.max_sum = float("-inf")
        maxPathSumHelper(root)

        return self.max_sum
