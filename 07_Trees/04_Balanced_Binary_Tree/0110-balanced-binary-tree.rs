/*
Problem: LeetCode 110 - Balanced Binary Tree

Key Idea:
The key idea is to use recursive depth-first traversal. For each node, calculate the heights of its left and right subtrees recursively. If both subtrees are balanced and the height difference is at most one, the tree is balanced.

Approach:
1. Create a recursive function 'is_balanced' that takes a reference to the root of the binary tree and returns a tuple (is_balanced, depth).
2. If the root is None, return (true, 0) (base case).
3. Recursively check if the left subtree is balanced and get its depth.
4. Recursively check if the right subtree is balanced and get its depth.
5. Calculate the depth of the current node as the maximum of the depths of the left and right subtrees plus 1.
6. Check if the left subtree is balanced, the right subtree is balanced, and the absolute difference of their depths is at most 1.
7. Return whether the tree rooted at the current node is balanced and its depth as a tuple.
8. In the main function, return the 'is_balanced' component of the result of 'is_balanced' on the input root.

Time Complexity:
O(n), where 'n' is the number of nodes in the binary tree. We visit each node once.

Space Complexity:
O(h), where 'h' is the height of the binary tree. This space is used for the recursive call stack.
*/

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        fn is_balanced(root: &Option<Rc<RefCell<TreeNode>>>) -> (bool, i32) {
            match root {
                None => (true, 0),
                Some(node) => {
                    let node = node.borrow();
                    let (left_balanced, left_depth) = is_balanced(&node.left);
                    let (right_balanced, right_depth) = is_balanced(&node.right);

                    let depth = left_depth.max(right_depth) + 1;
                    let is_current_balanced =
                        left_balanced && right_balanced && (left_depth - right_depth).abs() <= 1;

                    (is_current_balanced, depth)
                }
            }
        }

        let (is_balanced, _) = is_balanced(&root);
        is_balanced
    }
}
