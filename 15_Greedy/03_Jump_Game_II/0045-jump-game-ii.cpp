/*
Problem: LeetCode 45 - Jump Game II

Description:
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
If it is not possible to reach the last index, return -1.

Intuition:
To find the minimum number of jumps to reach the last index, we can use a greedy approach.
The idea is to keep track of the farthest position we can reach from the current position,
and the number of jumps needed to reach that position.
We update the current position to be the farthest position and increment the jumps count.

Approach:
1. Initialize `end` to represent the farthest position we can reach in the current jump.
2. Initialize `farthest` to represent the farthest position we can reach from any index in the current jump.
3. Initialize `jumps` to keep track of the number of jumps.
4. Iterate through the array from the beginning.
5. For each index, update `farthest` to be the maximum of `farthest` and `i + nums[i]`.
   This represents the farthest position we can reach from any index in the current jump.
6. If `i` reaches `end`, it means we have reached the end of the current jump.
   Update `end` to be `farthest`, and increment the `jumps` count.
7. If at any point, `end` is greater than or equal to the last index, return the `jumps` count.
8. If we successfully reach the end of the loop and have not yet reached the last index,
   it means we cannot reach the last index. Return -1.

Time Complexity:
The time complexity is O(n), where n is the size of the input array.
We only iterate through the array once.

Space Complexity:
The space complexity is O(1), as we use only a constant amount of extra space for the variables.
*/

class Solution {
  public:
    int jump(vector<int> &nums) {
        int end = 0;
        int farthest = 0;
        int jumps = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            // Update farthest to represent the farthest position we can reach from any index in the current jump
            farthest = max(farthest, i + nums[i]);

            // If i reaches end, it means we have reached the end of the current jump
            if (i == end) {
                // Update end to be the farthest position for the next jump
                end = farthest;
                // Increment the jumps count
                jumps++;

                // If end is greater than or equal to the last index, we have reached the end
                if (end >= nums.size() - 1) {
                    return jumps;
                }
            }
        }

        // If we reach the end of the loop and have not yet reached the last index, return -1
        return -1;
    }
};