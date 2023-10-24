/*
Problem: LeetCode 102 - Binary Tree Level Order Traversal

Description:
Given the root of a binary tree, return the level order traversal of its nodes' values.
(i.e., from left to right, level by level).

Intuition:
To perform a level order traversal of a binary tree, we can utilize a breadth-first search (BFS) algorithm.
By visiting the nodes in a breadth-first manner, we can easily track the nodes at each level and store their values.

Approach:
1. Create a result vector to store the level order traversal.
2. Create a queue to perform the BFS.
3. Enqueue the root node into the queue.
4. While the queue is not empty:
     - Get the current size of the queue to represent the number of nodes at the current level.
     - Create a level vector to store the values of the nodes at the current level.
     - Iterate through the nodes at the current level:
         - Dequeue a node from the queue.
         - Add the value of the dequeued node to the level vector.
         - Enqueue the left and right children of the dequeued node, if they exist.
     - Add the level vector to the result vector.
5. Return the result vector.

Time Complexity:
The time complexity of the approach is O(n), where n is the number of nodes in the binary tree. We visit each node once during the BFS.

Space Complexity:
The space complexity is O(m), where m is the maximum number of nodes at any level in the binary tree. This is the space used by the queue and the result vector.

*/

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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;

        if (root == nullptr) {
            return result;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level;

            for (int i = 0; i < levelSize; i++) {
                // Dequeue a node from the queue
                TreeNode *node = q.front();
                q.pop();
                // Add the value of the dequeued node to the level vector
                level.push_back(node->val);

                // Enqueue the left and right children of the dequeued node, if they exist
                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            // Add the level vector to the result vector
            result.push_back(level);
        }

        return result;
    }
};