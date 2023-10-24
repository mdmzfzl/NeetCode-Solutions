/*
Problem: LeetCode 572 - Subtree of Another Tree

Key Idea:
The key idea is to use a recursive approach. Start by checking if the current nodes in both trees are equal. If they are, recursively check if the left and right subtrees are also identical. Repeat this process until you find a matching subtree or exhaust all possibilities in the main tree.

Approach:
1. Create a recursive function 'is_subtree' that takes references to the roots of two binary trees as input and returns a boolean.
2. If the first tree's root is None, return false (base case).
3. Check if the current nodes of both trees are equal.
4. If the nodes are equal, recursively check if the left and right subtrees of both trees are also subtrees.
5. If any of the conditions in step 3 or 4 is true, return true.
6. In the main function, return the result of 'is_subtree' on the input trees.

Time Complexity:
O(m * n), where 'm' is the number of nodes in the first tree, and 'n' is the number of nodes in the second tree. In the worst case, we may have to check all nodes in the first tree against the second tree.

Space Complexity:
O(h), where 'h' is the height of the first tree. This space is used for the recursive call stack.
*/

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn is_subtree(s: Option<Rc<RefCell<TreeNode>>>, t: Option<Rc<RefCell<TreeNode>>>) -> bool {
        fn is_subtree(
            s: &Option<Rc<RefCell<TreeNode>>>,
            t: &Option<Rc<RefCell<TreeNode>>>,
        ) -> bool {
            match (s, t) {
                (None, None) => true,
                (Some(s_node), Some(t_node)) => {
                    let s_node = s_node.borrow();
                    let t_node = t_node.borrow();
                    s_node.val == t_node.val
                        && is_subtree(&s_node.left, &t_node.left)
                        && is_subtree(&s_node.right, &t_node.right)
                }
                _ => false,
            }
        }

        fn is_subtree_helper(
            s: &Option<Rc<RefCell<TreeNode>>>,
            t: &Option<Rc<RefCell<TreeNode>>>,
        ) -> bool {
            match s {
                Some(s_node) => {
                    let s_node = s_node.borrow();
                    is_subtree(s, t)
                        || is_subtree_helper(&s_node.left, t)
                        || is_subtree_helper(&s_node.right, t)
                }
                None => false,
            }
        }

        is_subtree_helper(&s, &t)
    }
}
