/*
Problem: LeetCode 104 - Maximum Depth of Binary Tree

Description:
Given the root of a binary tree, return its maximum depth.

Intuition:
The maximum depth of a binary tree is the number of edges in the longest path from the root node to any leaf node. We can find the maximum depth by recursively traversing the tree and keeping track of the depth at each level.

Approach:
1. Implement a recursive function to find the maximum depth of the binary tree.
2. If the root is null, return 0.
3. Recursively calculate the maximum depth of the left subtree.
4. Recursively calculate the maximum depth of the right subtree.
5. Return the maximum depth among the left and right subtrees, plus 1 for the current level.

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
    int maxDepth(TreeNode *root) {
        // Base case: if the root is null, return 0
        if (root == nullptr) {
            return 0;
        }

        // Recursively calculate the maximum depth of the left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        // Return the maximum depth among the left and right subtrees, plus 1 for the current level
        return max(leftDepth, rightDepth) + 1;
    }
};


// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(!root)
//             return 0;

//         return 1 + max(maxDepth(root->left), maxDepth(root->right));
//     }
// };