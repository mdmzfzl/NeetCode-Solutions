/*
Problem: LeetCode 973 - K Closest Points to Origin

Key Idea:
The key idea is to use a min-heap (priority queue) to efficiently find the k closest points to the origin (0, 0) based on their Euclidean distances.

Approach:
1. Create a min-heap (priority queue) to store points based on their squared Euclidean distances.
2. Iterate through the points:
   - Calculate the squared Euclidean distance of each point to the origin: `x^2 + y^2`.
   - Push the point and its squared distance as a tuple into the min-heap.
3. If the min-heap size exceeds `k`, pop the point with the largest squared distance. This step ensures that the min-heap always contains the `k` closest points.
4. After processing all points, the min-heap will contain the `k` closest points to the origin.
5. Extract the points from the min-heap in the order they appear. Since it's a min-heap, they will come out in ascending order of distance.
6. Return the `k` closest points.

Time Complexity:
- Heap Insertion and Extraction: O(log k) per operation, where k is the value of 'K'.
- We perform this operation for each of the 'N' points.
- Overall time complexity is O(N log K).

Space Complexity:
O(K), as the max-heap can contain at most K points.
*/

use std::cmp::Ordering;
use std::collections::BinaryHeap;

impl Solution {
    pub fn k_closest(points: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let k = k as usize;
        let mut min_heap = BinaryHeap::with_capacity(k + 1);

        for point in &points {
            let p = Point::from_vec(point);
            min_heap.push(p);

            if min_heap.len() > k {
                min_heap.pop();
            }
        }

        min_heap
            .into_sorted_vec()
            .into_iter()
            .map(Point::into_vec)
            .collect()
    }
}

#[derive(Eq, PartialEq)]
struct Point {
    x: i32,
    y: i32,
}

impl Point {
    fn distance_squared(&self) -> i32 {
        self.x * self.x + self.y * self.y
    }

    fn from_vec(v: &Vec<i32>) -> Self {
        Point { x: v[0], y: v[1] }
    }

    fn into_vec(self) -> Vec<i32> {
        vec![self.x, self.y]
    }
}

impl Ord for Point {
    fn cmp(&self, other: &Self) -> Ordering {
        self.distance_squared().cmp(&other.distance_squared())
    }
}

impl PartialOrd for Point {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

/*
// Quickselect method

impl Solution {
    pub fn k_closest(mut points: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let k = k as usize;
        let (mut left, mut right) = (0, points.len() - 1);

        while left <= right {
            let pivot_index = partition(&mut points, left, right);

            if pivot_index < k {
                left = pivot_index + 1;
            } else if pivot_index > k {
                right = pivot_index - 1;
            } else {
                break;
            }
        }

        points[..k].to_vec()
    }
}

const X: usize = 0;
const Y: usize = 1;

fn squared_distance(point: &Vec<i32>) -> i32 {
    point[X].pow(2) + point[Y].pow(2)
}

fn partition(points: &mut Vec<Vec<i32>>, mut left: usize, mut right: usize) -> usize {
    // Use Hoare's partition scheme.
    let pivot_index = left;
    while left < right {
        while left < right && squared_distance(&points[pivot_index]) <= squared_distance(&points[right]) {
            right -= 1;
        }
        while left < right && squared_distance(&points[left]) <= squared_distance(&points[pivot_index]) {
            left += 1;
        }
        points.swap(left, right);
    }
    points.swap(left, pivot_index);
    left
}
*/

/*
// Sorting method

impl Solution {
    fn squared_distance_to_zero(point: &Vec<i32>) -> i32 {
        point[0].pow(2) + point[1].pow(2)
    }

    pub fn k_closest(mut points: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        points.sort_by_key(|point| Solution::squared_distance_to_zero(point));
        points.into_iter().take(k as usize).collect()
    }
}
*/
