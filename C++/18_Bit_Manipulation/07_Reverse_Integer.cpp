/*
Problem: LeetCode 7 - Reverse Integer

Description:
Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

Intuition:
To reverse an integer, we can repeatedly extract the last digit of the number and add it to the result after multiplying the result by 10.

Approach:
1. Initialize a variable 'result' to store the reversed number and set it to 0.
2. While the input 'x' is not equal to 0:
   a. Extract the last digit of 'x' using 'x % 10'.
   b. Check if 'result' is going to overflow:
      - If 'result' is greater than INT_MAX/10 or 'result' is equal to INT_MAX/10 and the last digit is greater than 7, then return 0.
   c. Multiply 'result' by 10 and add the last digit to it.
   d. Update 'x' by removing the last digit using 'x /= 10'.
3. Return the 'result' as the reversed number.

Time Complexity:
The time complexity of this approach is O(log(x)), where x is the given input number.

Space Complexity:
The space complexity is O(1) as we are using only a constant amount of extra space.
*/

class Solution {
  public:
    int reverse(int x) {
        int result = 0;

        while (x != 0) {
            int lastDigit = x % 10;

            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && lastDigit > 7)) {
                return 0;
            }

            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && lastDigit < -8)) {
                return 0;
            }

            result = result * 10 + lastDigit;
            x /= 10;
        }

        return result;
    }
};