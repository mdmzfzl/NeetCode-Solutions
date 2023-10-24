/*
Problem: LeetCode 7 - Reverse Integer

Key Idea:
We can repeatedly extract the last digit of 'x' and append it to the result while updating 'x' by removing the last digit.

Approach:
1. Initialize a variable 'result' to 0. This variable will store the reversed integer.
2. Iterate while 'x' is not zero:
   a. Calculate the last digit of 'x' by taking 'x % 10'.
   b. Update 'result' by multiplying it by 10 and adding the last digit.
   c. Update 'x' by removing the last digit using 'x / 10'.
3. After the loop, 'result' will contain the reversed integer.
4. Check for overflow by comparing 'result' with the maximum and minimum values of a 32-bit integer.
5. Return 0 if 'result' overflows, otherwise return 'result'.

Time Complexity:
O(log(x)), where 'x' is the input integer. We iterate through the digits of 'x'.

Space Complexity:
O(1), as we use only a constant amount of extra space.
*/

impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let mut result = 0;
        let mut x = x;

        while x != 0 {
            let digit = x % 10;
            // Check for overflow
            if result > i32::MAX / 10 || (result == i32::MAX / 10 && digit > 7) {
                return 0;
            }
            if result < i32::MIN / 10 || (result == i32::MIN / 10 && digit < -8) {
                return 0;
            }
            result = result * 10 + digit;
            x /= 10;
        }

        result
    }
}

/*
// One liner

impl Solution {
    pub fn reverse(x: i32) -> i32 {
        x.abs()
            .to_string()
            .chars()
            .rev()
            .collect::<String>()
            .parse::<i32>()
            .map(|r| r * x.signum())
            .unwrap_or(0)
    }
}
*/
