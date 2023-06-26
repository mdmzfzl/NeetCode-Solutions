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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        
        vector<vector<int>> result;
        queue<TreeNode*> Q;

        // Pushing back root in the initial Queue
        Q.push(root);
        while(!Q.empty()) {
            int length = Q.size();
            vector<int> v;
            for(int i = 0; i < length; i++) {
                TreeNode* T = Q.front();
                Q.pop();
                v.push_back(T->val);

                if(T->left)
                    Q.push(T->left);
                if(T->right)
                    Q.push(T->right);
            }
            result.push_back(v);
        }
        return result;
    }
};