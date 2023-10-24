"""
Problem: LeetCode 102 - Binary Tree Level Order Traversal

Key Idea:
To perform level order traversal of a binary tree, we can use a breadth-first search (BFS) approach. We start with the root node, and in each iteration, we process all nodes at the current level before moving to the next level. We use a queue to keep track of nodes at each level.

Time Complexity:
The time complexity of this solution is O(n), where n is the number of nodes in the binary tree. We visit each node once during the BFS traversal.

Space Complexity:
The space complexity is O(w), where w is the maximum width of the binary tree (number of nodes in the widest level). In the worst case, the queue can hold all nodes in a single level.
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []

        result = []
        queue = [root]

        while queue:
            level = []
            next_level = []

            for node in queue:
                level.append(node.val)
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)

            result.append(level)
            queue = next_level

        return result
