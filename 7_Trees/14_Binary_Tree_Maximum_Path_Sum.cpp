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
For each node there can be three ways that the max path goes through the node: 
 
Case #1: Max path through Left Child + Node 
Case #2: Max path through Right Child + Node 
Case #3: Max path through Left Child + Max path through Right Child + Node 
 */

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        answer = INT_MIN;
        DFS(root);
        return answer;
    }
private:
    int answer;
    int DFS(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int left = DFS(root->left);
        int right = DFS(root->right);

        // Case #3
        answer = max(answer, left + right + root->val);

        // Case #1 and #2
        // We take 0 in case the sum is negative
        // Takes case of case when theres a single element too
        return max(0, root->val + max(left, right));
    }
};

/*
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxsum(root, maxi);
        return maxi;
    }
    private:
       int maxsum(TreeNode* root, int &maxi){
           if(root == NULL){
               return 0;
           }
           int left = max(0, maxsum(root->left, maxi));
           int right = max(0, maxsum(root->right, maxi));

           maxi = max(maxi, left + right + root->val);
           return root->val + max(left, right);
       }
};
*/