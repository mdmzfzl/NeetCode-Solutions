/*
Problem: LeetCode 102 - Binary Tree Level Order Traversal

Key Idea:
The key idea is to use a breadth-first traversal (commonly implemented using a queue). Start with the root node, enqueue it, and process nodes level by level. For each level, enqueue the children of the nodes at the current level. Keep doing this until the queue is empty, forming a list of lists representing each level's nodes as you go.

Approach:
1. Start with an empty result vector to store the level order traversal.
2. Initialize a queue for a breadth-first search (BFS).
3. Push the root node into the queue.
4. While the queue is not empty:
   - Initialize a temporary vector to store values at the current level.
   - Calculate the number of nodes at the current level by taking the length of the queue.
   - Iterate for each node in the current level (based on the count):
     - Pop a node from the queue.
     - Push its value into the temporary vector.
     - Push its left and right children into the queue if they exist.
   - Push the temporary vector into the result vector.
5. Return the result vector.

Time Complexity:
The time complexity is O(n), where 'n' is the number of nodes in the binary tree. We visit each node once during the BFS traversal.

Space Complexity:
The space complexity is O(m), where 'm' is the maximum number of nodes at any level. In the worst case, 'm' can be the number of leaf nodes, which is O(n/2) in a balanced tree, making the space complexity O(n).
*/

use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;

impl Solution {
    pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = Vec::new();

        if let Some(node) = root {
            let mut queue = VecDeque::new();
            queue.push_back(node);

            while !queue.is_empty() {
                let mut current_level: Vec<i32> = Vec::new();
                let level_size = queue.len();

                for _ in 0..level_size {
                    if let Some(node) = queue.pop_front() {
                        let node_ref = node.borrow();
                        current_level.push(node_ref.val);

                        if let Some(left) = &node_ref.left {
                            queue.push_back(left.clone());
                        }

                        if let Some(right) = &node_ref.right {
                            queue.push_back(right.clone());
                        }
                    }
                }

                result.push(current_level);
            }
        }

        result
    }
}
