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
 Approach - So although the longest path doesn't have to go through the root node, it has to pass the root node of some subtree of the tree (because it has to be from one leaf node to another leaf node, otherwise we can extend it for free). The longest path that passes a given node as the ROOT node is LP = left_height+right_height. So you just calculate LP for all nodes and output the max LP.
 */
 
class Solution {
private:
    int Diameter = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter(root);
        return Diameter;
    }

    // Takes a TreeNode as input and returns the longest path from it to a leaf node
    // Return of this function has nothing to do with diameter
    int maxDiameter(TreeNode* node) {
        if(!node)
            return 0;
        
        // FInding the longest paths in left and right subtree
        int leftSubtree = maxDiameter(node->left);
        int rightSubtree = maxDiameter(node->right);

        // Updating diameter
        Diameter = max(Diameter, leftSubtree + rightSubtree);

        // Whichever subtree is longer, we return that + 1 
        return max(leftSubtree, rightSubtree) + 1;
    }
};