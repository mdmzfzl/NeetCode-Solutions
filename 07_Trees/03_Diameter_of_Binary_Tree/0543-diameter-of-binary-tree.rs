/*
Problem: LeetCode 543 - Diameter of Binary Tree

Key Idea:
The key idea is to use depth-first traversal. For each node, calculate the sum of the depths of its left and right subtrees. The diameter will be the maximum of these sums or the maximum diameter found in any subtree.

Approach:
1. Create a recursive function 'diameter_of_binary_tree' that takes a reference to the root of the binary tree and returns a tuple (depth, diameter).
2. If the root is None, return (0, 0) (base case).
3. Recursively calculate the depth and diameter of the left subtree by calling 'diameter_of_binary_tree' on the left child.
4. Recursively calculate the depth and diameter of the right subtree by calling 'diameter_of_binary_tree' on the right child.
5. Calculate the diameter as the maximum of three values:
   - The diameter of the left subtree.
   - The diameter of the right subtree.
   - The sum of the depths of the left and right subtrees plus 1 (to account for the current node).
6. Calculate the depth as the maximum of the depths of the left and right subtrees plus 1 (to account for the current node).
7. Return the calculated depth and diameter as a tuple.
8. In the main function, return the diameter component of the result of 'diameter_of_binary_tree' on the input root.

Time Complexity:
O(n), where 'n' is the number of nodes in the binary tree. We visit each node once.

Space Complexity:
O(h), where 'h' is the height of the binary tree. This space is used for the recursive call stack.
*/

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn diameter_of_binary_tree(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn diameter_of_binary_tree(
            root: &Option<Rc<RefCell<TreeNode>>>,
            max_diameter: &mut i32,
        ) -> (i32, i32) {
            match root {
                None => (0, 0),
                Some(node) => {
                    let node = node.borrow();
                    let (left_depth, left_diameter) =
                        diameter_of_binary_tree(&node.left, max_diameter);
                    let (right_depth, right_diameter) =
                        diameter_of_binary_tree(&node.right, max_diameter);

                    let depth = left_depth.max(right_depth) + 1;
                    let diameter = left_diameter
                        .max(right_diameter)
                        .max(left_depth + right_depth);

                    *max_diameter = (*max_diameter).max(diameter);

                    (depth, diameter)
                }
            }
        }

        let mut max_diameter = 0;
        let (_, diameter) = diameter_of_binary_tree(&root, &mut max_diameter);
        diameter
    }
}
