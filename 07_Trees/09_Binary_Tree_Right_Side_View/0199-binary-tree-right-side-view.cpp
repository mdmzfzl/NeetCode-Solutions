/*
Problem: LeetCode 199 - Binary Tree Right Side View

Description:
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Intuition:
To obtain the right side view of a binary tree, we can perform a level order traversal and keep track of the last node at each level.
Since we traverse the tree level by level, the last node we encounter at each level from left to right will be visible from the right side.

Approach:
1. Create a vector, `result`, to store the right side view of the binary tree.
2. Create an empty queue of `TreeNode*` to perform the level order traversal.
3. Enqueue the root node into the queue.
4. While the queue is not empty:
   - Get the current size of the queue to represent the number of nodes at the current level.
   - Create a variable, `lastValue`, to store the value of the last node at the current level.
   - Iterate through the nodes at the current level:
     - Dequeue a node from the queue.
     - Update `lastValue` with the value of the dequeued node.
     - Enqueue the left and right children of the dequeued node, if they exist.
   - Add `lastValue` to the `result` vector.
5. Return the `result` vector containing the right side view.

Time Complexity:
The time complexity of the approach is O(n), where n is the number of nodes in the binary tree. We visit each node once during the level order traversal.

Space Complexity:
The space complexity is O(m), where m is the maximum number of nodes at any level in the binary tree. This is the space used by the queue and the `result` vector.

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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;

        if (root == nullptr) {
            return result;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            int lastValue;

            for (int i = 0; i < levelSize; i++) {
                TreeNode *node = q.front();
                q.pop();
                lastValue = node->val;

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            result.push_back(lastValue);
        }

        return result;
    }
};