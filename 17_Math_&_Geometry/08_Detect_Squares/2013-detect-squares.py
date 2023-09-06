"""
Problem: LeetCode 2013 - Detect Squares

Key Idea:
The key idea is to group points by their x-coordinates and then use these groups to efficiently find potential square corners. 

Time Complexity:
- Adding a point: O(1)
- Counting squares: O(K) in the worst case

Space Complexity:
- O(N) due to storing up to N points
"""

from collections import defaultdict
from typing import List


class DetectSquares:
    def __init__(self):
        self.points = defaultdict(lambda: defaultdict(int))

    def add(self, point: List[int]) -> None:
        x, y = point
        self.points[x][y] += 1

    def count(self, point: List[int]) -> int:
        x, y = point
        count = 0

        for y2 in self.points[x]:
            if y2 != y:
                side_length = abs(y2 - y)

                for x2 in (x + side_length, x - side_length):
                    if x2 in self.points and y in self.points[x2]:
                        count += (
                            self.points[x2][y]
                            * self.points[x2][y2]
                            * self.points[x][y2]
                        )

        return count


# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)
