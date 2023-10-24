/*
Problem: LeetCode 124 - Binary Tree Maximum Path Sum

Description:
Given a non-empty binary tree, find the maximum path sum.
A path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections.
The path must contain at least one node and does not need to go through the root.

Intuition:
The maximum path sum can be found by considering the maximum sum path for each node in the binary tree.
A path can include nodes from the left subtree, the current node, and nodes from the right subtree.
We need to keep track of the maximum sum encountered so far as we traverse the tree.

Approach:
1. Create a helper function, `maxPathSumHelper`, to calculate the maximum path sum for each node.
2. In the `maxPathSumHelper` function:
   - Check if the current node is `nullptr`. If so, return 0 to represent an empty path.
   - Recursively call the `maxPathSumHelper` function for the left subtree and store the result in `leftSum`.
   - Recursively call the `maxPathSumHelper` function for the right subtree and store the result in `rightSum`.
   - Calculate the maximum sum path that includes the current node:
     - Calculate `maxChildSum` as the maximum between `leftSum` and `rightSum`, or 0 if they are negative.
     - Calculate `maxSum` as the maximum between `leftSum + rightSum + node->val` and `node->val`.
   - Update the maximum sum encountered so far by comparing `maxSum` with the current maximum.
   - Return the maximum sum path that includes the current node by adding `node->val` to `maxChildSum`.
3. Call the `maxPathSumHelper` function with the root node.
4. Return the maximum sum encountered during the traversal.

Time Complexity:
The time complexity of the approach is O(n), where n is the number of nodes in the binary tree. We visit each node once during the traversal.

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
    int maxPathSum(TreeNode *root) {
        int maxSum = INT_MIN;
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }

  private:
    int maxPathSumHelper(TreeNode *node, int &maxSum) {
        if (node == nullptr) {
            return 0;
        }

        // Recursively calculate the maximum path sum for the left and right subtrees
        int leftSum = maxPathSumHelper(node->left, maxSum);
        int rightSum = maxPathSumHelper(node->right, maxSum);
        // Calculate the maximum sum path that includes the current node
        int maxChildSum = max(max(leftSum, rightSum), 0);
        int maxSumWithNode = max(maxChildSum + node->val, leftSum + rightSum + node->val);
        maxSum = max(maxSum, maxSumWithNode);
        // Return the maximum sum path that includes the current node by adding it to the maximum child sum
        return max(maxChildSum + node->val, node->val);
    }
};