/*
Problem: LeetCode 371 - Sum of Two Integers

Description:
Given two integers a and b, return the sum of the two integers without using the '+' and '-' operators.

Intuition:
We can use bitwise operations to perform addition without using the '+' operator.
The bitwise XOR operation (^) will give us the sum of two integers without considering the carry.
To handle the carry, we can use the bitwise AND operation (&) and left shift (<<) to calculate the carry.

Approach:
1. While 'b' is not equal to 0 (there is still a carry):
   a. Calculate the carry as 'carry = a & b'.
   b. Update 'a' as 'a = a ^ b' to get the sum without carry.
   c. Update 'b' as 'b = carry << 1' to prepare for the next iteration.

2. Return 'a' as the final sum.

Time Complexity:
The time complexity is O(1) because we perform a constant number of bitwise operations.

Space Complexity:
The space complexity is O(1) as we use only a constant amount of extra space.
*/

class Solution {
  public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (unsigned int)(a & b) << 1; // Use unsigned int to handle negative numbers
            a = a ^ b;
            b = carry;
        }

        return a;
    }
};