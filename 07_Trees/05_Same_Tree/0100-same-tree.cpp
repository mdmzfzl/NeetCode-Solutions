/*
Problem: LeetCode 100 - Same Tree

Description:
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Intuition:
To determine if two binary trees are the same, we need to compare their structures and values.
We can use a recursive approach to check if the current nodes of both trees are equal and if their left and right subtrees are also equal.

Approach:
1. Implement a recursive function to check if two binary trees are the same.
2. If both roots are null, return true as they are considered the same.
3. If one of the roots is null and the other is not, or if the values of the roots are different, return false.
4. Recursively check if the left subtrees of both trees are the same.
5. Recursively check if the right subtrees of both trees are the same.
6. Return the logical AND of the above checks.

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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Base case: if both roots are null, return true
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // Check if either root is null or their values are different
        if (p == nullptr || q == nullptr || p->val != q->val) {
            return false;
        }

        // Recursively check if the left subtrees and right subtrees are the same
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
