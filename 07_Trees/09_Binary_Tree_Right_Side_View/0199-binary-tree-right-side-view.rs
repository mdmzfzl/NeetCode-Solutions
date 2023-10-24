/*
Problem: LeetCode 199 - Binary Tree Right Side View

Key Idea:
The key idea is to perform a level order traversal of the binary tree and only add the rightmost node at each level to the result.

Approach:
1. Start with an empty result vector to store the right side view of the binary tree.
2. Initialize a queue for a breadth-first search (BFS).
3. Push the root node into the queue.
4. While the queue is not empty:
   - Initialize a variable to store the rightmost node's value at the current level.
   - Calculate the number of nodes at the current level by taking the length of the queue.
   - Iterate for each node in the current level (based on the count):
     - Pop a node from the queue.
     - Update the rightmost value to the current node's value.
     - Push its left and right children into the queue if they exist.
   - Push the rightmost value into the result vector.
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
    pub fn right_side_view(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut result: Vec<i32> = Vec::new();

        if let Some(node) = root {
            let mut queue = VecDeque::new();
            queue.push_back(node);

            while !queue.is_empty() {
                let mut rightmost_val = 0;
                let level_size = queue.len();

                for i in 0..level_size {
                    if let Some(node) = queue.pop_front() {
                        let node_ref = node.borrow();

                        if i == level_size - 1 {
                            // Rightmost node at the current level
                            rightmost_val = node_ref.val;
                        }

                        if let Some(left) = &node_ref.left {
                            queue.push_back(left.clone());
                        }

                        if let Some(right) = &node_ref.right {
                            queue.push_back(right.clone());
                        }
                    }
                }

                result.push(rightmost_val);
            }
        }

        result
    }
}
