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
    int goodNodes(TreeNode* root) {
        int result = 0;
        DFS(root, root->val, result);
        return result;
    }
private:
    // as we go down the tree the nodes need to be atleast equal or higher 
    // hence the need for maxSoFar
    void DFS(TreeNode* node, int maxSoFar, int &result) {
        if(!node)
            return;
        
        // if the next value in tree is equal or greater than previous value
        // then its a good node
        if(node->val >= maxSoFar)
            result++;
        
        maxSoFar = max(maxSoFar, node->val);
        
        DFS(node->left, maxSoFar, result);
        DFS(node->right, maxSoFar, result);
    }
};

/*
const static auto fast = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}(); 

class Solution {
    int count = 0;
public:
    void countGoodNodes(TreeNode* node, int maxVal) {
        if (node == NULL) return;
        maxVal = max(maxVal, node->val);
        if (maxVal == node->val) count++;
        countGoodNodes(node->left, maxVal);
        countGoodNodes(node->right, maxVal);
    } 
    int goodNodes(TreeNode* root) {
        countGoodNodes(root, INT_MIN);
        root->left = nullptr;
        root->right = nullptr;
        return count;
    }
};
*/