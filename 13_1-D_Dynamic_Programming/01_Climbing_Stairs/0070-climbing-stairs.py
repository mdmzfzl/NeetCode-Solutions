"""
Problem: LeetCode 70 - Climbing Stairs

Key Idea:
To climb to the n-th stair, you have two options, 
1. You can climb from the (n-1)-th stair.
2. You can climb from the (n-2)-th stair.

So, the number of ways to reach the n-th stair is the sum of the number of ways to reach the (n-1)-th and (n-2)-th stairs. This forms a Fibonacci sequence where f(n) = f(n-1) + f(n-2).

Time Complexity:
The time complexity is O(n) because we iterate from 1 to n to calculate the number of ways for each stair.

Space Complexity:
The space complexity is O(1) because we only need two variables to keep track of the previous two results and a temporary variable to calculate the current result.
"""


class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n

        prev1 = 1  # Number of ways to reach the 1st stair
        prev2 = 2  # Number of ways to reach the 2nd stair

        for i in range(3, n + 1):
            current = prev1 + prev2
            prev1, prev2 = prev2, current  # Update for the next iteration

        return prev2  # Number of ways to reach the n-th stair
