/*
Problem: LeetCode 55 - Jump Game

Description:
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you can reach the last index.

Intuition:
To check if it's possible to reach the last index, we can use a greedy approach.
The idea is to keep track of the furthest position we can reach from the current position.
If at any point, the furthest position we can reach is less than the current position,
we know that we cannot reach the end of the array.

Approach:
1. Initialize a variable, `max_reachable`, to store the furthest position we can reach from the current position.
2. Iterate through the array from the beginning.
3. At each index, update `max_reachable` to be the maximum of `max_reachable` and `i + nums[i]`.
   This represents the furthest position we can reach from the current index.
4. If at any point, `max_reachable` is less than or equal to the current index `i`,
   return false as we cannot reach the end of the array.
5. If we successfully reach the end of the loop, return true as we can reach the last index.

Time Complexity:
The time complexity is O(n), where n is the size of the input array.
We only iterate through the array once.

Space Complexity:
The space complexity is O(1), as we use only a constant amount of extra space for the `max_reachable` variable.
*/

class Solution {
  public:
    bool canJump(vector<int> &nums) {
        int max_reachable = 0; // Initialize the furthest position we can reach

        for (int i = 0; i < nums.size(); i++) {
            // Update max_reachable to represent the furthest position we can reach from the current index
            max_reachable = max(max_reachable, i + nums[i]);

            // If max_reachable is less than or equal to the current index, we cannot reach the end
            if (max_reachable <= i) {
                return false;
            }
        }

        // If we reach the end of the loop, we can reach the last index
        return true;
    }
};