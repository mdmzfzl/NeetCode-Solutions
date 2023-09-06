"""
Problem: LeetCode 134 - Gas Station

Key Idea:
We can solve this problem using a greedy approach. The idea is to keep track of the total gas available and the current gas needed as we iterate through the stations. If the current gas becomes negative, we reset the starting station to the next station and reset the current gas needed. At the end, if the total gas available is greater than or equal to the current gas needed, then the starting station is a valid solution.

Time Complexity:
- The time complexity of this approach is O(n), where n is the length of the input arrays.

Space Complexity:
- The space complexity is O(1), as we only use a constant amount of additional space for variables.
"""


class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        total_gas = 0
        current_gas = 0
        start_station = 0

        for i in range(len(gas)):
            total_gas += gas[i] - cost[i]
            current_gas += gas[i] - cost[i]

            if current_gas < 0:
                start_station = i + 1
                current_gas = 0

        return start_station if total_gas >= 0 else -1
