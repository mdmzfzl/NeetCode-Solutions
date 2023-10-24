"""
Problem: LeetCode 128 -Longest Consecutive Sequence

Key Idea:
To find the longest consecutive subsequence, we first create a set of all the elements in the input array 'nums'. Then, for each element in the array, we check if it is the starting element of a consecutive subsequence. To do this, we check if the element before the current element (i.e., nums[i] - 1) exists in the set. If it doesn't, it means nums[i] is the starting element of a consecutive subsequence. From here, we keep incrementing the current element until the consecutive subsequence ends (i.e., the next element does not exist in the set). We keep track of the length of the consecutive subsequence and update the maximum length found so far.

Time Complexity:
The time complexity of this solution is O(n), where n is the number of elements in the input array 'nums'. The set operations (addition and lookup) take O(1) time on average, and we perform these operations for each element once.

Space Complexity:
The space complexity is O(n), where n is the number of elements in the input array 'nums'. In the worst case, the set will store all elements from the input array if they are all distinct.
"""


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        num_set = set(nums)
        max_length = 0

        for num in num_set:
            if num - 1 not in num_set:
                current_num = num
                current_length = 1

                while current_num + 1 in num_set:
                    current_num += 1
                    current_length += 1

                max_length = max(max_length, current_length)

        return max_length
