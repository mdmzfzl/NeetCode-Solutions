"""
Problem: LeetCode 155 - Min Stack

Key Idea:
To implement a stack that supports finding the minimum element in constant time, we can use two stacks: one for storing the actual elements (stack) and another for keeping track of the minimum elements (min_stack). The min_stack will always have the current minimum element at the top. When pushing an element onto the stack, we compare it with the top element of the min_stack and push the smaller element onto the min_stack. When popping an element from the stack, we check if the element being popped is the same as the top element of the min_stack. If it is, we also pop the element from the min_stack. This way, the top element of the min_stack will always be the minimum element in the stack.

Time Complexity:
The time complexity of push, pop, top, and getMin operations is O(1). All these operations involve constant-time operations on the two stacks.

Space Complexity:
The space complexity is O(n), where n is the number of elements in the stack. Both the stack and min_stack can potentially store all elements from the input.
"""


class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)

    def pop(self) -> None:
        if self.stack:
            if self.stack[-1] == self.min_stack[-1]:
                self.min_stack.pop()
            self.stack.pop()

    def top(self) -> int:
        if self.stack:
            return self.stack[-1]

    def getMin(self) -> int:
        if self.min_stack:
            return self.min_stack[-1]
