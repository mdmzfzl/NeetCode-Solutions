"""
Problem: LeetCode 146 - LRU Cache

Key Idea:
To implement an LRU (Least Recently Used) cache, we can use a combination of a dictionary (to store key-value pairs) and a doubly linked list (to maintain the order of usage). The dictionary allows for quick access to values, and the doubly linked list helps in efficient removal and addition of elements. When a key is accessed or a new key is added, we update its position in the linked list. When the cache is full, we remove the least recently used item from the tail of the linked list.

Time Complexity:
1. The 'get' operation takes O(1) time, as dictionary access is constant time.
2. The 'put' operation takes O(1) time, as dictionary insertion and removal are constant time.

Space Complexity:
The space complexity is O(capacity), as we store key-value pairs in the dictionary and maintain a doubly linked list for the same number of elements.
"""


class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}
        self.order = DoublyLinkedList()

    def get(self, key: int) -> int:
        if key in self.cache:
            self.order.move_to_front(key)
            return self.cache[key]
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache[key] = value
            self.order.move_to_front(key)
        else:
            if len(self.cache) >= self.capacity:
                removed_key = self.order.remove_last()
                del self.cache[removed_key]
            self.cache[key] = value
            self.order.add_to_front(key)


class DoublyLinkedList:
    def __init__(self):
        self.head = ListNode()
        self.tail = ListNode()
        self.head.next = self.tail
        self.tail.prev = self.head
        self.nodes = {}

    def add_to_front(self, key):
        node = ListNode(key)
        node.next = self.head.next
        node.prev = self.head
        self.head.next.prev = node
        self.head.next = node
        self.nodes[key] = node

    def move_to_front(self, key):
        node = self.nodes[key]
        node.prev.next = node.next
        node.next.prev = node.prev
        self.add_to_front(key)

    def remove_last(self):
        node = self.tail.prev
        node.prev.next = self.tail
        self.tail.prev = node.prev
        del self.nodes[node.key]
        return node.key


class ListNode:
    def __init__(self, key=None):
        self.key = key
        self.prev = None
        self.next = None


"""
from collections import OrderedDict

class LRUCache:

    def __init__(self, capacity: int):
        self.cache = OrderedDict()
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key in self.cache:
            self.cache.move_to_end(key)
            return self.cache[key]
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.move_to_end(key)
        elif self.capacity <= 0:
            _ = self.cache.popitem(False)
        else:
            self.capacity = max(0, self.capacity - 1)
        self.cache[key] = value
"""

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
