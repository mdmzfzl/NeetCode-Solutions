/*
Problem: LeetCode 4 - Median of Two Sorted Arrays

Key Idea:
The key idea is to perform a binary search on the smaller of the two arrays while ensuring a balanced partition between the arrays. This involves comparing elements near the middle to find the correct partition point and calculate the median based on the partitioned elements. Continue adjusting the partition until you find the median.

Approach:
1. Let's denote the two input arrays as nums1 and nums2.
2. Find the smaller of the two array lengths: n and m, where n = nums1.len() and m = nums2.len().
3. Perform a binary search on the smaller array (nums1) to partition it into two parts: left_part and right_part, such that:
   - The length of left_part is (n + m + 1) / 2, rounded down.
   - The maximum element in left_part is less than or equal to the minimum element in right_part.
4. Calculate the median based on left_part and right_part:
   - If n + m is odd, the median is the maximum element in left_part.
   - If n + m is even, the median is the average of the maximum element in left_part and the minimum element in right_part.
5. Implement the binary search:
   - Initialize two pointers, left1 and right1, to perform binary search on nums1.
   - Compute the corresponding positions left2 and right2 in nums2.
   - Adjust the pointers based on the comparison of elements at these positions.
   - Continue the binary search until the correct partition is found.

Time Complexity:
- The binary search has a time complexity of O(log(min(n, m))).

Space Complexity:
- The space complexity is O(1) as we are using a constant amount of extra space.
*/

use std::cmp::max;
use std::cmp::min;

impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let (nums1, nums2) = if nums1.len() <= nums2.len() {
            (nums1, nums2)
        } else {
            (nums2, nums1)
        };

        let (n, m) = (nums1.len(), nums2.len());
        let half_len = (n + m + 1) / 2;
        let (mut left1, mut right1) = (0, n);

        while left1 <= right1 {
            let partition1 = (left1 + right1) / 2;
            let partition2 = half_len - partition1;

            let max_left1 = if partition1 == 0 {
                i32::MIN
            } else {
                nums1[partition1 - 1]
            };
            let min_right1 = if partition1 == n {
                i32::MAX
            } else {
                nums1[partition1]
            };

            let max_left2 = if partition2 == 0 {
                i32::MIN
            } else {
                nums2[partition2 - 1]
            };
            let min_right2 = if partition2 == m {
                i32::MAX
            } else {
                nums2[partition2]
            };

            if max_left1 <= min_right2 && max_left2 <= min_right1 {
                if (n + m) % 2 == 0 {
                    return (max_left1.max(max_left2) as f64 + min_right1.min(min_right2) as f64)
                        / 2.0;
                } else {
                    return max_left1.max(max_left2) as f64;
                }
            } else if max_left1 > min_right2 {
                right1 = partition1 - 1;
            } else {
                left1 = partition1 + 1;
            }
        }

        0.0 // This should not be reached
    }
}

/*
// Merging arrays

impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let mut merged = Vec::with_capacity(nums1.len() + nums2.len());
        let (mut i, mut j) = (0, 0);

        while i < nums1.len() && j < nums2.len() {
            if nums1[i] <= nums2[j] {
                merged.push(nums1[i]);
                i += 1;
            } else {
                merged.push(nums2[j]);
                j += 1;
            }
        }

        while i < nums1.len() {
            merged.push(nums1[i]);
            i += 1;
        }

        while j < nums2.len() {
            merged.push(nums2[j]);
            j += 1;
        }

        let len = merged.len();
        if len % 2 == 0 {
            let mid = len / 2;
            (merged[mid - 1] as f64 + merged[mid] as f64) / 2.0
        } else {
            merged[len / 2] as f64
        }
    }
}
*/

/*
// Short solution

impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let mut merged = nums1.iter().chain(&nums2).copied().collect::<Vec<_>>();
        merged.sort();

        let mid = merged.len() / 2;
        if merged.len() % 2 == 0 {
            (merged[mid - 1] as f64 + merged[mid] as f64) / 2.0
        } else {
            merged[mid] as f64
        }
    }
}
*/
