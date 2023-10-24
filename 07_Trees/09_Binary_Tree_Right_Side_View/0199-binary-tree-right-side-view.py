"""
Problem: LeetCode 199 - Binary Tree Right Side View

Key Idea:
To obtain the right side view of a binary tree, we can perform a level order traversal using a breadth-first search (BFS) approach. For each level, we add the last node's value to the result list. This way, we capture the rightmost nodes at each level.

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
    def rightSideView(self, root: TreeNode) -> List[int]:
        if not root:
            return []

        result = []
        queue = [root]

        while queue:
            level_size = len(queue)

            for i in range(level_size):
                node = queue.pop(0)
                if i == level_size - 1:
                    result.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

        return result
