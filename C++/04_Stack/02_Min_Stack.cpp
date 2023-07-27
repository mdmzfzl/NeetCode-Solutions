/*
Problem: LeetCode 155 - Min Stack

Description:
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Intuition:
To efficiently retrieve the minimum element in constant time, we need to keep track of the minimum value at each step. We can achieve this by using an additional stack to store the minimum values.

Approach:
1. Initialize two stacks: a main stack to store the actual values and a minimum stack to store the minimum values.
2. When pushing a value, check if it is smaller than or equal to the top of the minimum stack. If it is, push the value onto both stacks.
   - If it is larger, push the value only onto the main stack.
3. When popping a value, check if the top of the main stack is equal to the top of the minimum stack.
   - If they are equal, pop both values from both stacks.
   - If they are not equal, pop only from the main stack.
4. When retrieving the top element, simply return the top of the main stack.
5. When retrieving the minimum element, simply return the top of the minimum stack.
6. The implementation ensures that the minimum stack always has the minimum value at the top, reflecting the minimum value at each step.

Time Complexity:
All operations - push, pop, top, and getMin - have a time complexity of O(1). They are all performed in constant time.

Space Complexity:
The space complexity is O(n), where n is the number of elements pushed into the stack. The two stacks store the same number of elements as the main stack.
*/

class MinStack {
  private:
    std::stack<int> mainStack;
    std::stack<int> minStack;

  public:
    MinStack() {
    }

    void push(int val) {
        mainStack.push(val);

        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }

        mainStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};