/*
Problem: LeetCode 43 - Multiply Strings

Description:
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Intuition:
The basic idea behind multiplying two numbers represented as strings is to simulate the process of multiplication as we do on paper. We start with the least significant digits of both numbers and multiply them. We keep track of the carry and add the product to the corresponding position in the result string. We continue this process for all digits of both numbers, considering the correct position of the result digits based on the multiplication.

Approach:
1. Create a result string to store the final product.
2. Initialize an array to store the intermediate products (i.e., the products of each digit in num1 with each digit in num2).
3. Traverse num1 and num2 from right to left, and calculate all the intermediate products, storing them in the array.
4. Calculate the carry and the sum at each position of the result string, taking into account the intermediate products and any previous carry.
5. After completing the traversal and calculations, the result string will hold the final product.

Time Complexity:
The time complexity of this approach is O(m * n), where m and n are the lengths of num1 and num2, respectively.

Space Complexity:
The space complexity is O(m + n) to store the intermediate products.
*/

class Solution {
  public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        vector<int> products(m + n, 0); // To store intermediate products
        string result = "";

        // Calculate intermediate products
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + products[i + j + 1]; // Add to the existing intermediate product
                products[i + j] += sum / 10; // Carry
                products[i + j + 1] = sum % 10; // Store the digit at correct position
            }
        }

        // Build the result string
        for (int p : products) {
            if (!(result.empty() && p == 0)) {
                result += to_string(p);
            }
        }

        return result.empty() ? "0" : result;
    }
};