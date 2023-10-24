/*
Problem: LeetCode 134 - Gas Station

Key Idea:
The key idea is to determine if there exists a starting gas station such that you can complete a circular tour of all gas stations.

Approach:
1. Initialize two variables: 'total_gas' to track the total gas available and 'current_gas' to track the gas available at the current station.
2. Initialize a variable 'start_station' to store the potential starting station's index.
3. Iterate through the gas stations in a circular manner (starting from 0 and looping back to 0):
   - For each station, calculate the difference between gas and cost (gas[i] - cost[i]) and add it to 'current_gas'.
   - If 'current_gas' becomes negative at any station, reset 'current_gas' to 0 and update 'start_station' to the next station.
   - Keep track of 'total_gas' by accumulating the gas-cost differences.
4. If 'total_gas' is non-negative, return 'start_station' as the answer; otherwise, return -1, indicating that it's impossible to complete the tour.

Time Complexity:
O(n), where n is the number of gas stations. We perform a single pass through the stations.

Space Complexity:
O(1), as we only use a constant amount of extra space to store variables.
*/

impl Solution {
    pub fn can_complete_circuit(gas: Vec<i32>, cost: Vec<i32>) -> i32 {
        let mut total_gas = 0;
        let mut current_gas = 0;
        let mut start_station = 0;

        for i in 0..gas.len() {
            let diff = gas[i] - cost[i];
            current_gas += diff;
            total_gas += diff;

            if current_gas < 0 {
                current_gas = 0;
                start_station = i + 1;
            }
        }

        if total_gas >= 0 {
            start_station as i32
        } else {
            -1
        }
    }
}
