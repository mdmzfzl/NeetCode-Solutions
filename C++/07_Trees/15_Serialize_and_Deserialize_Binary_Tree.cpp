/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialized = "";
        PreOrder(root, serialized);
        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> Q;
        string S;
        for(int i = 0; i < data.size(); i++) {
            // If it's a comma, push string into queue and reset string
            if(data[i] == ',') {
                Q.push(S);
                S = "";
                // Continuing so we go to next iteration without pushing comma
                continue;
            }
            // pushing back char to string if its not a comma
            S.push_back(data[i]);
        }
        // Making tree after decoding
        return MakeTree(Q);
    }

private: 
    // Function to make string using pre-order traversal
    void PreOrder(TreeNode* root, string &str) {
        // If root is null then insert N into string
        if(!root) {
            str.push_back('N');
            str.push_back(',');
            return;
        }
        // Converting int to string and appending
        // Another way of appending
        str += to_string(root->val) + ",";

        PreOrder(root->left, str);
        PreOrder(root->right, str);
    }

    TreeNode* MakeTree(queue<string> &Q) {
        string S = Q.front(); 
        Q.pop();

        if(S == "N")
            return NULL;
        
        // stoi -> string to integer
        TreeNode* root = new TreeNode(stoi(S));

        root->left = MakeTree(Q);
        root->right = MakeTree(Q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));