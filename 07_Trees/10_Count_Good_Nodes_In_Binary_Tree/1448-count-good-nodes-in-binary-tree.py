"""
Problem: LeetCode 1448 - Count Good Nodes in Binary Tree

Key Idea:
To count the number of good nodes in a binary tree, we can use a recursive depth-first search (DFS) approach. For each node, we keep track of the maximum value encountered on the path from the root to the current node. If the value of the current node is greater than or equal to the maximum value on the path, it is a good node. We increment the count and continue the DFS for the left and right subtrees.

Time Complexity:
The time complexity of this solution is O(n), where n is the number of nodes in the binary tree. We visit each node once during the DFS traversal.

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
    def goodNodes(self, root: TreeNode) -> int:
        def dfs(node, max_val):
            if not node:
                return 0

            if node.val >= max_val:
                max_val = node.val
                count = 1
            else:
                count = 0

            count += dfs(node.left, max_val)
            count += dfs(node.right, max_val)

            return count

        return dfs(root, float("-inf"))
