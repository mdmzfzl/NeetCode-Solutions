"""
Problem: LeetCode 15 - 3Sum

Key Idea:
To find all unique triplets that sum to zero, we can use a three-pointer approach. First, we sort the input array 'nums' in non-decreasing order. Then, we iterate through the array with a fixed first element (i). For each fixed first element, we use two pointers (left and right) to find the other two elements that sum to the negation of the fixed first element. As the array is sorted, we can move these two pointers towards each other to efficiently find all possible triplets.

Time Complexity:
The time complexity of this solution is O(n^2), where n is the number of elements in the input array 'nums'. Sorting the array takes O(nlogn) time, and the two-pointer approach iterates through the array once, performing a linear search for each element.

Space Complexity:
The space complexity is O(1) since we are not using any additional data structures that depend on the input size. We only use a constant amount of extra space for the three pointers and other variables.
"""


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result = []
        n = len(nums)

        for i in range(n - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            left, right = i + 1, n - 1

            while left < right:
                current_sum = nums[i] + nums[left] + nums[right]

                if current_sum == 0:
                    result.append([nums[i], nums[left], nums[right]])

                    # Skip duplicates
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1

                    left += 1
                    right -= 1
                elif current_sum < 0:
                    left += 1
                else:
                    right -= 1

        return result
