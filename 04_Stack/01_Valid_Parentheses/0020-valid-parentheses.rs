/*
Problem: LeetCode 20 - Valid Parentheses

Key Idea:
The key idea is to use a stack to keep track of open parentheses and ensure that they are closed in the correct order.

Approach:
1. Initialize an empty stack to store open parentheses.
2. Iterate through each character in the input string:
   - If the character is an open parenthesis ('(', '{', or '['), push it onto the stack.
   - If the character is a closing parenthesis (')', '}', or ']'):
     - Check if the stack is empty. If it is, return false as there is no corresponding open parenthesis.
     - Pop the top element from the stack.
     - Check if the popped element matches the current closing parenthesis. If they don't match, return false.
3. After iterating through the entire string, check if the stack is empty. If it is, return true; otherwise, return false.

Time Complexity:
O(n), where n is the length of the input string. We perform a single pass through the string.

Space Complexity:
O(n), where n is the length of the input string in the worst case. This is the space required to store the stack.
*/

impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack: Vec<char> = Vec::new();

        for c in s.chars() {
            match c {
                '(' | '{' | '[' => stack.push(c),
                ')' => {
                    if stack.pop() != Some('(') {
                        return false;
                    }
                }
                '}' => {
                    if stack.pop() != Some('{') {
                        return false;
                    }
                }
                ']' => {
                    if stack.pop() != Some('[') {
                        return false;
                    }
                }
                _ => return false, // Invalid character
            }
        }

        stack.is_empty()
    }
}
