"""
Problem: LeetCode 739 - Daily Temperatures

Key Idea:
To find the daily temperatures that are warmer in the input array 'temperatures', we can use a stack. We iterate through the temperatures in reverse order, and for each temperature, we pop elements from the stack while they are smaller than the current temperature. This indicates that the current temperature is the first warmer temperature for the popped elements. We keep track of the indices of these warmer temperatures in the result array. Then, we push the current temperature's index onto the stack. At the end, the result array will contain the number of days until the next warmer temperature for each day.

Time Complexity:
The time complexity of this solution is O(n), where n is the number of elements in the input array 'temperatures'. We iterate through the array once, and each element is pushed onto and popped from the stack at most once.

Space Complexity:
The space complexity is O(n), where n is the number of elements in the input array 'temperatures'. In the worst case, all temperatures could be strictly increasing, leading to all elements being pushed onto the stack.
"""


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        result = [0] * len(temperatures)

        for i in range(len(temperatures) - 1, -1, -1):
            while stack and temperatures[i] >= temperatures[stack[-1]]:
                stack.pop()
            if stack:
                result[i] = stack[-1] - i
            stack.append(i)

        return result
