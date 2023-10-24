"""
Problem: LeetCode 84 - Largest Rectangle in Histogram

Key Idea:
To find the largest rectangle area in the input histogram represented by the list 'heights', we can use a stack to keep track of increasing bar heights' indices. We iterate through the heights and push the current index onto the stack if the current height is greater than or equal to the height at the top of the stack. If the current height is smaller, it indicates that the previous bars cannot form a larger rectangle, so we pop indices from the stack and calculate the area for each popped bar. The width of the rectangle is determined by the difference between the current index and the index at the top of the stack. The height of the rectangle is the height at the popped index. We keep track of the maximum area seen so far.

Time Complexity:
The time complexity of this solution is O(n), where n is the number of elements in the input list 'heights'. We iterate through the heights once, and each element is pushed onto and popped from the stack at most once.

Space Complexity:
The space complexity is O(n), where n is the number of elements in the input list 'heights'. In the worst case, all elements could be pushed onto the stack.
"""


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        max_area = 0

        for i in range(len(heights)):
            while stack and heights[i] < heights[stack[-1]]:
                height = heights[stack.pop()]
                width = i if not stack else i - stack[-1] - 1
                max_area = max(max_area, height * width)
            stack.append(i)

        while stack:
            height = heights[stack.pop()]
            width = len(heights) if not stack else len(heights) - stack[-1] - 1
            max_area = max(max_area, height * width)

        return max_area
