"""
Problem: LeetCode 42 - Trapping Rain Water

Key Idea:
To find the amount of trapped rainwater in the given elevation histogram represented by the input array 'height', we can use a two-pointer approach. We initialize two pointers, one at the beginning of the array (left) and the other at the end of the array (right). We also initialize two variables to keep track of the maximum left height and maximum right height seen so far. While the left pointer is less than the right pointer, we compare the height at the left and right pointers. If the height at the left pointer is less than or equal to the height at the right pointer, it means we can trap water between the left pointer and the maximum left height. Otherwise, we can trap water between the right pointer and the maximum right height. At each step, we update the trapped water amount and move the pointers and update the maximum heights accordingly.

Time Complexity:
The time complexity of this solution is O(n), where n is the number of elements in the input array 'height'. The two-pointer approach iterates through the array once, and at each step, we move at least one of the pointers, so we do not revisit any element.

Space Complexity:
The space complexity is O(1) since we are not using any additional data structures that depend on the input size. We only use a constant amount of extra space for the two pointers and other variables.
"""


class Solution:
    def trap(self, height: List[int]) -> int:
        left, right = 0, len(height) - 1
        max_left, max_right = 0, 0
        trapped_water = 0

        while left < right:
            if height[left] <= height[right]:
                if height[left] >= max_left:
                    max_left = height[left]
                else:
                    trapped_water += max_left - height[left]
                left += 1
            else:
                if height[right] >= max_right:
                    max_right = height[right]
                else:
                    trapped_water += max_right - height[right]
                right -= 1

        return trapped_water
