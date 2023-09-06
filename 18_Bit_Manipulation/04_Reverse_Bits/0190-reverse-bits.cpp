/*
Problem: LeetCode 190 - Reverse Bits

Description:
Reverse bits of a given 32 bits unsigned integer.

Intuition:
To reverse the bits of the given integer, we can use bit manipulation techniques.

Approach:
1. Initialize a variable 'result' to 0, which will store the reversed bits of the input number.
2. Use a for loop to iterate 32 times (since it is a 32-bit integer).
3. For each iteration, shift the 'result' to the left by 1 bit to make space for the next bit.
4. Extract the least significant bit from the input number using the expression (n & 1).
5. Add the extracted bit to the 'result' using the bitwise OR operation (result |= (n & 1)).
6. Right shift the input number by 1 bit to get rid of the least significant bit (n >>= 1).
7. Continue the loop until all 32 bits are processed.
8. After the loop, the 'result' will contain the reversed bits of the input number.
9. Return the 'result'.

Time Complexity:
The time complexity is O(1) since the number of iterations is fixed (32 iterations for a 32-bit integer).

Space Complexity:
The space complexity is O(1) as we only use a constant amount of space to store the 'result' and other variables.
*/

#include <cstdint>

class Solution {
  public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;

        for (int i = 0; i < 32; ++i) {
            result <<= 1;
            result |= (n & 1);
            n >>= 1;
        }

        return result;
    }
};