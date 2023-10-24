/*
Problem: LeetCode 105 - Construct Binary Tree from Preorder and Inorder Traversal

Key Idea:
The key idea is to use recursion to construct the binary tree. We can determine the root node from the preorder traversal and then find its position in the inorder traversal to divide the inorder traversal into left and right subtrees. We repeat this process for each subtree recursively.

Approach:
1. Create a hashmap that maps values from the inorder traversal to their indices. This will allow us to quickly find the position of the root node in the inorder traversal.
2. Define a recursive function that takes the following parameters:
   - `pre_start` and `pre_end`: The start and end indices in the preorder traversal.
   - `in_start` and `in_end`: The start and end indices in the inorder traversal.
3. In the function:
   - If `pre_start > pre_end`, return None (no more nodes to construct).
   - Get the value of the root node from the current `pre_start` index.
   - Find the position of the root value in the inorder traversal using the hashmap.
   - Calculate the number of nodes in the left subtree (the difference between the root's position and `in_start`).
   - Create the root node.
   - Recursively call the function for the left subtree and right subtree, adjusting the indices accordingly.
   - Return the root node.
4. Start the recursion with `pre_start = 0`, `pre_end = n - 1`, `in_start = 0`, and `in_end = n - 1`, where `n` is the number of nodes.
5. The result is the root node of the constructed binary tree.

Time Complexity:
The time complexity is O(n), where 'n' is the number of nodes, as we visit each node once during the construction.

Space Complexity:
The space complexity is O(n) due to the recursion stack.
*/

use std::cell::RefCell;
use std::collections::HashMap;
use std::rc::Rc;

impl Solution {
    pub fn build_tree(preorder: Vec<i32>, inorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        fn build(
            preorder: &[i32],
            inorder: &[i32],
            pre_start: usize,
            pre_end: usize,
            in_start: usize,
            in_end: usize,
            inorder_map: &HashMap<i32, usize>,
        ) -> Option<Rc<RefCell<TreeNode>>> {
            if pre_start > pre_end {
                return None;
            }

            let root_val = preorder[pre_start];
            let root_inorder_index = *inorder_map.get(&root_val).unwrap();
            let left_size = root_inorder_index - in_start;

            let mut root = TreeNode::new(root_val);
            root.left = build(
                preorder,
                inorder,
                pre_start + 1,
                pre_start + left_size,
                in_start,
                root_inorder_index - 1,
                inorder_map,
            );
            root.right = build(
                preorder,
                inorder,
                pre_start + left_size + 1,
                pre_end,
                root_inorder_index + 1,
                in_end,
                inorder_map,
            );

            Some(Rc::new(RefCell::new(root)))
        }

        let mut inorder_map = HashMap::new();
        for (i, &val) in inorder.iter().enumerate() {
            inorder_map.insert(val, i);
        }

        build(
            &preorder,
            &inorder,
            0,
            preorder.len() - 1,
            0,
            inorder.len() - 1,
            &inorder_map,
        )
    }
}
