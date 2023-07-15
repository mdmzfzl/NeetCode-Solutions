/*
Problem: LeetCode 213 - House Robber II

Description:
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money
stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one.
Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two
adjacent houses were broken into on the same night. Given an integer array nums representing the amount of money
of each house, return the maximum amount of money you can rob tonight without alerting the police.

Approach:
1. If the input array nums is empty, return 0.
2. If the input array nums has only one house, return the money in that house.
3. Define two vectors, minusLast and minusFirst, to store the amounts of money excluding the last and first houses, respectively.
4. Use the helper function to find the maximum amount of money that can be robbed from either the minusLast or minusFirst vectors.
5. Return the maximum amount of money obtained.

Time Complexity:
The time complexity of this approach is O(n), where n is the size of the input array nums.
This is because we iterate through the input array once to calculate the maximum amount of money that can be robbed.

Space Complexity:
The space complexity is O(n), as we use two additional vectors to store the amounts of money excluding the last and first houses.

Let's implement the solution!
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];
        
        int result;
        vector<int> minusLast, minusFirst;
        // All elements excluding the last
        minusLast = nums; minusLast.pop_back();
        // All elements excluding the first
        minusFirst = nums; minusFirst.erase(minusFirst.begin());
        
        result = max(helper(minusLast), helper(minusFirst));
        return result;
    }

private:
    // This is the same function from House Robber I
    int helper(vector<int>& nums) {
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