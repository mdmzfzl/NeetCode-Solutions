/*
Problem: LeetCode 297 - Serialize and Deserialize Binary Tree

Key Idea:
The key idea is to perform a depth-first traversal (preorder) of the binary tree to serialize it into a string representation, and then parse the string to deserialize it back into a binary tree.

Approach:
1. Serialization:
   - Implement a recursive function that serializes the binary tree into a string.
   - In the serialization function:
     - If the current node is None, append "null" to the serialized string.
     - Otherwise, append the node's value to the serialized string and recursively serialize its left and right subtrees.
2. Deserialization:
   - Implement a deserialization function that parses the string to reconstruct the binary tree.
   - In the deserialization function:
     - Split the serialized string into a list of tokens.
     - Initialize an index to keep track of the current token.
     - Recursively deserialize the tree:
       - If the current token is "null", return None.
       - Otherwise, parse the current token as the node's value and create a new TreeNode.
       - Recursively call the deserialization function for the left and right subtrees.
3. Initialize the index to 0 and call the deserialization function to reconstruct the binary tree.
4. The result is the root of the deserialized binary tree.

Time Complexity:
- Serialization: O(n) - We visit each node exactly once during serialization.
- Deserialization: O(n) - We parse each token exactly once during deserialization.

Space Complexity:
- Serialization: O(n) - The serialized string can be of length 'n' in the worst case.
- Deserialization: O(n) - We use the serialized tokens to reconstruct the tree, which can have a length of 'n' in the worst case.
*/

use std::rc::Rc;
use std::cell::RefCell;

struct Codec;

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Codec {
    fn new() -> Self {
        Codec
    }

    fn serialize(&self, root: Option<Rc<RefCell<TreeNode>>>) -> String {
        fn serialize_helper(node: Option<Rc<RefCell<TreeNode>>>, serialized: &mut String) {
            match node {
                None => serialized.push_str("null,"),
                Some(inner) => {
                    let val = inner.borrow().val.to_string();
                    serialized.push_str(&val);
                    serialized.push(',');
                    serialize_helper(inner.borrow().left.clone(), serialized);
                    serialize_helper(inner.borrow().right.clone(), serialized);
                }
            }
        }

        let mut serialized = String::new();
        serialize_helper(root, &mut serialized);
        serialized
    }

    fn deserialize(&self, data: String) -> Option<Rc<RefCell<TreeNode>>> {
        let tokens: Vec<&str> = data.split(',').collect();
        let mut index = 0;

        fn deserialize_helper(tokens: &Vec<&str>, index: &mut usize) -> Option<Rc<RefCell<TreeNode>>> {
            if *index >= tokens.len() {
                return None;
            }

            let val = tokens[*index];
            *index += 1;

            if val == "null" {
                return None;
            }

            let val = val.parse::<i32>().unwrap();
            let node = Rc::new(RefCell::new(TreeNode::new(val)));

            node.borrow_mut().left = deserialize_helper(tokens, index);
            node.borrow_mut().right = deserialize_helper(tokens, index);

            Some(node)
        }

        deserialize_helper(&tokens, &mut index)
    }
}

/**
 * Your Codec object will be instantiated and called as such:
 * let obj = Codec::new();
 * let data: String = obj.serialize(strs);
 * let ans: Option<Rc<RefCell<TreeNode>>> = obj.deserialize(data);
**/
