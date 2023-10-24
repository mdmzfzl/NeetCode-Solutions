"""
Problem: LeetCode 1 - Two Sum

Key Idea:
The key idea to solve this problem efficiently is by using a hash map (dictionary in Python) to keep track of the elements we have traversed so far. For each element in the input list, we calculate the difference between the target and the current element. If this difference exists in the hash map, then we have found the pair that sums to the target, and we return their indices. Otherwise, we add the current element to the hash map and continue with the next element.

Time Complexity:
The time complexity of this solution is O(n), where n is the size of the input array 'nums'. In the worst case, we might need to traverse the entire array once to find the pair.

Space Complexity:
The space complexity is O(n), as the hash map can potentially store all elements of the input array 'nums' if they are all unique. In the best case, where the target sum is achieved with the first two elements, the space complexity would be O(1). However, in the worst case, if all elements are distinct, the hash map will store all elements, leading to O(n) space complexity.
"""


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        prevMap = {}  # val -> index

        for i, n in enumerate(nums):
            diff = target - n
            if diff in prevMap:
                return [prevMap[diff], i]
            prevMap[n] = i
