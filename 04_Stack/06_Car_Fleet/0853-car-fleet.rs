/*
Problem: LeetCode 853 - Car Fleet

Key Idea:
The key idea is to simulate the movement of cars and calculate the time it takes for each car to reach the target.

Approach:
1. Create a vector `cars` of pairs, where each pair represents a car with its position and speed.
2. Sort the `cars` vector by the position of the cars, with the car closest to the target at the end.
3. Initialize a variable `time` to 0, which represents the current time.
4. Initialize a variable `count` to 0, which represents the number of car fleets.
5. Iterate through the `cars` vector from the end to the beginning (from the car closest to the target to the farthest):
   - Calculate the time it takes for the current car to reach the target using the formula: `time = (target - position) as f64 / speed as f64`.
   - If the calculated time is greater than the current `time`, it means a new car fleet is formed. Increment `count` and update `time` to the calculated time.
6. Return the value of `count`, which represents the number of car fleets.

Time Complexity:
O(n log n), where n is the number of cars. Sorting the `cars` vector takes O(n log n) time.

Space Complexity:
O(n), as we store the cars in a vector.
*/

impl Solution {
    pub fn car_fleet(target: i32, position: Vec<i32>, speed: Vec<i32>) -> i32 {
        let mut cars: Vec<(i32, i32)> = position.into_iter().zip(speed.into_iter()).collect();
        cars.sort_by_key(|&(pos, _)| -pos); // Sort by position in descending order.

        let mut time = 0.0;
        let mut count = 0;

        for (pos, spd) in cars {
            let curr_time = (target - pos) as f64 / spd as f64;
            if curr_time > time {
                count += 1;
                time = curr_time;
            }
        }

        count
    }
}
