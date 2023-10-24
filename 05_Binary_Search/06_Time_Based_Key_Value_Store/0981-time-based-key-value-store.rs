/*
Problem: LeetCode 981 - Time Based Key-Value Store

Key Idea:
We can use a HashMap to store the key-value pairs and their timestamps. To efficiently retrieve values based on timestamps, we can use binary search.

Approach:
1. Create a HashMap where the keys are strings (the data keys) and the values are vectors of pairs (timestamp, value).
   - HashMap<String, Vec<(i32, String)>> for storing key-value pairs.
2. Implement two methods, `set` and `get`.
   - `set` method:
     - Insert the key-value pair with the given timestamp into the HashMap.
     - Since the input timestamps are monotonically increasing, we can insert new pairs directly into the vector.
   - `get` method:
     - Retrieve the vector associated with the given key.
     - Perform a binary search within the vector to find the largest timestamp that is less than or equal to the input timestamp.
     - Return the corresponding value if found, or an empty string otherwise.
3. The binary search for each `get` operation takes O(log n) time, where n is the number of timestamps associated with the key.
   - The space complexity is O(N) for storing all key-value pairs and their timestamps.

Time Complexity:
- O(log n) for each `get` operation.
- O(1) for each `set` operation.

Space Complexity:
- O(N) where N is the total number of key-value pairs.
*/

use std::collections::HashMap;

struct TimeMap {
    store: HashMap<String, Vec<(i32, String)>>,
}

impl TimeMap {
    fn new() -> Self {
        TimeMap {
            store: HashMap::new(),
        }
    }

    fn set(&mut self, key: String, value: String, timestamp: i32) {
        self.store
            .entry(key)
            .or_insert_with(Vec::new)
            .push((timestamp, value));
    }

    fn get(&self, key: String, timestamp: i32) -> String {
        if let Some(values) = self.store.get(&key) {
            let mut left = 0;
            let mut right = values.len() as i32 - 1;

            while left <= right {
                let mid = left + (right - left) / 2;
                let (ts, val) = &values[mid as usize];

                if *ts == timestamp {
                    return val.clone();
                } else if *ts < timestamp {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            if right >= 0 {
                return values[right as usize].1.clone();
            }
        }

        String::new()
    }
}
