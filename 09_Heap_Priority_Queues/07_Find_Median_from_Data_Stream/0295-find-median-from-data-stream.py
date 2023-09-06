"""
Problem: LeetCode 295 - Find Median from Data Stream

Key Idea:
To find the median from a stream of data, we can use two heaps: a max-heap to store the lower half of the data and a min-heap to store the upper half of the data. The max-heap will contain the smaller elements, and the min-heap will contain the larger elements. To maintain the balance of the heaps, we ensure that the size difference between the two heaps is at most 1. The median will be the average of the top elements of both heaps if the total number of elements is even, or the top element of the larger heap if the total number of elements is odd.

Time Complexity:
- Adding an element: The time complexity of adding an element to the heaps is O(log n), where n is the number of elements.
- Finding the median: The time complexity of finding the median is O(1), as it involves accessing the top elements of the heaps.

Space Complexity:
- The space complexity is O(n), where n is the number of elements in the data stream.
"""

import heapq


class MedianFinder:
    def __init__(self):
        self.min_heap = []  # To store larger elements
        self.max_heap = []  # To store smaller elements

    def addNum(self, num: int) -> None:
        if not self.max_heap or num <= -self.max_heap[0]:
            heapq.heappush(self.max_heap, -num)
        else:
            heapq.heappush(self.min_heap, num)

        # Balance the heaps
        if len(self.max_heap) > len(self.min_heap) + 1:
            heapq.heappush(self.min_heap, -heapq.heappop(self.max_heap))
        elif len(self.min_heap) > len(self.max_heap):
            heapq.heappush(self.max_heap, -heapq.heappop(self.min_heap))

    def findMedian(self) -> float:
        if len(self.max_heap) == len(self.min_heap):
            return (-self.max_heap[0] + self.min_heap[0]) / 2
        else:
            return -self.max_heap[0]
