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
    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        inorder(root, k, result);
        return result;
    }

private:
    void inorder(TreeNode* root, int& k, int& result) {
        if (!root) 
            return;

        inorder(root->left, k, result);
        k--;

        if (k == 0) {
            result = root->val;
            return;
        }
        inorder(root->right, k, result);
    }
};

/*
class Solution {
public:
    void inorder(TreeNode *root,vector<int>&ds){
        if(root == NULL)
            return;
        inorder(root->left, ds);
        ds.push_back(root->val);
        inorder(root->right, ds);

    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ds;
        inorder(root, ds);
        return ds[k-1];
    }
};
*/