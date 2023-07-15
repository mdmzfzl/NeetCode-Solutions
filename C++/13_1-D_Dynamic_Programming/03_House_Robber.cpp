/*
Problem: LeetCode 198 - House Robber

Description:
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money
stashed. The only constraint stopping you from robbing each of them is that adjacent houses have a security system
connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money
you can rob tonight without alerting the police.

Approach:
1. If the input array nums is empty, return 0.
2. Initialize three variables: prev, curr, and next.
    - prev represents the maximum amount of money that can be robbed from the previous house.
    - curr represents the maximum amount of money that can be robbed up to the current house.
    - next will store the updated maximum amount of money that can be robbed from the current house.
3. Iterate through the input array nums:
    - For each house, calculate the maximum amount of money that can be robbed:
        - next = max(prev + nums[i], curr)
        - Update prev = curr and curr = next for the next iteration.
4. Return curr, which represents the maximum amount of money that can be robbed.

Time Complexity:
The time complexity of this approach is O(n), where n is the size of the input array nums.
This is because we iterate through the input array once to calculate the maximum amount of money that can be robbed.

Space Complexity:
The space complexity is O(1), as we are using only a constant amount of extra space.

Let's implement the solution!
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int prev = 0, curr = 0, next = 0;

        for(int i = 0; i < nums.size(); i++) {
            next = max(prev + nums[i], curr);
            prev = curr;
            curr = next;
        }
        return curr;
    }
};
