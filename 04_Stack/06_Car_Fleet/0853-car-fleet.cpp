/*
Problem: LeetCode 853 - Car Fleet

Description:
N cars are going to the same destination along a one-lane road. The destination is target miles away.
Each car i has a constant speed speed[i] (in miles per hour), and initial position position[i] miles towards the target along the road.

A car can never pass another car ahead of it, but it can catch up to it and drive bumper to bumper at the same speed.
The distance between these two cars is ignored - they are assumed to have the same position.

A car fleet is some non-empty set of cars driving at the same position and same speed. Note that a single car is also a car fleet.

If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.

Intuition:
To determine the number of car fleets that reach the destination, we can simulate the car movement and track the time it takes for each car to reach the destination.

Approach:
1. Create a vector of pairs to store the positions and speeds of the cars.
2. Sort the vector of pairs based on the positions in descending order.
3. Initialize the count of car fleets to 0.
4. Iterate through each car in the sorted vector:
   - Calculate the time it takes for the car to reach the destination (target - position) / speed.
   - If the current car's time is greater than the previous car's time (car fleet is not possible), increment the count of car fleets.
   - Update the previous car's time with the maximum of the current car's time and the previous car's time.
5. Return the count of car fleets.

Time Complexity:
The time complexity is O(n log n), where n is the number of cars. Sorting the vector of pairs takes O(n log n) time.

Space Complexity:
The space complexity is O(n), where n is the number of cars. We store the positions and speeds of the cars in a vector of pairs.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        int n = position.size();
        vector<pair<int, int>> cars;

        // Create vector of pairs to store positions and speeds
        for (int i = 0; i < n; ++i) {
            cars.push_back({position[i], speed[i]});
        }

        // Sort the vector of pairs based on positions in descending order
        sort(cars.begin(), cars.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first > b.first;
        });
        int count = 0;
        double prevTime = 0.0;

        for (int i = 0; i < n; ++i) {
            double currTime = static_cast<double>(target - cars[i].first) / cars[i].second;

            if (currTime > prevTime) {
                count++;
                prevTime = currTime;
            }
        }

        return count;
    }
};