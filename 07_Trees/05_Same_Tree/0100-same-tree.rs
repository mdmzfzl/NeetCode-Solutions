/*
Problem: LeetCode 100 - Same Tree

Key Idea:
The key idea is to use recursive depth-first traversal. For each pair of corresponding nodes in the trees, check if their values are equal and recursively check the left and right subtrees. If all corresponding nodes are equal, the trees are identical.

Approach:
1. Create a recursive function 'is_same_tree' that takes references to the roots of two binary trees as input and returns a boolean.
2. If both roots are None, return true (base case).
3. If one of the roots is None while the other is not, return false (as they cannot be identical).
4. Check if the values of the current nodes are equal.
5. Recursively call 'is_same_tree' for the left subtrees and right subtrees.
6. Return the logical AND of the results from steps 4 and 5.
7. In the main function, return the result of 'is_same_tree' on the input roots.

Time Complexity:
O(n), where 'n' is the number of nodes in the binary trees. We visit each node once.

Space Complexity:
O(h), where 'h' is the height of the binary trees. This space is used for the recursive call stack.
*/

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn is_same_tree(
        p: Option<Rc<RefCell<TreeNode>>>,
        q: Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        fn is_same_tree(
            p: &Option<Rc<RefCell<TreeNode>>>,
            q: &Option<Rc<RefCell<TreeNode>>>,
        ) -> bool {
            match (p, q) {
                (None, None) => true,
                (Some(p_node), Some(q_node)) => {
                    let p_node = p_node.borrow();
                    let q_node = q_node.borrow();
                    p_node.val == q_node.val
                        && is_same_tree(&p_node.left, &q_node.left)
                        && is_same_tree(&p_node.right, &q_node.right)
                }
                _ => false,
            }
        }

        is_same_tree(&p, &q)
    }
}
