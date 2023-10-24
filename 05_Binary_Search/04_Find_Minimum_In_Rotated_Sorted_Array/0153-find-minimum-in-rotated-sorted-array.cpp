/*
Problem: LeetCode 153 - Find Minimum in Rotated Sorted Array

Description:
Suppose an array of length n is sorted in ascending order, rotated at some pivot unknown to you beforehand. You are given a target value to search for. If found in the array, return its index, otherwise return -1.

Intuition:
To find the minimum element in the rotated sorted array, we can utilize the property that the minimum element is the only element that is smaller than its adjacent elements. By performing a modified version of binary search, we can efficiently locate the minimum element.

Approach:
1. Initialize left and right pointers to the start and end of the array.
2. While the left pointer is less than the right pointer:
   - Calculate the middle index as (left + right) / 2.
   - If the middle element is greater than the last element, the minimum element is on the right side of the middle. Update the left pointer to middle + 1.
   - If the middle element is less than or equal to the last element, the minimum element is on the left side of the middle. Update the right pointer to middle.
3. Return the element at the left pointer, which represents the minimum element.

Time Complexity:
The time complexity is O(log n), where n is the length of the array. At each step, the search space is divided in half.

Space Complexity:
The space complexity is O(1), as the algorithm uses a constant amount of extra space.
*/

class Solution {
  public:
    int findMin(vector<int> &nums) {
        int left = 0; // Initialize the left pointer to the start of the array
        int right = nums.size() - 1; // Initialize the right pointer to the end of the array

        while (left < right) { // Perform binary search until left pointer is less than right pointer
            int middle = left + (right - left) / 2; // Calculate the middle index

            if (nums[middle] > nums[right]) {
                // If the middle element is greater than the last element,
                // it means the rotation point is on the right side of the middle.
                // Update the left pointer to middle + 1 to search in the right half.
                left = middle + 1;
            } else {
                // If the middle element is less than or equal to the last element,
                // it means the rotation point is on the left side of the middle or the middle element itself.
                // Update the right pointer to middle to search in the left half.
                right = middle;
            }
        }

        return nums[left]; // Return the element at the left pointer, which represents the minimum element.
    }
};

// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int low = 0;
//         int high = nums.size() - 1;

//         // not low <= high since not searching for target
//         while (low < high) {
//             int mid = low + (high - low) / 2;
//             // ex. [3,4,5,6,7,8,9,1,2], mid = 4, high = 8
//             // nums[mid] > nums[high], min must be right
//             if (nums[mid] > nums[high]) {
//                 // never consider mid bc know for sure not min
//                 low = mid + 1;
//             // ex. [8,9,1,2,3,4,5,6,7], mid = 4, high = 8
//             // nums[mid] <= nums[right], min must be left
//             } else {
//                 // consider mid still bc could be min
//                 high = mid;
//             }
//         }

//         // low lands on correct value, never disqualified mins
//         return nums[low];
//     }
// };