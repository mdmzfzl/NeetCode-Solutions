/*
Problem: LeetCode 190 - Reverse Bits

Key Idea:
We can iterate through the bits of 'n' from the least significant bit to the most significant bit and construct the reversed number bit by bit.

Approach:
1. Initialize a variable 'result' to 0. This variable will store the reversed bits.
2. Iterate through 'n' while it's not zero:
   a. Right-shift 'result' by one position to make space for the next bit.
   b. Check if the least significant bit of 'n' is 1 using 'n & 1'.
   c. If it's 1, set the least significant bit of 'result' to 1 using 'result |= 1'.
   d. Right-shift 'n' by one position to process the next bit.
3. Repeat steps 2a-2d until 'n' becomes zero.
4. After the loop, 'result' will contain the reversed bits of 'n'.
5. Return 'result' as the result.

Time Complexity:
O(32) or O(1), since we iterate through a constant number of bits (32 bits in an unsigned integer).

Space Complexity:
O(1), as we use a constant amount of extra space.
*/

impl Solution {
    pub fn reverse_bits(n: u32) -> u32 {
        let mut result = 0;
        let mut n = n;

        for _ in 0..32 {
            result <<= 1;
            if n & 1 == 1 {
                result |= 1;
            }
            n >>= 1;
        }

        result
    }
}

/*
impl Solution {
    pub fn reverse_bits(mut x: u32) -> u32 {
        x.reverse_bits()
    }
}
*/
