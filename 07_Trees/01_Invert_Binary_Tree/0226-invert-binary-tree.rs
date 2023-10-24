/*
Problem: LeetCode 226 - Invert Binary Tree

Key Idea:
The key idea is to swap the left and right subtrees of each node.

Approach:
1. Create a recursive function 'invert_tree' that takes a reference to the root of the binary tree.
2. If the root is None, return None (base case).
3. Swap the left and right subtrees of the root node by recursively calling 'invert_tree' on both the left and right subtrees.
4. Update the root node's left child with the result of inverting the right subtree and the right child with the result of inverting the left subtree.
5. Return the root node after the inversion.
6. In the main function, return the result of 'invert_tree' on the input root.

Time Complexity:
O(n), where 'n' is the number of nodes in the binary tree. We visit each node once.

Space Complexity:
O(h), where 'h' is the height of the binary tree. This space is used for the recursive call stack.
*/

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn invert_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        match root {
            None => None,
            Some(node) => {
                let mut node = node.borrow_mut();
                let left = node.left.take();
                let right = node.right.take();
                node.left = Solution::invert_tree(right);
                node.right = Solution::invert_tree(left);
                Some(Rc::new(RefCell::new(TreeNode {
                    val: node.val,
                    left: node.left.clone(),
                    right: node.right.clone(),
                })))
            }
        }
    }
}
