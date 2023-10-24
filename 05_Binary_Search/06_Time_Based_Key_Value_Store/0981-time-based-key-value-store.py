"""
Problem: LeetCode 981 - Time Based Key-Value Store

Key Idea:
To implement a time-based key-value store, we can use a dictionary to store the values associated with each key. For each key, we store a list of tuples representing the timestamp and the corresponding value. When querying a key at a specific timestamp, we perform binary search on the list of timestamps associated with that key to find the largest timestamp less than or equal to the given timestamp.

Time Complexity:
1. The time complexity of the 'set' operation is O(1), as it involves adding a new value to the dictionary.
2. The time complexity of the 'get' operation is O(log n), where n is the number of timestamps associated with the queried key. This is due to the binary search performed to find the appropriate value.

Space Complexity:
The space complexity is O(n), where n is the number of keys. We need to store values and timestamps for each key in the dictionary.
"""


class TimeMap:
    def __init__(self):
        self.data = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.data[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        values = self.data[key]
        left, right = 0, len(values) - 1

        while left <= right:
            mid = left + (right - left) // 2
            if values[mid][0] == timestamp:
                return values[mid][1]
            elif values[mid][0] < timestamp:
                left = mid + 1
            else:
                right = mid - 1

        if right >= 0:
            return values[right][1]
        return ""
