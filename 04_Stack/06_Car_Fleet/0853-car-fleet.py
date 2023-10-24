"""
Problem: LeetCode 853 - car Fleet

Key Idea:
To determine the number of car fleets that can reach the target destination in the input arrays 'target' and 'position', we can simulate the car movements and calculate the time it takes for each car to reach the target. We can then sort the cars based on their positions and iterate through them. For each car, we calculate its time to reach the target and compare it with the previous car. If the time for the current car is greater, it means the previous car cannot catch up to it, so we consider the current car as a new fleet. Otherwise, the previous car can catch up to the current car, so they form a fleet together.

Time Complexity:
The time complexity of this solution is O(n log n), where n is the number of cars. The dominating factor is the sorting step, which takes O(n log n) time. The subsequent iteration through the sorted cars takes linear time.

Space Complexity:
The space complexity is O(n), where n is the number of cars. We need additional space to store the time-to-reach values for each car.
"""


class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = sorted(zip(position, speed), reverse=True)
        fleets = 0
        prev_time = -1.0

        for pos, spd in cars:
            time = (target - pos) / spd
            if time > prev_time:
                fleets += 1
                prev_time = time

        return fleets
