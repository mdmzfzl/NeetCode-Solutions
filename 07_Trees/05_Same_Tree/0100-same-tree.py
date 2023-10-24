"""
Problem: LeetCode 100 - Same Tree

Key Idea:
To determine if two binary trees are the same, we can use a recursive approach. For each pair of corresponding nodes, we compare their values and recursively check the left and right subtrees. If the values are equal and the left and right subtrees are also equal, then the trees are the same.

Time Complexity:
The time complexity of this solution is O(n), where n is the number of nodes in the binary tree. We visit each node once to compare its values.

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
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if not p and not q:
            return True
        if not p or not q or p.val != q.val:
            return False
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
