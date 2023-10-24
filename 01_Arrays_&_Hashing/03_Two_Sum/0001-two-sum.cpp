/*
Problem: LeetCode 1 - Two Sum

Description:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

Intuition:
To find the pair of numbers that add up to the target, we can utilize a hash map. By iterating through the array and checking if the complement (target - current number) exists in the hash map, we can efficiently find the desired pair.

Approach:
1. Initialize an empty hash map to store the elements and their indices.
2. Iterate through each element num and its index in the input array nums:
    - Calculate the complement as target - num.
    - If the complement exists in the hash map, return the indices [map[complement], index].
    - Otherwise, add the current element num and its index to the hash map.
3. If no solution is found, return an empty vector or handle it as per the problem's requirement.

Time Complexity:
The time complexity of this approach is O(n), where n is the size of the input array nums.
This is because we iterate through the array once and perform constant-time operations for each element.

Space Complexity:
The space complexity is O(n), as the hash map can potentially store all elements of the input array.
*/

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> numMap;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (numMap.count(complement) > 0) {
                return {numMap[complement], i};
            }

            numMap[nums[i]] = i;
        }

        return {}; // Handle no solution as per problem's requirement
    }
};

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> M;
//         vector<int> res;
//         for(int i = 0; i < nums.size(); i++) {
//             int compliment = target - nums[i];

//             // If we find the compliment
//             if(M.find(compliment) != M.end()) {
//                 // returning i and index of compliment
//                 res.push_back(M[compliment]);
//                 res.push_back(i);
//             }
//             else // insert pair
//                 M.insert( {nums[i], i});
//         }
//         return res;
//     }
// };