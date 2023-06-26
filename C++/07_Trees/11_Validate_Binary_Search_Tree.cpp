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

/*
The idea is to write a utility helper function that traverses down the tree keeping track of the narrowing min and max allowed values as it goes, looking at each node only once. The initial values for min and max should be LONG_MIN and LONG_MAX — they narrow from there.
*/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
private:
    bool helper(TreeNode* root, long left, long right){
        if (!root)
            return true;

        if (root->val < right && root->val > left)
           return helper(root->left, left, root->val) && helper(root->right, root->val, right);
        
        return false;
    }
};

/*
class Solution {
public:
    bool check(TreeNode* root, long long l, long long r){
        if (root==NULL) 
            return true;
        if (!(root->val >= l && root->val <= r)) 
            return false;
        if (check(root->left, l, (long long)(root->val) - 1) && check(root->right, (long long)(root->val) + 1, r)) 
            return true;
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return check(root, INT_MIN, INT_MAX);
    }
};
*/