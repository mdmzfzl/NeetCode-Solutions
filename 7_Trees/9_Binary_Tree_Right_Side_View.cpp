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

 // Using BFS to store all elements of a row into a queue 
 // and just inserting the last element into the result vector
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        
        vector<int> result;
        queue<TreeNode*> Q;
        int length;

        Q.push(root);

        while(!Q.empty()) {
            length = Q.size();
            for(int i = 0; i < length; i++) {
                TreeNode* temp = Q.front();
                Q.pop();

                // Inserting last element of a row into result
                if(length - i == 1)
                    result.push_back(temp->val);    

                if(temp->left)
                    Q.push(temp->left);
                if(temp->right)
                    Q.push(temp->right);
            }
        }
        return result;
    }
};

/*
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }

        solve(root, ans,0);
        return ans;
    }
private:
    void solve(TreeNode* root,vector<int>&ans,int lvl){
        if(root == NULL)
            return ;

        if(lvl == ans.size())
            ans.push_back(root->val);
        
        solve(root->right, ans, lvl+1);
        solve(root->left, ans, lvl+1);
    }
};
*/
