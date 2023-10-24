/*
Problem: LeetCode 84 - Largest Rectangle in Histogram

Key Idea:
The key idea is to use a stack to keep track of the indices of the histogram bars while iterating through the heights.

Approach:
1. Initialize an empty stack to store indices of histogram bars.
2. Initialize variables `max_area` and `i` to store the maximum area and the current index.
3. Iterate through the heights array:
   - While the stack is not empty and the current height is less than the height at the index at the top of the stack, pop elements from the stack and calculate the area using the height at the popped index and the difference between the current index and the index at the top of the stack. Update `max_area` if the calculated area is greater.
   - Push the current index onto the stack.
4. After the loop, there may be remaining elements in the stack. For each remaining index in the stack, pop it and calculate the area using the height at the popped index and the difference between the current index and the popped index. Update `max_area` if the calculated area is greater.
5. Return `max_area` as the largest rectangle area.

Time Complexity:
O(n), where n is the number of heights in the input array. We perform a single pass through the heights.

Space Complexity:
O(n), as the stack can store at most n indices.
*/

impl Solution {
    pub fn largest_rectangle_area(heights: Vec<i32>) -> i32 {
        let mut stack: Vec<usize> = Vec::new();
        let mut max_area = 0;
        let mut i = 0;

        while i < heights.len() {
            if stack.is_empty() || heights[i] >= heights[*stack.last().unwrap()] {
                stack.push(i);
                i += 1;
            } else {
                let top = stack.pop().unwrap();
                let width = if stack.is_empty() {
                    i
                } else {
                    i - stack.last().unwrap() - 1
                };
                max_area = max_area.max(heights[top] * width as i32);
            }
        }

        while !stack.is_empty() {
            let top = stack.pop().unwrap();
            let width = if stack.is_empty() {
                i
            } else {
                i - stack.last().unwrap() - 1
            };
            max_area = max_area.max(heights[top] * width as i32);
        }

        max_area
    }
}
