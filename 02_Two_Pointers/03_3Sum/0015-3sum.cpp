/*
Problem: LeetCode 15 - 3Sum

Description:
Given an array nums of n integers, find all unique triplets in the array which gives the sum of zero.
The solution set must not contain duplicate triplets.

Intuition:
To find unique triplets that sum up to zero, we can leverage the two-pointer approach. By sorting the array and iterating through each element, we can convert the problem into finding two numbers that sum up to the negation of the current element.

Approach:
1. Sort the input array `nums` in non-decreasing order.
2. Iterate through each element `nums[i]` from 0 to n-3 (exclusive):
   - If `i > 0` and `nums[i]` is equal to `nums[i-1]`, skip the current iteration to avoid duplicate triplets.
   - Initialize two pointers, `left` pointing to the element next to `nums[i]`, and `right` pointing to the last element of the array.
   - Iterate while `left` is less than `right`:
     - Calculate the current sum of the elements `nums[i]`, `nums[left]`, and `nums[right]`.
     - If the sum is equal to zero, add the triplet `[nums[i], nums[left], nums[right]]` to the result.
       - Increment `left` and decrement `right` to search for the next pair of elements.
       - Skip any duplicate values of `nums[left]` and `nums[right]` to avoid duplicate triplets.
     - If the sum is less than zero, increment `left`.
     - If the sum is greater than zero, decrement `right`.
3. Return the result, which contains all unique triplets that sum up to zero.

Time Complexity:
The time complexity is O(n^2), where n is the number of elements in the input array. Sorting the array takes O(nlogn) time, and iterating through the array with two pointers takes O(n^2) time.

Space Complexity:
The space complexity is O(1) as we are using a constant amount of space to store the pointers and the result.
*/

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1, right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return result;
    }
};