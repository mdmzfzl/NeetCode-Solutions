/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Utilising the concept that left element of node will be lower than curr node and right will be greater.

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // case 1: Both elements lie in left subtree
        if (p->val < root->val && q->val < root->val) 
            return lowestCommonAncestor(root->left, p, q);

        // case 2: Both elements lie in right subtree
        else if (p->val > root->val && q->val > root->val) 
            return lowestCommonAncestor(root->right, p, q);

        // case 3: if one element is on the left side and one element is on the right side
        // basically where the split occurs, if it reached here then its the LCA
        else 
            return root;
    }
};