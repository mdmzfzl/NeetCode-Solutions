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
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        
        bool Left = isBalanced(root->left);
        bool Right = isBalanced(root->right);

        // If the difference between Left and Right tree height is lesser than 1, return true
        // else false
        // Left && right is here to make sure both are balnced
        // If they are not, their values will be -1 and (&&) case will return false
        return Left && Right && abs(height(root->left) - height(root->right)) <= 1;
    }

    int height(TreeNode* root) {
        if(!root) 
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
};