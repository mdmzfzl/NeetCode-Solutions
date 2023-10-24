"""
Problem: LeetCode 121 - Merge k Sorted Lists

Key Idea:
To merge k sorted linked lists, we can use a min-heap (priority queue) to keep track of the smallest element from each list. We initially add the first element from each list to the heap. Then, in each iteration, we pop the smallest element from the heap and add it to the merged result. If the popped element has a next element in its original list, we add that next element to the heap. We continue this process until the heap is empty.

Time Complexity:
The time complexity of this solution is O(N log k), where N is the total number of elements in all k linked lists. The heap operations take logarithmic time, and we perform these operations for each element.

Space Complexity:
The space complexity is O(k), as the heap can store at most k elements at a time.
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

import heapq


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        min_heap = []
        for i, l in enumerate(lists):
            if l:
                heapq.heappush(min_heap, (l.val, i))

        dummy = ListNode()
        current = dummy

        while min_heap:
            val, idx = heapq.heappop(min_heap)
            current.next = ListNode(val)
            current = current.next
            if lists[idx].next:
                heapq.heappush(min_heap, (lists[idx].next.val, idx))
                lists[idx] = lists[idx].next

        return dummy.next
