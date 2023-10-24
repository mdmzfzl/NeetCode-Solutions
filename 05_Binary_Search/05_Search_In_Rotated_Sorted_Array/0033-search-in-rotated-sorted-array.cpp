/*
Problem: LeetCode 33 - Search in Rotated Sorted Array

Description:
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand. You are given a target value to search for. If found in the array, return its index, otherwise return -1.
You may assume no duplicate exists in the array.

Intuition:
To search for a target value efficiently in the rotated sorted array, we can utilize a modified version of binary search. By comparing the target value with the array elements and adjusting the search space based on the rotation point, we can find the target value or determine its absence.

Approach:
1. Initialize the left and right pointers to the start and end of the array.
2. While the left pointer is less than or equal to the right pointer:
   - Calculate the middle index as (left + right) / 2.
   - If the middle element is equal to the target value, return the middle index.
   - If the left half of the array is sorted:
     - If the target value is within the range of the left half, update the right pointer to middle - 1.
     - Otherwise, update the left pointer to middle + 1.
   - If the right half of the array is sorted:
     - If the target value is within the range of the right half, update the left pointer to middle + 1.
     - Otherwise, update the right pointer to middle - 1.
3. If the target value is not found after the while loop, return -1.

Time Complexity:
The time complexity is O(log n), where n is the size of the array. At each step, the search space is divided in half.

Space Complexity:
The space complexity is O(1), as the algorithm uses a constant amount of extra space.
*/

class Solution {
  public:
    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int middle = left + (right - left) / 2;

            if (nums[middle] == target) { // If middle element is equal to the target value, return the middle index
                return middle;
            }

            if (nums[left] <= nums[middle]) { // If left half of the array is sorted
                if (target >= nums[left] && target < nums[middle]) { // If target value is within the range of the left half
                    right = middle - 1; // Update the right pointer to search in the left half
                } else {
                    left = middle + 1; // Update the left pointer to search in the right half
                }
            } else { // If right half of the array is sorted
                if (target > nums[middle] && target <= nums[right]) { // If target value is within the range of the right half
                    left = middle + 1; // Update the left pointer to search in the right half
                } else {
                    right = middle - 1; // Update the right pointer to search in the left half
                }
            }
        }

        return -1; // Target value not found, return -1
    }
};
