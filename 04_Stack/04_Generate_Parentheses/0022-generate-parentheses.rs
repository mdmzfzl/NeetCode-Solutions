/*
Problem: LeetCode 22 - Generate Parentheses

Key Idea:
The key idea is to use recursion to generate all valid combinations of parentheses.

Approach:
1. Initialize an empty vector `result` to store the generated combinations.
2. Create a recursive function `generate` that takes four arguments: `current` (the current combination), `open` (the number of open parentheses used), `close` (the number of closing parentheses used), and `n` (the total number of pairs).
3. In the `generate` function:
   - If `current` is of length `2 * n`, it means a valid combination is generated, so add it to the `result` vector.
   - If `open` is less than `n`, it means we can add an open parenthesis. Recursively call `generate` with `current` + '(', `open + 1`, `close`, and `n`.
   - If `close` is less than `open`, it means we can add a closing parenthesis. Recursively call `generate` with `current` + ')', `open`, `close + 1`, and `n`.
4. Start the recursion with an empty `current`, `open` and `close` as 0, and `n` as the given input.
5. Return the `result` vector containing all valid combinations.

Time Complexity:
O(2^n), where n is the number of pairs. Each valid combination has a length of 2 * n, and there are 2^(2n) possible combinations.

Space Complexity:
O(2^n), as there can be a total of 2^(2n) valid combinations in the result vector.
*/

impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut result: Vec<String> = Vec::new();

        fn generate(current: String, open: i32, close: i32, n: i32, result: &mut Vec<String>) {
            if current.len() == (2 * n) as usize {
                result.push(current);
                return;
            }

            if open < n {
                generate(current.clone() + "(", open + 1, close, n, result);
            }

            if close < open {
                generate(current.clone() + ")", open, close + 1, n, result);
            }
        }

        generate("".to_string(), 0, 0, n, &mut result);
        result
    }
}
