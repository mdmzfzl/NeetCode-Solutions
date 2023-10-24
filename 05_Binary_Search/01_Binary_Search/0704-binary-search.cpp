/*
Problem: LeetCode 704 - Binary Search

Description:
Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.

Intuition:
Binary search is a widely used algorithm to efficiently search for a target element in a sorted array. It works by repeatedly dividing the search space in half until the target element is found or determined to be not present.

Approach:
1. Initialize left and right pointers to the start and end of the array.
2. While the left pointer is less than or equal to the right pointer:
   - Calculate the middle index as (left + right) / 2.
   - If the middle element is equal to the target, return the middle index.
   - If the middle element is greater than the target, update the right pointer to middle - 1.
   - If the middle element is less than the target, update the left pointer to middle + 1.
3. If the target is not found after the while loop, return -1.

Time Complexity:
The time complexity of binary search is O(log n), where n is the number of elements in the array. At each step, the search space is divided in half.

Space Complexity:
The space complexity is O(1), as the algorithm uses a constant amount of extra space to store the left and right pointers.
*/

class Solution {
  public:
    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};