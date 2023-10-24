/*
Problem: LeetCode 268 - Missing Number

Description:
Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array.

Intuition:
We can use the mathematical concept of finding the sum of the first n natural numbers
and subtract the sum of the elements in the given array to find the missing number.

Approach:
1. Initialize a variable 'expectedSum' to store the sum of the first n natural numbers.
2. Iterate through the array 'nums' and calculate the sum of its elements, storing it in the variable 'actualSum'.
3. Calculate the missing number as 'expectedSum - actualSum' and return it.

Time Complexity:
The time complexity is O(n) as we need to iterate through the entire array once to calculate the sum of its elements.

Space Complexity:
The space complexity is O(1) as we use only a constant amount of extra space to store variables.
*/

class Solution {
  public:
    int missingNumber(std::vector<int> &nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;

        for (int num : nums) {
            actualSum += num;
        }

        return expectedSum - actualSum;
    }
};