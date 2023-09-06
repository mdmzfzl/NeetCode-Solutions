"""
Problem: LeetCode 621 - Task Scheduler

Key Idea:
To schedule tasks with maximum cooling time, we can use a greedy approach. We first count the frequency of each task and sort them in descending order. We then iterate through the tasks and use a cooldown counter to keep track of the remaining time until the next valid task can be scheduled. During each iteration, we schedule the task with the highest frequency that is not on cooldown. If there are no available tasks, we simply wait.

Time Complexity:
- Counting tasks: The time complexity of counting the frequency of each task is O(n), where n is the number of tasks.
- Sorting tasks: The time complexity of sorting the tasks is O(26 * log 26) = O(1), since there are at most 26 different tasks.
- Iterating through tasks: The time complexity of iterating through the tasks is O(n), where n is the number of tasks.

Space Complexity:
- The space complexity is O(26) = O(1), since there are at most 26 different tasks.
"""

import heapq
from collections import Counter


class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        task_counts = Counter(tasks)
        max_heap = [-count for count in task_counts.values()]
        heapq.heapify(max_heap)

        cooldown = 0
        while max_heap:
            temp = []
            for _ in range(n + 1):
                if max_heap:
                    temp.append(heapq.heappop(max_heap) + 1)

            for count in temp:
                if count < 0:
                    heapq.heappush(max_heap, count)

            if max_heap:
                cooldown += n + 1
            else:
                cooldown += len(temp)

        return cooldown
