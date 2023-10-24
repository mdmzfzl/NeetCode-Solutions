/*
Problem: LeetCode 134 - Gas Station

Description:
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).
You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.

Intuition:
To determine if there exists a valid starting gas station, we can follow a greedy approach.
If the total gas available is greater than or equal to the total cost of traveling the circuit,
then there must be a starting gas station that allows us to complete the circuit without running out of gas.

Approach:
1. Initialize variables `totalGas` and `totalCost` to store the total gas available and the total cost of traveling the circuit, respectively.
2. Initialize variables `currentGas` and `start` to store the current gas in the tank and the starting gas station index, respectively.
3. Iterate through the gas stations in a circular manner using a for loop.
4. For each gas station `i`, calculate the difference `diff` between the gas available `gas[i]` and the cost to travel to the next station `cost[i]`.
   Add `diff` to `currentGas` to simulate traveling to the next station.
5. If `currentGas` becomes negative at any station, it means we cannot reach the next station.
   In this case, reset `currentGas` to 0 and update `start` to be the next station index.
6. Keep adding `diff` to `totalGas` and `totalCost` as we traverse through the circular route.
7. At the end of the loop, check if `totalGas` is greater than or equal to `totalCost`.
   If true, return `start` as the starting gas station index.
8. If `totalGas` is less than `totalCost`, it means there is no valid starting gas station.
   Return -1.

Time Complexity:
The time complexity is O(n), where n is the number of gas stations. We only traverse through the gas stations once.

Space Complexity:
The space complexity is O(1), as we use only a constant amount of extra space for the variables.
*/

class Solution {
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int totalGas = 0; // Total gas available
        int totalCost = 0; // Total cost of traveling the circuit
        int currentGas = 0; // Current gas in the tank
        int start = 0; // Starting gas station index

        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i]; // Difference between gas available and cost to travel to the next station
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += diff;

            // If currentGas becomes negative, reset it to 0 and update start to be the next station index
            if (currentGas < 0) {
                currentGas = 0;
                start = i + 1;
            }
        }

        // If totalGas is greater than or equal to totalCost, there exists a valid starting gas station
        if (totalGas >= totalCost) {
            return start;
        }

        // If totalGas is less than totalCost, there is no valid starting gas station
        return -1;
    }
};