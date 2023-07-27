/*
Problem: LeetCode 191 - Number of 1 Bits

Description:
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Intuition:
To count the number of '1' bits in the binary representation of a number, we can use the bit manipulation technique. The idea is to repeatedly shift the number to the right and check if the least significant bit is '1'. If it is, then we increment a count variable.

Approach:
1. Initialize a variable 'count' to 0.
2. Iterate while the input number 'n' is not equal to 0.
3. Inside the loop, check if the least significant bit of 'n' is '1'.
4. If it is, increment the 'count' variable.
5. Right-shift 'n' by 1 to move on to the next bit.
6. Continue the loop until all bits are processed.
7. Return the 'count' variable, which contains the number of '1' bits in the input number.

Time Complexity:
The time complexity is O(log n), where n is the value of the input number. The number of iterations in the loop is equal to the number of bits in the binary representation of 'n', which is log(n) base 2.

Space Complexity:
The space complexity is O(1) since we only use a constant amount of extra space for the 'count' variable.
*/

class Solution {
  public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        // Iterate while n is not 0
        while (n != 0) {
            // Check if the least significant bit is 1
            if (n & 1) {
                count++;
            }

            // Right-shift n to move to the next bit
            n >>= 1;
        }

        return count;
    }
};

// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         int count = 0;
//         while (n != 0) {
//             count++;
//             n &= (n - 1); // Clear the least significant 1 bit
//         }
//         return count;
//     }
// };