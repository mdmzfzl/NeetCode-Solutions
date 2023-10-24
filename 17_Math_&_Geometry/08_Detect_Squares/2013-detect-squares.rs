/*
Problem: LeetCode 2013 - Detect Squares

Key Idea:
A rectangle requires two pairs of points to share one common point and have equal distances along both axes.

Approach:
1. Create a `DetectSquares` struct to maintain a `points_count` HashMap, which counts the occurrences of each point.
2. In the `add` method, update the count for the given point in the `points_count` HashMap.
3. In the `count` method, iterate through the points in the `points_count` HashMap.
4. For each point `key`, check if it can form a rectangle with the input point `point`. If so, calculate the count of two additional points to complete the rectangle.
5. Multiply these three counts (including `val`, which represents the count of `key`) to get the total count of rectangles formed with `point` as one corner.
6. Add this count to the result and continue iterating.
7. Finally, return the result, which represents the total count of rectangles formed by the given points.

Time Complexity:
O(n), due to count() method.

Space Complexity:
O(n), for using a hashmap.
*/

use std::collections::HashMap;

struct DetectSquares {
    points_count: HashMap<Vec<i32>, i32>,
}

impl DetectSquares {
    fn new() -> Self {
        DetectSquares {
            points_count: HashMap::new(),
        }
    }

    fn add(&mut self, point: Vec<i32>) {
        self.points_count
            .entry(point)
            .and_modify(|count| *count += 1)
            .or_insert(1);
    }

    fn count(&self, point: Vec<i32>) -> i32 {
        let mut result: i32 = 0;

        for (key, val) in self.points_count.iter() {
            if key[0] != point[0]
                && key[1] != point[1]
                && (point[0] - key[0]).abs() == (point[1] - key[1]).abs()
            {
                let count_a = match self.points_count.get(&*vec![key[0], point[1]]) {
                    Some(&count) => count,
                    None => 0,
                };

                let count_b = match self.points_count.get(&*vec![point[0], key[1]]) {
                    Some(&count) => count,
                    None => 0,
                };

                result += val * count_a * count_b;
            }
        }

        result
    }
}
