/*
Problem: LeetCode 155 - Min Stack

Key Idea:
The key idea is to maintain a stack that not only stores elements but also keeps track of the minimum element in the stack at any point.

Approach:
1. Create a stack to store elements.
2. Create a second stack to store the minimum elements.
3. For each push operation, push the element onto the main stack.
   - If the second stack is empty or the element is less than or equal to the top element of the second stack, push the element onto the second stack as the new minimum.
4. For each pop operation, pop the top element from the main stack.
   - If the popped element is equal to the top element of the second stack (i.e., the current minimum), pop the top element from the second stack as well to update the minimum.
5. For each top operation, return the top element of the main stack.
6. For each get_min operation, return the top element of the second stack, which represents the current minimum element.

Time Complexity:
- Push, pop, top, and get_min operations all have O(1) time complexity as we perform constant-time stack operations.

Space Complexity:
- O(n), where n is the number of elements in the stack. We maintain two separate stacks to store elements and minimums.
*/

struct MinStack {
    stack: Vec<i32>,
    min_stack: Vec<i32>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MinStack {
    fn new() -> Self {
        MinStack {
            stack: Vec::new(),
            min_stack: Vec::new(),
        }
    }

    fn push(&mut self, val: i32) {
        self.stack.push(val);
        if self.min_stack.is_empty() || val <= *self.min_stack.last().unwrap() {
            self.min_stack.push(val);
        }
    }

    fn pop(&mut self) {
        if let Some(top) = self.stack.pop() {
            if top == *self.min_stack.last().unwrap() {
                self.min_stack.pop();
            }
        }
    }

    fn top(&self) -> i32 {
        *self.stack.last().unwrap()
    }

    fn get_min(&self) -> i32 {
        *self.min_stack.last().unwrap()
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * let obj = MinStack::new();
 * obj.push(val);
 * obj.pop();
 * let ret_3: i32 = obj.top();
 * let ret_4: i32 = obj.get_min();
 */
 