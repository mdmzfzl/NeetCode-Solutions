"""
Problem: LeetCode 4 - Median of Two Sorted Arrays

Key Idea:
To find the median of two sorted arrays 'nums1' and 'nums2', we can perform a binary search on the smaller array. We partition both arrays into two parts such that the left half contains smaller elements and the right half contains larger elements. The median will be the average of the maximum element in the left half and the minimum element in the right half. We adjust the partition indices based on binary search, aiming to keep the same number of elements in both halves.

Time Complexity:
The time complexity of this solution is O(log(min(m, n))), where m and n are the lengths of 'nums1' and 'nums2'. The binary search reduces the search space by half in each step.

Space Complexity:
The space complexity is O(1), as no extra space is used other than a few variables to keep track of indices and values.
"""


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        m, n = len(nums1), len(nums2)
        low, high = 0, m

        while low <= high:
            partition1 = (low + high) // 2
            partition2 = (m + n + 1) // 2 - partition1

            maxLeft1 = float("-inf") if partition1 == 0 else nums1[partition1 - 1]
            minRight1 = float("inf") if partition1 == m else nums1[partition1]

            maxLeft2 = float("-inf") if partition2 == 0 else nums2[partition2 - 1]
            minRight2 = float("inf") if partition2 == n else nums2[partition2]

            if maxLeft1 <= minRight2 and maxLeft2 <= minRight1:
                if (m + n) % 2 == 0:
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2
                else:
                    return max(maxLeft1, maxLeft2)
            elif maxLeft1 > minRight2:
                high = partition1 - 1
            else:
                low = partition1 + 1

        raise ValueError("Input arrays are not sorted.")
