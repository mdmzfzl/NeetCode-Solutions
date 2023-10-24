/*
Problem: LeetCode 110 - Balanced Binary Tree

Description:
Given a binary tree, determine if it is height-balanced.
A height-balanced binary tree is defined as a binary tree in which the left and right subtrees' heights differ by at most one.

Intuition:
To determine if a binary tree is height-balanced, we need to check if the heights of its left and right subtrees differ by at most one.
We can calculate the height of each subtree recursively and compare the heights at each level to check for balance.

Approach:
1. Implement a recursive function to check if the binary tree is height-balanced.
2. If the root is null, return true as it is considered height-balanced.
3. Recursively calculate the height of the left subtree.
4. Recursively calculate the height of the right subtree.
5. Check if the heights of the left and right subtrees differ by more than one. If so, return false.
6. If the heights are balanced, return true if both the left and right subtrees are also balanced; otherwise, return false.

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
    bool isBalanced(TreeNode *root) {
        return checkHeight(root) != -1;
    }

  private:
    int checkHeight(TreeNode *root) {
        // Base case: if the root is null, return 0
        if (root == nullptr) {
            return 0;
        }

        // Recursively calculate the height of the left and right subtrees
        int leftHeight = checkHeight(root->left);
        int rightHeight = checkHeight(root->right);

        // If the left or right subtree is not balanced, return -1
        if (leftHeight == -1 || rightHeight == -1) {
            return -1;
        }

        // If the heights of the left and right subtrees differ by more than one, return -1
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        // Return the maximum height between the left and right subtrees, plus 1 for the current level
        return max(leftHeight, rightHeight) + 1;
    }
};