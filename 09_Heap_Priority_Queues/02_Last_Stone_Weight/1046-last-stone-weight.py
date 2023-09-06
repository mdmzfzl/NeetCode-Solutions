"""
Problem: LeetCode 1046 - Last Stone Weight

Key Idea:
To simulate the process of smashing stones, we can use a max-heap (priority queue) to keep track of the stone weights. At each step, we pop the two largest stones from the heap, smash them together, and push the resulting weight back into the heap. We repeat this process until there is only one stone left in the heap, which will be the last stone weight.

Time Complexity:
- Building the max-heap: The time complexity of building the max-heap is O(n), where n is the number of stones.
- Popping and pushing elements: The time complexity of each pop and push operation is O(log n), where n is the number of stones. We perform these operations until there is only one stone left.

Space Complexity:
- The space complexity is O(n), where n is the number of stones, due to the space required to store the max-heap.
"""

import heapq


class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        max_heap = [-stone for stone in stones]  # Use negative values for max-heap

        heapq.heapify(max_heap)

        while len(max_heap) > 1:
            x = -heapq.heappop(max_heap)  # Extract the largest stone
            y = -heapq.heappop(max_heap)  # Extract the second largest stone

            if x != y:
                heapq.heappush(max_heap, -(x - y))  # Push the remaining weight

        return -max_heap[0] if max_heap else 0
