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

// All values in the tree are unique
// 1) First value in preorder will always be root
// 2) All values before root in in-order traversal will go in left subtree
//    and all value to right will go in right subtree
// so we can partition the preorder array by knowing the size of L and R subtree 

/*
The algorithm works as follows:

1. If the inorder array is empty, return null.
2. Take the first element from the preorder array and create a new node with it as the root.
3.Find the index of the root element in the inorder array.
4. Recursively construct the left subtree using the elements in the left side of the inorder array (excluding the root element), and the left portion of the preorder array.
5. Recursively construct the right subtree using the elements in the right side of the inorder array (excluding the root element), and the right portion of the preorder array.
6. Return the root of the current subtree.
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        TreeNode* root = Build(preorder, inorder, index, 0, inorder.size() - 1);
        return root;
    }
private:
    TreeNode* Build(vector<int>& preOrder, vector<int>& inOrder, int& index, int i, int j) {
        if (i > j)
            return NULL;
        
        // Making the tree
        TreeNode* root = new TreeNode(preOrder[index]);

        int split = 0;
        // finding where the split occurs
        for(int k = 0; k < inOrder.size(); k++) {
            // finding the root element in "inorder" array
            // that will be our split
            if(preOrder[index] == inOrder[k]) {
                split = k;
                break;
            }
        }
        index++;

        root->left = Build(preOrder, inOrder, index, i, split - 1);
        root->right = Build(preOrder, inOrder, index, split + 1, j);

        return root;
    }
};


/*
class Solution {
public:
    TreeNode* solve(int &rootIdx, vector<int> &pre, vector<int> &in, int l, int r, map<int, int> &mp){
        if(l > r)
            return NULL;
        
        int ele = pre[rootIdx++];
        TreeNode* ans = new TreeNode(ele);
        int pos = mp[ele];
        
        ans->left = solve(rootIdx, pre, in, l, pos-1, mp);
        ans->right = solve(rootIdx, pre, in, pos+1, r, mp);
        
        return ans;
    }
    
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        // --- mapping of inorder to find in O(1)
        map<int, int> mp ;
        for(int i =0; i < in.size(); i++)
            mp[in[i]] = i;
        
        int rootIdx = 0;
        return solve(rootIdx, pre, in, 0, in.size()-1, mp);
    }
};
*/
