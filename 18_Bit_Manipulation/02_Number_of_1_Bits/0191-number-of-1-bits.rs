/*
Problem: LeetCode 191 - Number of 1 Bits

Key Idea:
The key idea is to use bit manipulation. Iterate through the bits of the integer and use bitwise AND operation to check if each bit is 1. Increment a count variable for each 1 bit encountered. Repeat this process until all bits have been checked to count the number of 1 bits in the integer.

Approach:
1. Initialize a variable 'count' to 0. This variable will store the number of set bits.
2. Iterate through each bit of the input integer 'n' from the least significant bit to the most significant bit.
3. To check if a bit is set (1), perform a bitwise AND operation between 'n' and 1 (binary 0001).
4. If the result of the bitwise AND operation is not zero, increment the 'count' variable.
5. Right-shift 'n' by one position to check the next bit.
6. Repeat steps 3-5 until 'n' becomes zero.
7. Return the 'count' as the number of set bits.

Time Complexity:
O(log n), where 'n' is the input integer. We iterate through each bit in the binary representation of 'n'.

Space Complexity:
O(1), as we use a constant amount of extra space.
*/

impl Solution {
    pub fn hammingWeight(n: u32) -> i32 {
        let mut count = 0;
        let mut n = n;

        while n != 0 {
            if n & 1 != 0 {
                count += 1;
            }
            n >>= 1;
        }

        count
    }
}

/*
// short solution

impl Solution {
    pub fn hammingWeight(n: u32) -> i32 {
        n.count_ones() as i32
    }
}
*/
