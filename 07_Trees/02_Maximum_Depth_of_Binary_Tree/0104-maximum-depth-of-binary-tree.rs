/*
Problem: LeetCode 104 - Maximum Depth of Binary Tree

Key Idea:
The key idea is to use recursive depth-first traversal. For each node, calculate the depth of its left and right subtrees recursively, and return the maximum of these depths plus one as the depth of the current node.

Approach:
1. Create a recursive function 'max_depth' that takes a reference to the root of the binary tree.
2. If the root is None, return 0 (base case).
3. Recursively calculate the maximum depth of the left subtree by calling 'max_depth' on the left child.
4. Recursively calculate the maximum depth of the right subtree by calling 'max_depth' on the right child.
5. Return the maximum depth among the left and right subtrees, incremented by 1 to account for the current level.
6. In the main function, return the result of 'max_depth' on the input root.

Time Complexity:
O(n), where 'n' is the number of nodes in the binary tree. We visit each node once.

Space Complexity:
O(h), where 'h' is the height of the binary tree. This space is used for the recursive call stack.
*/

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn max_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        match root {
            None => 0,
            Some(node) => {
                let node = node.borrow();
                let left_depth = Solution::max_depth(node.left.clone());
                let right_depth = Solution::max_depth(node.right.clone());
                1 + left_depth.max(right_depth)
            }
        }
    }
}
