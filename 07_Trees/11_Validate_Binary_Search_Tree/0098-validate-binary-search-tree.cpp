/*
Problem: LeetCode 98 - Validate Binary Search Tree

Description:
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

Intuition:
A binary search tree (BST) is a binary tree in which the value of each node is greater than all the values in its left subtree and less than all the values in its right subtree.
To validate a BST, we can perform an in-order traversal and check if the values are in ascending order.

Approach:
1. Initialize a previous value to store the last visited value during the in-order traversal.
2. Create a helper function, `isValidBSTHelper`, to perform the in-order traversal and validate the BST.
3. In the `isValidBSTHelper` function:
   - Check if the current node is `nullptr`. If so, return true since it does not violate the BST property.
   - Recursively call the `isValidBSTHelper` function for the left subtree. If it returns false, return false.
   - Check if the current node's value is less than or equal to the previous value. If so, return false.
   - Update the previous value to be the current node's value.
   - Recursively call the `isValidBSTHelper` function for the right subtree. If it returns false, return false.
4. Return true if the entire tree has been traversed without any violations.

Time Complexity:
The time complexity of the approach is O(n), where n is the number of nodes in the binary tree. We visit each node once during the in-order traversal.

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
    bool isValidBST(TreeNode *root) {
        long long prev = LLONG_MIN; // Use long long to handle edge case with INT_MIN
        return isValidBSTHelper(root, prev);
    }

  private:
    bool isValidBSTHelper(TreeNode *node, long long &prev) {
        if (node == nullptr) {
            return true;
        }

        if (!isValidBSTHelper(node->left, prev)) {
            return false;
        }

        if (node->val <= prev) {
            return false;
        }

        prev = node->val;
        return isValidBSTHelper(node->right, prev);
    }
};
