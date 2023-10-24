/*
Problem: LeetCode 105 - Construct Binary Tree from Preorder and Inorder Traversal

Description:
Given two integer arrays `preorder` and `inorder` representing the preorder and inorder traversal of a binary tree, construct the binary tree.

Intuition:
In a preorder traversal, the root node is visited first, followed by the left subtree and then the right subtree.
In an inorder traversal, the left subtree is visited first, followed by the root node and then the right subtree.
We can utilize these properties to construct the binary tree.

Approach:
1. Create a helper function, `buildTreeHelper`, to construct the binary tree recursively.
2. In the `buildTreeHelper` function:
   - Check if the preorder array is empty. If so, return `nullptr`.
   - Extract the root value from the preorder array and create a new node.
   - Find the index of the root value in the inorder array.
   - Split the inorder array into left and right subtrees based on the root index.
   - Recursively call the `buildTreeHelper` function for the left subtree using the corresponding sections of the preorder and inorder arrays.
   - Recursively call the `buildTreeHelper` function for the right subtree using the corresponding sections of the preorder and inorder arrays.
   - Assign the left and right subtrees to the root node.
   - Return the root node.
3. Call the `buildTreeHelper` function with the entire preorder and inorder arrays.
4. Return the constructed binary tree.

Time Complexity:
The time complexity of the approach is O(n), where n is the number of nodes in the binary tree. We visit each node once during the construction.

Space Complexity:
The space complexity is O(n), where n is the number of nodes in the binary tree. This is the space used by the recursive call stack.

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTreeHelper(preorder, inorder, 0, 0, inorder.size() - 1);
    }

  private:
    TreeNode *buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int preStart, int inStart, int inEnd) {
        if (preStart >= preorder.size() || inStart > inEnd) {
            return nullptr;
        }

        int rootVal = preorder[preStart];
        TreeNode *root = new TreeNode(rootVal);
        int rootIndex;

        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == rootVal) {
                rootIndex = i;
                break;
            }
        }

        int leftSize = rootIndex - inStart;
        root->left = buildTreeHelper(preorder, inorder, preStart + 1, inStart, rootIndex - 1);
        root->right = buildTreeHelper(preorder, inorder, preStart + leftSize + 1, rootIndex + 1, inEnd);
        return root;
    }
};