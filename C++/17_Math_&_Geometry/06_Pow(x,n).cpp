/*
Problem: LeetCode 50 - Pow(x, n)

Description:
Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

Intuition:
To calculate the power x^n, we can use the concept of recursion and divide-and-conquer. The idea is to break down the problem into smaller subproblems and solve them recursively.

Approach:
1. First, we handle the base case where n is 0 or 1. If n is 0, the result is 1. If n is 1, the result is x itself.
2. If n is negative, we convert the problem to calculate 1/x raised to the power -n.
3. To calculate x^n, we can divide the problem into two parts:
   - Calculate x^(n/2) using recursion.
   - If n is even, the result is (x^(n/2)) * (x^(n/2)).
   - If n is odd, the result is (x^(n/2)) * (x^(n/2)) * x.
4. We use a helper function to perform the recursive calculations.

Time Complexity:
The time complexity of this approach is O(log n) because we are dividing the problem size by 2 in each recursive call.

Space Complexity:
The space complexity is O(log n) as well due to the recursive function calls.
*/

class Solution {
  public:
    double myPow(double x, long long n) {
        // Base case: x^0 = 1
        if (n == 0) {
            return 1.0;
        }

        // Base case: x^1 = x
        if (n == 1) {
            return x;
        }

        // If n is negative, calculate 1/x^-n
        if (n < 0) {
            return 1.0 / myPow(x, -n);
        }

        // Calculate x^n using recursion and divide-and-conquer
        double halfPow = myPow(x, n / 2);
        double result = halfPow * halfPow;

        // If n is odd, multiply with x
        if (n % 2 != 0) {
            result *= x;
        }

        return result;
    }
};

/*
// Beats 100% runtime

class Solution {
public:
    double myPow(double x, int n) {
        // Handle negative exponent by inverting the base
        if (n < 0) {
            x = 1 / x;
        }

        // Take the absolute value of the exponent to avoid issues with INT_MIN
        long num = labs(n);

        // Initialize the result to 1
        double pow = 1;

        // Exponentiation by squaring algorithm
        while (num) { // While the exponent is not zero
            if (num & 1) { // If the least significant bit of the exponent is 1
                pow *= x; // Multiply the result by the current base value
            }

            x *= x; // Square the base value for the next iteration
            num >>= 1; // Right-shift the exponent to remove the least significant bit
        }

        return pow;
    }
};
*/