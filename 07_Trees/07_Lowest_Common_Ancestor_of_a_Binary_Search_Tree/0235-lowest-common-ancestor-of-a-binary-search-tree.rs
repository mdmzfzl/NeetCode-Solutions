/*
Problem: LeetCode 235 - Lowest Common Ancestor of a Binary Search Tree

Key Idea:
The key idea is to utilize the property of a Binary Search Tree (BST), where the nodes in the left subtree of a node are smaller than the node, and nodes in the right subtree are larger than the node. This property allows us to efficiently find the lowest common ancestor.

Approach:
1. Start at the root of the BST.
2. Traverse down the tree.
3. If both p and q are smaller than the current node's value, move to the left subtree.
4. If both p and q are larger than the current node's value, move to the right subtree.
5. Otherwise, the current node is the lowest common ancestor.

Time Complexity:
O(log N) on average, where 'N' is the number of nodes in the BST. In the worst case, where the tree is completely unbalanced, it can be O(N).

Space Complexity:
O(1), as we are using a constant amount of space for traversal.
*/

use std::cell::RefCell;
use std::rc::Rc;

type TreeNodeRef = Option<Rc<RefCell<TreeNode>>>;

impl Solution {
    pub fn lowest_common_ancestor(
        root: TreeNodeRef,
        p: TreeNodeRef,
        q: TreeNodeRef,
    ) -> TreeNodeRef {
        let p_value = p.as_ref().unwrap().borrow().val;
        let q_value = q.as_ref().unwrap().borrow().val;
        let mut current_node = root;

        while let Some(node) = current_node {
            let mut node_ref = node.borrow_mut();

            if p_value < node_ref.val && q_value < node_ref.val {
                current_node = node_ref.left.take();
            } else if p_value > node_ref.val && q_value > node_ref.val {
                current_node = node_ref.right.take();
            } else {
                return Some(node.clone());
            }
        }

        None
    }
}
