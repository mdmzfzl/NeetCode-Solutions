/*
Problem: LeetCode 230 - Kth Smallest Element in a BST

Key Idea:
The key idea is to perform an in-order traversal of the binary search tree (BST) while maintaining a count of visited nodes. When the count reaches 'k', we have found the kth smallest element in the BST.

Approach:
1. Define a recursive function to perform an in-order traversal of the BST.
2. In the function:
   - If the current node is None, return None.
   - Recursively call the function for the left child.
   - Increment the count of visited nodes.
   - If the count equals 'k', return the value of the current node.
   - Recursively call the function for the right child.
3. Start the traversal from the root node with the count initialized to 0.
4. If the traversal completes, return None (k is out of bounds).

Time Complexity:
The time complexity is O(h + k), where 'h' is the height of the BST. In the worst case, the traversal goes down to the leftmost leaf node (height 'h') and then back up to find the kth smallest element.

Space Complexity:
The space complexity is O(h) due to the recursion stack. In the worst case, 'h' can be equal to 'n' in a skewed tree, making the space complexity O(n). In a balanced tree, 'h' is O(log n).
*/

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn kth_smallest(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> i32 {
        fn in_order_traversal(
            node: Option<Rc<RefCell<TreeNode>>>,
            k: i32,
            count: &mut i32,
        ) -> Option<i32> {
            if let Some(n) = node {
                let node_ref = n.borrow();
                let left_result = in_order_traversal(node_ref.left.clone(), k, count);
                if let Some(val) = left_result {
                    return Some(val);
                }
                *count += 1;
                if *count == k {
                    return Some(node_ref.val);
                }
                in_order_traversal(node_ref.right.clone(), k, count)
            } else {
                None
            }
        }

        let mut count = 0;
        in_order_traversal(root, k, &mut count).unwrap()
    }
}
