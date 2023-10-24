/*
Problem: LeetCode 1448 - Count Good Nodes in Binary Tree

Description:
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
Return the number of good nodes in the binary tree.

Intuition:
To count the number of good nodes in a binary tree, we can perform a depth-first search (DFS) and keep track of the maximum value seen so far.
For each node, if its value is greater than or equal to the maximum value seen so far, we increment the count of good nodes.

Approach:
1. Create a helper function, `countGoodNodesHelper`, to perform the DFS traversal and count the good nodes.
2. Initialize a count variable to keep track of the number of good nodes.
3. Start the DFS traversal from the root node with the initial maximum value as negative infinity.
4. In the `countGoodNodesHelper` function:
   - Check if the current node is nullptr. If so, return.
   - Update the maximum value seen so far to be the maximum of the current node's value and the current maximum value.
   - If the current node's value is greater than or equal to the maximum value seen so far, increment the count of good nodes.
   - Recursively call the `countGoodNodesHelper` function for the left and right children of the current node.
5. Return the count of good nodes.

Time Complexity:
The time complexity of the approach is O(n), where n is the number of nodes in the binary tree. We visit each node once during the DFS traversal.

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
    int goodNodes(TreeNode *root) {
        return countGoodNodesHelper(root, INT_MIN);
    }

  private:
    int countGoodNodesHelper(TreeNode *node, int maxSoFar) {
        if (node == nullptr) {
            return 0;
        }

        int count = 0;

        if (node->val >= maxSoFar) {
            count++;
        }

        int newMax = max(node->val, maxSoFar);
        count += countGoodNodesHelper(node->left, newMax);
        count += countGoodNodesHelper(node->right, newMax);
        return count;
    }
};