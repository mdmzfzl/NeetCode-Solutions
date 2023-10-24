/*
Problem: LeetCode 543 - Diameter of Binary Tree

Description:
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is defined as the length of the longest path between any two nodes in the tree.
This path may or may not pass through the root.

Intuition:
To find the diameter of a binary tree, we need to determine the length of the longest path between any two nodes.
This can be achieved by calculating the maximum depth of each node's left and right subtrees and summing them up.
We can use a recursive approach to traverse the tree and update the diameter as we go.

Approach:
1. Implement a recursive function to find the diameter of the binary tree.
2. If the root is null, return 0 as the diameter.
3. Recursively calculate the maximum depth of the left subtree.
4. Recursively calculate the maximum depth of the right subtree.
5. Update the diameter by taking the maximum of the current diameter and the sum of the maximum depths of the left and right subtrees.
6. Return the maximum depth among the left and right subtrees, plus 1 for the current level.

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

// Definition for a binary tree node
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
  public:
    int diameterOfBinaryTree(TreeNode *root) {
        int diameter = 0;
        maxDepth(root, diameter);
        return diameter;
    }

  private:
    // Depth First Search
    int maxDepth(TreeNode *root, int &diameter) {
        // Base case: if the root is null, return 0
        if (root == nullptr) {
            return 0;
        }

        // Recursively calculate the maximum depth of the left and right subtrees
        int leftDepth = maxDepth(root->left, diameter);
        int rightDepth = maxDepth(root->right, diameter);
        // Update the diameter by taking the maximum of the current diameter and the sum of the maximum depths of the left and right subtrees
        diameter = max(diameter, leftDepth + rightDepth);
        // Return the maximum depth among the left and right subtrees, plus 1 for the current level
        return max(leftDepth, rightDepth) + 1;
    }
};
