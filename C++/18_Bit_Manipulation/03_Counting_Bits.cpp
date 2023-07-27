/*
Problem: LeetCode 338 - Counting Bits

Description:
Given a non-negative integer num, for every number i in the range 0 ≤ i ≤ num,
calculate the number of 1's in their binary representation and return them as an array.

Intuition:
To count the number of '1' bits in the binary representation of each number, we can use dynamic programming.
The idea is to utilize the previously calculated results to build the result for the current number.

Approach:
1. Create a vector 'result' of size num+1 to store the counts for all numbers from 0 to num.
2. Initialize the first element of 'result' to 0 since the number 0 has 0 '1' bits.
3. Use a for loop to iterate from 1 to num.
4. For each number i, the number of '1' bits can be calculated using the expression result[i] = result[i >> 1] + (i & 1).
   - The expression (i >> 1) calculates the number obtained by right-shifting i by one bit, which is equivalent to dividing i by 2.
   - The expression (i & 1) checks if the least significant bit of i is '1'.
   - The count of '1' bits for i is the count of '1' bits for (i >> 1) plus the count of the least significant bit (i & 1).
5. Continue the loop until all numbers from 0 to num are processed.
6. Return the 'result' vector containing the counts for all numbers.

Time Complexity:
The time complexity is O(n), where n is the value of the input number 'num'.
The loop iterates 'num' times to calculate the count of '1' bits for each number.

Space Complexity:
The space complexity is O(n) as we use a vector of size 'num+1' to store the counts for all numbers from 0 to num.
*/

class Solution {
  public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1, 0);

        for (int i = 1; i <= num; ++i) {
            result[i] = result[i >> 1] + (i & 1);
        }

        return result;
    }
};

// class Solution {
// public:
//     vector<int> countBits(int num) {
//         vector<int> result(num + 1, 0);

//         for (int i = 1; i <= num; ++i) {
//             result[i] = result[i & (i - 1)] + 1;
//         }

//         return result;
//     }
// };