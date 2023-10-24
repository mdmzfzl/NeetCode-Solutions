/*
Problem: LeetCode 1448 - Count Good Nodes in Binary Tree

Key Idea:
The key idea is to perform a depth-first search (DFS) traversal of the binary tree while keeping track of the maximum value encountered in the path from the root to the current node. If the current node's value is greater than or equal to the maximum value encountered so far, it is considered a "good" node, and we increment the count.

Approach:
1. Start with a count variable initialized to 0 to keep track of good nodes.
2. Define a recursive DFS function that takes the current node, the maximum value encountered so far, and updates the count.
3. In the DFS function:
   - If the current node is None, return.
   - Calculate the new maximum value as the maximum of the current node's value and the maximum value encountered so far.
   - If the current node's value is greater than or equal to the new maximum value, increment the count.
   - Recursively call the DFS function for the left and right children, passing the new maximum value.
4. Call the DFS function starting from the root node with an initial maximum value of negative infinity.
5. Return the count, which represents the number of good nodes.

Time Complexity:
The time complexity is O(n), where 'n' is the number of nodes in the binary tree. We visit each node once during the DFS traversal.

Space Complexity:
The space complexity is O(h), where 'h' is the height of the binary tree. In the worst case, 'h' can be equal to 'n' in a skewed tree, making the space complexity O(n). In a balanced tree, 'h' is O(log n).
*/

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn good_nodes(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn dfs(node: Option<Rc<RefCell<TreeNode>>>, max_val: i32, count: &mut i32) {
            if let Some(n) = node {
                let node_ref = n.borrow();
                let new_max = i32::max(max_val, node_ref.val);

                if node_ref.val >= max_val {
                    *count += 1;
                }

                dfs(node_ref.left.clone(), new_max, count);
                dfs(node_ref.right.clone(), new_max, count);
            }
        }

        let mut count = 0;
        dfs(root, i32::min_value(), &mut count);
        count
    }
}
