"""
Problem: LeetCode 57 - Subtree of Another Tree

Key Idea:
To check if one binary tree is a subtree of another, we can use a recursive approach. For each node in the main tree, we check if the current subtree rooted at that node is equal to the given subtree. If not, we recursively check the left and right subtrees.

Time Complexity:
The time complexity of this solution is O(m * n), where m is the number of nodes in the main tree and n is the number of nodes in the given subtree. In the worst case, we might need to traverse the entire main tree to find a matching subtree.

Space Complexity:
The space complexity is O(h), where h is the height of the main tree. In the worst case, the recursion stack can go as deep as the height of the tree.
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        if not s:
            return False
        if self.isSameTree(s, t):
            return True
        return self.isSubtree(s.left, t) or self.isSubtree(s.right, t)

    def isSameTree(self, p, q):
        if not p and not q:
            return True
        if not p or not q or p.val != q.val:
            return False
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
