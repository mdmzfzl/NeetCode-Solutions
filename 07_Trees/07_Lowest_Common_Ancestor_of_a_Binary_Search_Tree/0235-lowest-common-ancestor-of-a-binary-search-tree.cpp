/*
Problem: LeetCode 235 - Lowest Common Ancestor of a Binary Search Tree

Description:
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
According to the definition of LCA on Wikipedia: "The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself)."

Intuition:
The key property of a binary search tree (BST) is that for every node, its left subtree contains values smaller than the node's value, and its right subtree contains values greater than the node's value.
To find the lowest common ancestor (LCA) of two nodes in a BST, we can take advantage of this property to navigate through the tree and determine the LCA based on the values of the nodes.

Approach:
1. Start from the root of the BST.
2. If both `p` and `q` are smaller than the current node, the LCA lies in the left subtree. Recurse on the left subtree.
3. If both `p` and `q` are greater than the current node, the LCA lies in the right subtree. Recurse on the right subtree.
4. If neither of the above conditions is true, then the current node is the LCA.

Time Complexity:
The time complexity of the approach is O(h), where h is the height of the BST. In the worst case, we need to traverse the entire height of the BST.

Space Complexity:
The space complexity is O(h), where h is the height of the BST. This is the space used by the recursive call stack.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        // If both `p` and `q` are smaller than the current node, recurse on the left subtree
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        // If both `p` and `q` are greater than the current node, recurse on the right subtree
        else if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        // If neither of the above conditions is true, return the current node as the LCA
        else {
            return root;
        }
    }
};