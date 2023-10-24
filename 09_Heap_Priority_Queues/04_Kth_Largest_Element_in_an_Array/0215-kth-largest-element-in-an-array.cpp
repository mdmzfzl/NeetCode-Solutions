/*
Problem: LeetCode 215 - Kth Largest Element in an Array

Description:
Given an integer array `nums` and an integer `k`, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.

Intuition:
The code uses the Quickselect algorithm to find the kth largest element in the array efficiently.
Quickselect is a variation of the QuickSort algorithm and works by partitioning the array based on a chosen pivot element.
Instead of sorting both sides of the partition like in QuickSort, Quickselect only focuses on the side of the partition that contains the desired kth largest element.

Approach:
1. The code implements the Quickselect algorithm to efficiently find the kth largest element.
   - Quickselect is a variation of the QuickSort algorithm that focuses on the desired kth largest element during partitioning.

2. The `quickselect` function is a helper function that takes the input array `nums`, start index `l`, end index `r`, and the value of `k` as parameters.
   - It returns the kth largest element in the array by recursively partitioning the array.

3. Base case:
   - If the start index `l` is greater than or equal to the end index `r`, it means we have found the kth largest element, so we return the element at index `l`.

4. Partitioning:
   - The code chooses the pivot element as `nums[l + r >> 1]`, which is the element at the middle index between `l` and `r`.
   - It initializes two pointers, `i` and `j`, where `i` starts from `l - 1` and `j` starts from `r + 1`.
   - The code enters a loop where it increments `i` until it finds an element greater than the pivot and decrements `j` until it finds an element smaller than the pivot.
   - If `i` is less than `j`, it means there are elements on the wrong side of the partition, so it swaps `nums[i]` and `nums[j]`.

5. After the loop:
   - The code calculates the size of the smaller partition as `sl = j - l + 1`.

6. Recursion:
   - If `k` is less than or equal to `sl`, it means the desired element is in the smaller partition, so it recursively calls `quickselect` on that partition.
   - If `k` is greater than `sl`, it means the desired element is in the larger partition, so it recursively calls `quickselect` on that partition, adjusting `k` by subtracting `sl`.

7. The `findKthLargest` function is the main function that takes the input array `nums` and integer `k` as parameters.
   - It disables synchronization between C and C++ standard streams for faster I/O.
   - It returns the result of the `quickselect` function called with `nums`, 0 as the start index, `nums.size() - 1` as the end index, and `k`.

Time Complexity:
- On average, the Quickselect algorithm has a time complexity of O(n), where n is the number of elements in the input array.
- However, in the worst case, Quickselect can have a time complexity of O(n^2) if the pivot selection is unbalanced.
- Overall, the average time complexity of Quickselect is O(n), making it an efficient algorithm for finding the kth largest element.

Space Complexity:
- The space complexity is O(log n) for the recursive call stack of the `quickselect` function, where n is the number of elements in the input array.
- In addition to the input array, the algorithm uses a constant amount of extra space.
- Therefore, the overall space complexity is O(log n).
*/

class Solution {
  public:
    int quickselect(vector<int> &nums, int left, int right, int k) {
        // Base case: if the left and right indices are the same, return the element at that index
        if (left >= right) {
            return nums[left];
        }

        // Choose a pivot element
        int pivot = nums[left + (right - left) / 2];
        // Initialize two pointers, one from the left and one from the right
        int i = left - 1;
        int j = right + 1;

        // Partition the array around the pivot
        while (i < j) {
            // Find the first element greater than the pivot from the left side
            while (nums[++i] > pivot);

            // Find the first element smaller than the pivot from the right side
            while (nums[--j] < pivot);

            // Swap the elements if the pointers haven't crossed each other
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }

        // Calculate the size of the smaller partition
        int smallerPartitionSize = j - left + 1;

        // If the desired element is in the smaller partition, recursively call quickselect on that partition
        if (k <= smallerPartitionSize) {
            return quickselect(nums, left, j, k);
        }

        // If the desired element is in the larger partition, recursively call quickselect on that partition
        return quickselect(nums, j + 1, right, k - smallerPartitionSize);
    }

    int findKthLargest(vector<int> &nums, int k) {
        // Disable synchronization between C and C++ standard streams for faster I/O
        cin.tie(0);
        ios::sync_with_stdio(false);
        // Call the quickselect algorithm to find the kth largest element
        return quickselect(nums, 0, nums.size() - 1, k);
    }
};