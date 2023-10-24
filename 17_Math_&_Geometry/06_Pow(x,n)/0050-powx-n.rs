/*
Problem: LeetCode 50 - Pow(x, n)

Key Idea:
The key idea is to use the concept of exponentiation by squaring to calculate the power efficiently. Instead of multiplying 'x' by itself 'n' times, we can recursively calculate 'x' raised to 'n/2' and use that result to calculate 'x' raised to 'n'.

Approach:
1. Handle the base cases:
   - If 'n' is 0, return 1 because any number raised to the power of 0 is 1.
   - If 'n' is negative, calculate the reciprocal of 'x' and negate 'n' to make it positive. This allows us to handle negative exponents.
2. Calculate 'x' raised to 'n' by recursively calculating 'x' raised to 'n/2'.
3. Use the result from step 2 to calculate 'x' raised to 'n':
   - If 'n' is even, return the square of the result from step 2.
   - If 'n' is odd, return the square of the result from step 2 multiplied by 'x'.
4. The recursion terminates when 'n' becomes 0.

Time Complexity:
O(log n), where 'n' is the exponent. We reduce the problem size by half in each recursive step.

Space Complexity:
O(log n), as the maximum depth of the recursion stack is proportional to the logarithm of 'n'.
*/

impl Solution {
    pub fn my_pow(x: f64, n: i32) -> f64 {
        if n == 0 {
            return 1.0;
        }

        let mut x = x;
        let mut n = n as i64;

        if n < 0 {
            x = 1.0 / x;
            n = -n;
        }

        let mut result = 1.0;
        let mut current_x = x;

        while n > 0 {
            if n % 2 == 1 {
                result *= current_x;
            }
            current_x *= current_x;
            n /= 2;
        }

        result
    }
}
