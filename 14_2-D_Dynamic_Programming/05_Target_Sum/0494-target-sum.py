"""
Problem: LeetCode 494 - Target Sum

Key Idea:
The key idea is to use dynamic programming to count the number of ways to reach a certain sum by assigning either a positive or negative sign to each element in the input array.

Time Complexity:
The time complexity is O(n * sum), where 'n' is the number of elements in the input array 'nums' and 'sum' is the sum of all elements in 'nums'. We iterate through 'n' elements and, for each element, iterate through 'sum' values.

Space Complexity:
The space complexity is O(sum) because we use a 1D array 'dp' of size 'sum + 1' to store the number of ways to reach each sum from 0 to 'sum'.
"""


class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        # Calculate the sum of all elements in the input array 'nums'.
        total_sum = sum(nums)

        # If the total sum is less than the target sum 'S', it's not possible to reach 'S'.
        if (total_sum + S) % 2 != 0 or total_sum < abs(S):
            return 0

        # Calculate the target sum for positive signs. (total_sum + S) / 2
        target = (total_sum + S) // 2

        # Initialize a 1D array 'dp' to store the number of ways to reach each sum from 0 to 'target'.
        dp = [0] * (target + 1)

        # There is one way to reach a sum of 0 (by not selecting any element).
        dp[0] = 1

        # Iterate through each element in the input array 'nums'.
        for num in nums:
            # Update the 'dp' array for each sum from 'target' to 'num'.
            for i in range(target, num - 1, -1):
                dp[i] += dp[i - num]

        # The 'dp[target]' contains the number of ways to reach the target sum 'S'.
        return dp[target]
