/*
Problem: LeetCode 230 - Kth Smallest Element in a BST

Description:
Given the root of a binary search tree (BST), return the kth smallest element in the BST.

Intuition:
In a binary search tree (BST), the left subtree contains smaller elements, and the right subtree contains larger elements.
To find the kth smallest element, we can perform an in-order traversal and keep track of the count of visited nodes.

Approach:
1. Create a helper function, `kthSmallestHelper`, to perform the in-order traversal and find the kth smallest element.
2. Initialize a count variable to keep track of the number of visited nodes.
3. Start the in-order traversal from the root node.
4. In the `kthSmallestHelper` function:
   - Check if the current node is `nullptr`. If so, return -1 to indicate an invalid result.
   - Recursively call the `kthSmallestHelper` function for the left subtree. If the result is not -1, return the result.
   - Increment the count of visited nodes. If the count equals k, return the current node's value.
   - Recursively call the `kthSmallestHelper` function for the right subtree. If the result is not -1, return the result.
5. Return -1 if the kth smallest element is not found.

Time Complexity:
The time complexity of the approach is O(n), where n is the number of nodes in the binary search tree. We visit each node once during the in-order traversal.

Space Complexity:
The space complexity is O(h), where h is the height of the binary search tree. This is the space used by the recursive call stack.

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
    int kthSmallest(TreeNode *root, int k) {
        int count = 0;
        return kthSmallestHelper(root, k, count);
    }

  private:
    int kthSmallestHelper(TreeNode *node, int k, int &count) {
        if (node == nullptr) {
            return -1;
        }

        int result = kthSmallestHelper(node->left, k, count);

        if (result != -1) {
            return result;
        }

        count++;

        if (count == k) {
            return node->val;
        }

        return kthSmallestHelper(node->right, k, count);
    }
};