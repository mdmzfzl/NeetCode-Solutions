/*
Problem: LeetCode 297 - Serialize and Deserialize Binary Tree

Description:
Design an algorithm to serialize and deserialize a binary tree. Serialize means to encode a tree structure into a string representation, and deserialize means to decode the string representation back into a binary tree structure. The encoded string should be as compact as possible.

Intuition:
To serialize a binary tree, we can perform a pre-order traversal and encode the tree structure into a string. We use a special character to represent nullptr or empty nodes. During deserialization, we can use the encoded string to reconstruct the binary tree.

Approach:
1. Serialization:
   - Perform a pre-order traversal of the binary tree.
   - When encountering a non-empty node, append its value to the serialized string, followed by a separator.
   - When encountering a nullptr or empty node, append a special character (e.g., 'N') to represent it.
   - Use a separator character (e.g., ',') to separate the values in the serialized string.

2. Deserialization:
   - Split the serialized string by the separator to obtain an array of values.
   - Create a queue to hold the values from the array.
   - Recursively build the binary tree using a helper function:
     - If the queue is empty or the current value is the special character, return nullptr.
     - Create a new node with the current value.
     - Pop the queue to move to the next value.
     - Set the left child of the current node by recursively calling the helper function.
     - Set the right child of the current node by recursively calling the helper function.
     - Return the current node.
   - Call the helper function with the queue to build the binary tree.
   - Return the root of the binary tree.

Time Complexity:
- Serialization: O(n), where n is the number of nodes in the binary tree. We perform a pre-order traversal to serialize the tree.
- Deserialization: O(n), where n is the number of nodes in the binary tree. We iterate through the serialized string to deserialize and reconstruct the tree.

Space Complexity:
- Serialization: O(n), where n is the number of nodes in the binary tree. The serialized string requires space proportional to the number of nodes.
- Deserialization: O(n), where n is the number of nodes in the binary tree. We use a queue to store the values during deserialization.

*/

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
    string serialize(TreeNode *root) {
        string serialized = "";
        PreOrder(root, serialized);
        return serialized;
    }

    TreeNode *deserialize(string data) {
        queue<string> Q;
        split(data, Q);
        return MakeTree(Q);
    }

  private:
    void PreOrder(TreeNode *root, string &str) {
        if (!root) {
            str.push_back('N');
            str.push_back(',');
            return;
        }

        str += to_string(root->val) + ",";
        PreOrder(root->left, str);
        PreOrder(root->right, str);
    }

    TreeNode *MakeTree(queue<string> &Q) {
        string S = Q.front();
        Q.pop();

        if (S == "N") {
            return nullptr;
        }

        // stoi -> string to integer
        TreeNode *root = new TreeNode(stoi(S));
        root->left = MakeTree(Q);
        root->right = MakeTree(Q);
        return root;
    }

    void split(const string &data, queue<string> &Q) {
        size_t start = 0;
        size_t pos = data.find(",");

        while (pos != string::npos) {
            Q.push(data.substr(start, pos - start));
            start = pos + 1;
            pos = data.find(",", start);
        }
    }
};


// class Codec {
// public:
//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         string serialized = "";
//         PreOrder(root, serialized);
//         return serialized;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         queue<string> Q;
//         string S;
//         for(int i = 0; i < data.size(); i++) {
//             // If it's a comma, push string into queue and reset string
//             if(data[i] == ',') {
//                 Q.push(S);
//                 S = "";
//                 // Continuing so we go to next iteration without pushing comma
//                 continue;
//             }
//             // pushing back char to string if its not a comma
//             S.push_back(data[i]);
//         }
//         // Making tree after decoding
//         return MakeTree(Q);
//     }

// private:
//     // Function to make string using pre-order traversal
//     void PreOrder(TreeNode* root, string &str) {
//         // If root is null then insert N into string
//         if(!root) {
//             str.push_back('N');
//             str.push_back(',');
//             return;
//         }
//         // Converting int to string and appending
//         // Another way of appending
//         str += to_string(root->val) + ",";

//         PreOrder(root->left, str);
//         PreOrder(root->right, str);
//     }

//     TreeNode* MakeTree(queue<string> &Q) {
//         string S = Q.front();
//         Q.pop();

//         if(S == "N")
//             return NULL;

//         // stoi -> string to integer
//         TreeNode* root = new TreeNode(stoi(S));

//         root->left = MakeTree(Q);
//         root->right = MakeTree(Q);
//         return root;
//     }
// };