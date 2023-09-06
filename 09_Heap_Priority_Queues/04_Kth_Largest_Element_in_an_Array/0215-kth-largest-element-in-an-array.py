"""
Problem: LeetCode 215 - Kth Largest Element in an Array

Key Idea:
To find the kth largest element in an array, we can use a min-heap (priority queue) with a maximum size of k. As we iterate through the array, we push elements into the min-heap. If the size of the heap exceeds k, we remove the smallest element. The top element of the min-heap will be the kth largest element.

Time Complexity:
- Building the min-heap: The time complexity of building the min-heap is O(k), where k is the maximum size of the heap.
- Adding elements: The time complexity of adding an element to the min-heap is O(n * log k), where n is the length of the array and k is the maximum size of the heap.

Space Complexity:
- The space complexity is O(k), where k is the maximum size of the min-heap.
"""

import heapq


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        min_heap = []

        for num in nums:
            heapq.heappush(min_heap, num)
            if len(min_heap) > k:
                heapq.heappop(min_heap)

        return min_heap[0]
