/*
Problem: LeetCode 226 - Invert Binary Tree

Description:
Given the root of a binary tree, invert the tree and return its root.

Intuition:
To invert a binary tree, we need to swap the left and right subtrees of each node. This can be done recursively, starting from the root node and swapping the children of each node.

Approach:
1. Implement a recursive function to invert the binary tree.
2. If the root is null, return null.
3. Swap the left and right children of the root node.
4. Recursively invert the left and right subtrees.
5. Return the modified root.

Time Complexity:
The time complexity of the approach is O(n), where n is the number of nodes in the binary tree. We visit each node once.

Space Complexity:
The space complexity is O(h), where h is the height of the binary tree. This is the space used by the recursive call stack.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
  public:
    TreeNode *invertTree(TreeNode *root) {
        // Base case: if the root is null, return null
        if (root == nullptr) {
            return nullptr;
        }

        // Swap the left and right children of the root node
        swap(root->left, root->right);
        // Recursively invert the left and right subtrees
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
