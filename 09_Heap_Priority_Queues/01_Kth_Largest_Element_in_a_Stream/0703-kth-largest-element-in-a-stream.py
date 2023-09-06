"""
Problem: LeetCode 703 - Kth Largest Element in a Stream

Key Idea:
To find the kth largest element in a stream of integers, we can use a min-heap (priority queue) with a maximum size of k. As new elements arrive, we add them to the min-heap. If the size of the heap exceeds k, we remove the smallest element. The top element of the min-heap will be the kth largest element.

Time Complexity:
- Adding an element: The time complexity of adding an element to the min-heap is O(log k), where k is the maximum size of the heap.
- Retrieving the kth largest element: The time complexity of retrieving the kth largest element (the top of the heap) is O(1).

Space Complexity:
- The space complexity is O(k), where k is the maximum size of the min-heap.
"""

import heapq


class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.min_heap = []
        self.k = k

        for num in nums:
            self.add(num)

    def add(self, val: int) -> int:
        heapq.heappush(self.min_heap, val)

        if len(self.min_heap) > self.k:
            heapq.heappop(self.min_heap)

        return self.min_heap[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
