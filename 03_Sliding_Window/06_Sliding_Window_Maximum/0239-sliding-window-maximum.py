"""
Problem: LeetCode 239 - Sliding Window Maximum

Key Idea:
To find the maximum sliding window of size 'k' in the input array 'nums', we can use a deque (double-ended queue). The deque will store the indices of elements in 'nums' such that the elements at these indices are in decreasing order. As we traverse the array 'nums', we add the current element to the deque, but before adding, we remove elements from the back of the deque that are smaller than the current element. This ensures that the front element of the deque will always be the maximum element in the window. At each step, we check if the front element's index is within the valid range of the current window. If it is not, we remove the front element from the deque. As we traverse the array, we can build the maximum sliding window using the elements stored in the deque.

Time Complexity:
The time complexity of this solution is O(n), where n is the number of elements in the input array 'nums'. We traverse the array once, and at each step, we perform constant-time operations for adding and removing elements from the deque.

Space Complexity:
The space complexity is O(k), where k is the size of the sliding window. The deque will store at most 'k' elements at any point during the traversal, representing the maximum window size.
"""

from collections import deque


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums or k <= 0:
            return []

        result = []
        window = deque()

        for i, num in enumerate(nums):
            while window and nums[window[-1]] < num:
                window.pop()

            window.append(i)

            if i - window[0] >= k:
                window.popleft()

            if i >= k - 1:
                result.append(nums[window[0]])

        return result
