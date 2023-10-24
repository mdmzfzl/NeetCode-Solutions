/*
Problem: LeetCode 167 - Two Sum II - Input array is sorted

Description:
Given an array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.
Return the indices of the two numbers (1-indexed) as an integer array answer of size 2, where 1 <= answer[0] < answer[1] <= numbers.length.
You may assume that each input would have exactly one solution and you may not use the same element twice.

Intuition:
Since the input array is sorted, we can use a two-pointer approach to find the two numbers that sum up to the target. By maintaining two pointers, one pointing to the start of the array and the other pointing to the end, we can narrow down the search space based on the comparison of the current sum with the target.

Approach:
1. Initialize two pointers, `left` pointing to the start of the array (index 0) and `right` pointing to the end of the array.
2. Iterate while `left` is less than `right`:
   - Calculate the current sum of the elements at `left` and `right`.
   - If the sum is equal to the target, return the indices (`left + 1` and `right + 1`) as the answer.
   - If the sum is less than the target, increment `left` to consider a larger element.
   - If the sum is greater than the target, decrement `right` to consider a smaller element.
3. If no solution is found, return an empty vector.

Time Complexity:
The time complexity is O(n), where n is the number of elements in the input array. In the worst case, we iterate through the entire array once.

Space Complexity:
The space complexity is O(1) as we are using a constant amount of space to store the pointers and perform the comparison.
*/

class Solution {
  public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int left = 0, right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {};
    }
};