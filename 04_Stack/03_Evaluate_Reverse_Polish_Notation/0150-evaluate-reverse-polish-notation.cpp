/*
Problem: LeetCode 150 - Evaluate Reverse Polish Notation

Description:
Evaluate the value of an arithmetic expression in Reverse Polish Notation (RPN).
Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Intuition:
Reverse Polish Notation (RPN) eliminates the need for parentheses in arithmetic expressions by using a postfix notation. To evaluate an RPN expression, we can utilize a stack to perform the necessary operations.

Approach:
1. Initialize an empty stack.
2. Iterate through each token in the given list:
   - If the token is an operator ('+', '-', '*', '/'), pop the top two values from the stack, perform the corresponding operation, and push the result back to the stack.
   - If the token is an operand (integer), convert it to an integer and push it onto the stack.
3. After iterating through all tokens, the stack will contain the final result.
4. Pop the result from the stack and return it.

Time Complexity:
The time complexity is O(n), where n is the number of tokens in the input list. We iterate through each token once.

Space Complexity:
The space complexity is O(n), where n is the number of tokens in the input list. In the worst case, the stack may store all the operands.
*/

class Solution {
  public:
    int evalRPN(std::vector<std::string> &tokens) {
        std::stack<int> stack;

        for (const auto &token : tokens) {
            if (isOperator(token)) {
                int operand2 = stack.top();
                stack.pop();
                int operand1 = stack.top();
                stack.pop();
                int result = performOperation(operand1, operand2, token);
                stack.push(result);
            } else {
                stack.push(std::stoi(token));
            }
        }

        return stack.top();
    }

  private:
    bool isOperator(const std::string &token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int performOperation(int operand1, int operand2, const std::string &operatorStr) {
        if (operatorStr == "+") {
            return operand1 + operand2;
        } else if (operatorStr == "-") {
            return operand1 - operand2;
        } else if (operatorStr == "*") {
            return operand1 * operand2;
        } else if (operatorStr == "/") {
            return operand1 / operand2;
        }

        return 0; // Invalid operator
    }
};