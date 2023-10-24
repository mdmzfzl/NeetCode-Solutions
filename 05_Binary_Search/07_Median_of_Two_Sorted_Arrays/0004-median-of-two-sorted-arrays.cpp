/*
Problem: LeetCode 4 - Median of Two Sorted Arrays

Description:
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Intuition:
To find the median of two sorted arrays, we need to divide the combined array into two equal halves. The median is the middle element or the average of the two middle elements, depending on whether the total number of elements is odd or even. Since the arrays are sorted, we can leverage binary search and partitioning to find the median efficiently.

Approach:
1. Ensure that nums1 is the smaller array. If not, swap nums1 and nums2.
2. Use binary search to find the correct partitioning point in the smaller array (nums1).
3. The partition point i divides nums1 into two parts: elements before i form the left half, and elements after i form the right half.
4. Calculate the partition point j in nums2 based on i, such that j = (m + n + 1) / 2 - i, where m is the size of nums1 and n is the size of nums2.
5. Check if the partitioning is valid by comparing the maximum element of the left half (maxLeft) with the minimum element of the right half (minRight).
6. If the partitioning is valid, calculate the median based on the array sizes and the partition points:
   - If the total number of elements (m + n) is odd, the median is maxLeft.
   - If the total number of elements is even, the median is the average of maxLeft and minRight.
7. If the partitioning is not valid, adjust the partition points using binary search until a valid partitioning is found.
8. Return the median.

Time Complexity:
The time complexity of the approach is O(log(min(m, n))), where m and n are the sizes of the input arrays. The binary search is performed on the smaller array.

Space Complexity:
The space complexity is O(1) as the approach uses only a constant amount of extra space.

*/

class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            nums1.swap(nums2);
        }

        int m = nums1.size();
        int n = nums2.size();
        int left = 0;
        int right = m;
        int halfLen = (m + n + 1) / 2;

        while (left <= right) {
            int i = left + (right - left) / 2; // Partition point in nums1
            int j = halfLen - i; // Partition point in nums2

            if (i < m && nums2[j - 1] > nums1[i]) {
                // i is too small, increase it to the right half
                left = i + 1;
            } else if (i > 0 && nums1[i - 1] > nums2[j]) {
                // i is too large, decrease it to the left half
                right = i - 1;
            } else {
                // Found the correct partitioning
                int maxLeft = 0;

                if (i == 0) {
                    maxLeft = nums2[j - 1];
                } else if (j == 0) {
                    maxLeft = nums1[i - 1];
                } else {
                    maxLeft = max(nums1[i - 1], nums2[j - 1]);
                }

                if ((m + n) % 2 == 1) {
                    return maxLeft; // Odd number of elements, median is the max of the left half
                }

                int minRight = 0;

                if (i == m) {
                    minRight = nums2[j];
                } else if (j == n) {
                    minRight = nums1[i];
                } else {
                    minRight = min(nums1[i], nums2[j]);
                }

                return (maxLeft + minRight) / 2.0; // Even number of elements, median is the average of max left and min right
            }
        }

        // Should never reach this point
        return 0.0;
    }
};

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         if (nums1.size() > nums2.size()) {
//             // if nums1 is bigger we swap it because we're gonna assume nums1 is smaller
//             return findMedianSortedArrays(nums2, nums1);
//         }

//         int m = nums1.size();
//         int n = nums2.size();

//         double Answer = 0.0;

//         // Now that nums1 is smaller
//         int L = 0, R = m;

//         while(L <= R) {
//             // Mid of nums1 & nums2
//             int MidM = L + (R-L)/2;
//             int MidN = (m+n+1)/2 - MidM;

//             int a = (MidM > 0) ? nums1[MidM - 1] : INT_MIN;
//             int b = (MidM < m) ? nums1[MidM] : INT_MAX;
//             int c = (MidN > 0) ? nums2[MidN - 1] : INT_MIN;
//             int d = (MidN < n) ? nums2[MidN] : INT_MAX;


//             // If both halves are correctly sorted
//             if(a <= d && c <= b) {
//                 // Checking if the merged array has even elements or odd
//                 if( (m + n) % 2 == 0)
//                     Answer = (max(a, c) + min(b, d)) / 2.0;
//                 else
//                     Answer = max(a, c);

//                 break;
//             }

//             // If not correctly sorted and right part of nums2 is lesser than left part of nums1
//             else if(d < a)
//                 R = MidM - 1;
//             // If not correctly sorted and right side of nums1 is lesser than left part of nums2 i.e. c < b
//             else
//                 L = MidM + 1;
//         }

//         return Answer;
//     }
// };