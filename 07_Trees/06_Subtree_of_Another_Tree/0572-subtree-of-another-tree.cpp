/*
Problem: LeetCode 572 - Subtree of Another Tree

Description:
Given the roots of two binary trees, `s` and `t`, check if `t` is a subtree of `s`.
A subtree of a tree is a tree consisting of a node in `s` and all of its descendants.
The trees `s` and `t` have the same structure, and all the values of the nodes in `t` are also present in `s`.

Intuition:
To check if `t` is a subtree of `s`, we can perform a depth-first search (DFS) on `s` to find a node with the same value as the root of `t`.
Once we find a matching node, we can recursively check if the subtree rooted at that node is identical to `t`.

Approach:
1. Implement a recursive function to check if `t` is a subtree of `s`.
2. If `s` is null, return false as `t` cannot be a subtree of an empty tree.
3. Check if the current node in `s` is identical to `t`. If so, check if the subtree rooted at this node is identical to `t`.
4. If the subtree is identical, return true.
5. If not, recursively check if `t` is a subtree of the left subtree or the right subtree of `s`.
6. Return the logical OR of the above checks.

Time Complexity:
The time complexity of the approach is O(m * n), where m and n are the number of nodes in `s` and `t`, respectively. In the worst case, we may have to compare each node of `s` with `t`.

Space Complexity:
The space complexity is O(max(m, n)), where m and n are the number of nodes in `s` and `t`, respectively. This is the space used by the recursive call stack.

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
    bool isSubtree(TreeNode *s, TreeNode *t) {
        // Base case: if `s` is null, return false as `t` cannot be a subtree of an empty tree
        if (s == nullptr) {
            return false;
        }

        // Check if the current node in `s` is identical to `t`, and if the subtree rooted at this node is identical to `t`
        if (isIdentical(s, t)) {
            return true;
        }

        // Recursively check if `t` is a subtree of the left subtree or the right subtree of `s`
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }

  private:
    bool isIdentical(TreeNode *s, TreeNode *t) {
        // Base cases: if either `s` or `t` is null, return true only if both are null
        if (s == nullptr && t == nullptr) {
            return true;
        }

        if (s == nullptr || t == nullptr) {
            return false;
        }

        // Check if the current nodes have the same value and recursively check if their left and right subtrees are identical
        return (s->val == t->val) && isIdentical(s->left, t->left) && isIdentical(s->right, t->right);
    }
};