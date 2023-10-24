/*
Problem: LeetCode 136 - Single Number

Description:
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

Intuition:
Since all elements appear twice in the array except for one, we can use the XOR operation to find the single element. The XOR operation on two equal numbers results in 0, so XORing all the numbers in the array will give us the single number that appears only once.

Approach:
1. Initialize a variable 'result' to 0.
2. Iterate through the elements in the array 'nums'.
3. For each element, XOR it with the 'result'.
4. The final value of 'result' will be the single number that appears only once.

Time Complexity:
The time complexity is O(n), where n is the number of elements in the array 'nums'. We iterate through the array once to perform the XOR operation.

Space Complexity:
The space complexity is O(1) since we only use a constant amount of extra space for the 'result' variable.
*/

class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        int result = 0;

        // Perform XOR operation on all elements in the array
        for (int num : nums) {
            result ^= num;
        }

        return result;
    }
};