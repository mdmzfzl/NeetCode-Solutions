/*
Problem: LeetCode 739 - Daily Temperatures

Key Idea:
The key idea is to use a stack to keep track of the indices of the temperatures while iterating through the array.

Approach:
1. Initialize an empty stack to store indices of temperatures.
2. Initialize a result vector `result` of the same length as the input `temperatures` with all values set to 0.
3. Iterate through the `temperatures` array with an index `i`:
   - While the stack is not empty and the temperature at the current index `i` is greater than the temperature at the index at the top of the stack, pop elements from the stack and calculate the difference between their indices and `i`. Set this difference as the value at the corresponding index in the `result` vector.
   - Push the current index `i` onto the stack.
4. After the loop, the stack may still contain indices of temperatures for which there were no warmer days. Set the values at these indices in the `result` vector to 0.
5. Return the `result` vector.

Time Complexity:
O(n), where n is the length of the input `temperatures`. We perform a single pass through the array.

Space Complexity:
O(n), as the stack can store at most n elements.
*/

impl Solution {
    pub fn daily_temperatures(temperatures: Vec<i32>) -> Vec<i32> {
        let mut result: Vec<i32> = vec![0; temperatures.len()];
        let mut stack: Vec<usize> = Vec::new();

        for (i, &temp) in temperatures.iter().enumerate() {
            while let Some(&prev_index) = stack.last() {
                if temp > temperatures[prev_index] {
                    stack.pop();
                    result[prev_index] = (i - prev_index) as i32;
                } else {
                    break;
                }
            }
            stack.push(i);
        }

        result
    }
}
