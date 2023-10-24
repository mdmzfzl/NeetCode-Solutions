/*
Problem: LeetCode 146 - LRU Cache

Key Idea:
The key idea is to implement an LRU (Least Recently Used) cache, which efficiently stores and manages a fixed number of items while removing the least recently used item when the capacity is exceeded.

Approach:
1. Use a combination of a HashMap and a doubly linked list to implement the LRU cache.
2. The HashMap stores the key-value pairs, where the key is used for quick access to the corresponding node in the linked list.
3. The doubly linked list represents the order of usage, with the most recently used item at the front (head) and the least recently used item at the end (tail).
4. When an item is accessed (get or put operation), move it to the front of the linked list to mark it as the most recently used.
5. When the cache capacity is exceeded during a put operation, remove the least recently used item from both the HashMap and the linked list.
6. The doubly linked list is used to efficiently manage the order of usage by adjusting the pointers when items are accessed or removed.

Time Complexity:
- Get Operation: O(1) - Accessing a value in the HashMap is an O(1) operation.
- Put Operation: O(1) - Inserting or updating a value in the HashMap is an O(1) operation.
Overall, the operations are O(1) because the linked list operations (removing and adding nodes) are constant time.

Space Complexity:
O(capacity), where the space complexity is determined by the capacity of the LRU cache.
*/

use std::collections::{HashMap, HashSet, VecDeque};

struct LRUCache {
    deque: VecDeque<i32>,
    cache: HashMap<i32, i32>,
    capacity: usize,
    keys: HashSet<i32>,
}

impl LRUCache {
    fn new(capacity: i32) -> Self {
        Self {
            deque: VecDeque::new(),
            cache: HashMap::new(),
            capacity: capacity as usize,
            keys: HashSet::new(),
        }
    }

    fn get(&mut self, key: i32) -> i32 {
        if self.keys.contains(&key) {
            let index = self.deque.iter().position(|&x| x == key).unwrap();
            self.deque.remove(index);
            self.deque.push_front(key);
            *self.cache.get(&key).unwrap()
        } else {
            -1
        }
    }

    fn put(&mut self, key: i32, value: i32) {
        if self.keys.contains(&key) {
            let index = self.deque.iter().position(|&x| x == key).unwrap();
            self.deque.remove(index);
            self.deque.push_front(key);
            self.cache.insert(key, value);
        } else {
            if self.cache.len() == self.capacity {
                if let Some(last) = self.deque.pop_back() {
                    self.cache.remove(&last);
                    self.keys.remove(&last);
                }
            }
            self.cache.insert(key, value);
            self.deque.push_front(key);
            self.keys.insert(key);
        }
    }
}

/*
// Faster solution

use std::collections::{HashMap, VecDeque};

struct LRUCache {
    cache: HashMap<i32, (i32, u32)>,
    queue: VecDeque<(i32, u32)>,
    time: u32,
    capacity: usize,
}

impl LRUCache {
    fn new(capacity: i32) -> Self {
        let capacity = capacity as usize;
        Self {
            cache: HashMap::with_capacity(capacity),
            queue: VecDeque::new(),
            time: 0,
            capacity,
        }
    }

    fn get(&mut self, key: i32) -> i32 {
        match self.cache.get(&key) {
            None => -1,
            Some(&(value, _)) => {
                self.update(key, value);
                value
            }
        }
    }

    fn put(&mut self, key: i32, value: i32) {
        if !self.cache.contains_key(&key) && self.cache.len() == self.capacity {
            let (key, _) = self.queue.pop_front().unwrap();
            self.cache.remove(&key);
        }
        self.update(key, value);
    }

    fn update(&mut self, key: i32, value: i32) {
        self.time = self.time.wrapping_add(1);
        self.cache.insert(key, (value, self.time));
        self.queue.push_back((key, self.time));
        loop {
            if let Some(&(key, time1)) = self.queue.front() {
                if let Some(&(_, time2)) = self.cache.get(&key) {
                    if time1 == time2 {
                        break;
                    }
                }
            }
            self.queue.pop_front();
        }
    }
}
*/
