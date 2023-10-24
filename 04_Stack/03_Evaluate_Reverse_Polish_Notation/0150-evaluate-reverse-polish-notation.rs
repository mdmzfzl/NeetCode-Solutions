/*
Problem: LeetCode 150 - Evaluate Reverse Polish Notation

Key Idea:
The key idea is to use a stack to evaluate the given reverse Polish notation expression.

Approach:
1. Initialize an empty stack to store operands.
2. Iterate through each element in the input tokens:
   - If the current element is an operand (a number), push it onto the stack.
   - If the current element is an operator ('+', '-', '*', '/'):
     - Pop the top two elements from the stack as the operands.
     - Perform the operation based on the current operator and push the result back onto the stack.
3. After processing all elements, the result should be the only element left on the stack. Pop and return this result.

Time Complexity:
O(n), where n is the number of elements in the input tokens. We perform a single pass through the tokens.

Space Complexity:
O(n), where n is the number of elements in the input tokens. The stack can have at most n/2 elements in the worst case.
*/

impl Solution {
    pub fn eval_rpn(tokens: Vec<String>) -> i32 {
        let mut stack: Vec<i32> = Vec::new();

        for token in tokens {
            if let Ok(operand) = token.parse::<i32>() {
                stack.push(operand);
            } else {
                let b = stack.pop().unwrap();
                let a = stack.pop().unwrap();
                let result = match token.as_str() {
                    "+" => a + b,
                    "-" => a - b,
                    "*" => a * b,
                    "/" => a / b,
                    _ => 0, // Invalid operator, can be handled differently if needed
                };
                stack.push(result);
            }
        }

        stack.pop().unwrap()
    }
}
