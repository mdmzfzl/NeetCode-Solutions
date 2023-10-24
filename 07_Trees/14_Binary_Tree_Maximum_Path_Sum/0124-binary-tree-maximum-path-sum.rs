/*
Problem: LeetCode 124 - Binary Tree Maximum Path Sum

Key Idea:
The key idea is to use a recursive approach to calculate the maximum path sum for each subtree while keeping track of the maximum path sum across all subtrees. At each node, we have three choices:
1. Include only the current node.
2. Include the current node and the maximum path sum from the left subtree.
3. Include the current node and the maximum path sum from the right subtree.

Approach:
1. Define a recursive function that takes a reference to the current node and returns the maximum path sum that starts from this node and goes downwards (either left or right).
2. In the function:
   - If the current node is None, return 0.
   - Recursively calculate the maximum path sum for the left subtree and the right subtree using the same function.
   - Calculate the maximum path sum that includes the current node and goes either left or right, or just the current node itself.
   - Update the global maximum path sum if the new path sum is greater.
   - Return the maximum path sum that starts from the current node and goes either left or right.
3. Initialize a global variable to store the maximum path sum with a value of negative infinity.
4. Start the recursion from the root node.
5. The result is the global maximum path sum.

Time Complexity:
The time complexity is O(n), where 'n' is the number of nodes in the binary tree, as we visit each node once.

Space Complexity:
The space complexity is O(h), where 'h' is the height of the binary tree. In the worst case (unbalanced tree), 'h' can be equal to 'n', but in the average case (balanced tree), 'h' is O(log n).
*/

use std::cell::RefCell;
use std::cmp::max;
use std::rc::Rc;

impl Solution {
    pub fn max_path_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn max_path_sum_helper(node: Option<Rc<RefCell<TreeNode>>>, max_sum: &mut i32) -> i32 {
            if let Some(inner) = node {
                let val = inner.borrow().val;
                let left_sum = max_path_sum_helper(inner.borrow_mut().left.take(), max_sum);
                let right_sum = max_path_sum_helper(inner.borrow_mut().right.take(), max_sum);

                // Calculate the maximum path sum including the current node.
                let node_sum = max(val, max(val + left_sum, val + right_sum));

                // Update the global maximum path sum.
                *max_sum = max(*max_sum, max(node_sum, val + left_sum + right_sum));

                // Return the maximum path sum starting from the current node.
                return node_sum;
            }

            // If the node is None, return 0.
            0
        }

        let mut max_sum = i32::min_value();
        max_path_sum_helper(root, &mut max_sum);
        max_sum
    }
}
