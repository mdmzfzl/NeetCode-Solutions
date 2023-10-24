"""
Problem: LeetCode 297 - Serialize and Deserialize Binary Tree

Key Idea:
To serialize a binary tree, we can perform a preorder traversal and serialize the nodes into a string. When deserializing, we split the string into a list of values and reconstruct the binary tree using a recursive approach.

Time Complexity:
- Serialization: The time complexity of serializing the binary tree is O(n), where n is the number of nodes in the tree. We visit each node once during the traversal.
- Deserialization: The time complexity of deserializing the binary tree is also O(n), as we process each value in the list exactly once.

Space Complexity:
- Serialization: The space complexity for serializing is O(n), where n is the number of nodes in the tree. This is due to the space required to store the serialized string.
- Deserialization: The space complexity for deserializing is O(n), where n is the number of nodes in the tree. This is due to the space required for the recursion stack during deserialization.
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """

        def preorder(node):
            if not node:
                return "None,"
            return str(node.val) + "," + preorder(node.left) + preorder(node.right)

        return preorder(root)

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """

        def build_tree(values):
            if values[0] == "None":
                values.pop(0)
                return None

            root = TreeNode(int(values.pop(0)))
            root.left = build_tree(values)
            root.right = build_tree(values)

            return root

        values = data.split(",")
        return build_tree(values[:-1])


# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
