/*
Problem: LeetCode 371 - Sum of Two Integers

Key Idea:
The key idea is to use bitwise operations to perform addition without using the `+` operator. We can use bitwise XOR to perform the addition without carrying, and bitwise AND to calculate the carry.

Approach:
1. Initialize two variables, 'a' and 'b', to represent the two integers to be added.
2. Loop while 'b' is not zero:
   a. Calculate the sum without carrying by performing 'a XOR b' and store it in 'a'.
   b. Calculate the carry by performing '(a AND b) << 1' and store it in 'b'.
3. After the loop, 'a' will contain the result, which is the sum of the two integers.

Time Complexity:
O(1), as the number of iterations in the loop is constant (32 bits for integers).

Space Complexity:
O(1), as we use only a constant amount of extra space.
*/

impl Solution {
    pub fn get_sum(a: i32, b: i32) -> i32 {
        let mut x = a;
        let mut y = b;

        while y != 0 {
            let carry = x & y;
            x = x ^ y;
            y = carry << 1;
        }

        x
    }
}

/*
impl Solution {
    pub fn get_sum(a: i32, b: i32) -> i32 {
        return [a, b].iter().sum();
    }
}
*/
