/*
Problem: LeetCode 98 - Validate Binary Search Tree

Key Idea:
The key idea is to perform an in-order traversal of the binary tree while keeping track of the previous node's value. In a valid binary search tree (BST), an in-order traversal should yield values in ascending order. Therefore, we can compare each node's value with the previous node's value to check if the tree is a valid BST.

Approach:
1. Define a recursive function to perform an in-order traversal of the binary tree.
2. In the function:
   - If the current node is None, return true (empty subtree is valid).
   - Recursively call the function for the left child.
   - Check if the current node's value is greater than the previous node's value. If not, return false.
   - Update the previous node's value to the current node's value.
   - Recursively call the function for the right child.
3. Start the traversal from the root node with the previous value initialized to negative infinity.
4. If the traversal completes without any violations, return true (valid BST); otherwise, return false.

Time Complexity:
The time complexity is O(n), where 'n' is the number of nodes in the binary tree. We visit each node once during the in-order traversal.

Space Complexity:
The space complexity is O(h), where 'h' is the height of the binary tree. In the worst case, 'h' can be equal to 'n' in a skewed tree, making the space complexity O(n). In a balanced tree, 'h' is O(log n).
*/

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn is_valid_bst(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        fn is_valid(node: Option<Rc<RefCell<TreeNode>>>, prev: &mut i64) -> bool {
            if let Some(n) = node {
                let node_ref = n.borrow();
                if !is_valid(node_ref.left.clone(), prev) {
                    return false;
                }
                if node_ref.val as i64 <= *prev {
                    return false;
                }
                *prev = node_ref.val as i64;
                is_valid(node_ref.right.clone(), prev)
            } else {
                true
            }
        }

        let mut prev = i64::min_value();
        is_valid(root, &mut prev)
    }
}
