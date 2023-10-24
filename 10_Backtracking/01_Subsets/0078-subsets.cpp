/*
Problem: LeetCode 78 - Subsets

Description:
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Intuition:
To find all possible subsets of a given array, we can use a backtracking approach. We start with an empty subset and gradually add elements to it, generating all possible combinations.

Approach:
1. Initialize an empty vector `subset` to store the current subset.
2. Initialize an empty vector `result` to store all subsets.
3. Define a helper function `generateSubsets`:
   - If the index is equal to the size of the input array `nums`, add the current subset to the `result` vector.
   - Otherwise:
     - Include the current element at the current index in the subset.
     - Recursively call `generateSubsets` with the next index.
     - Exclude the current element from the subset.
     - Recursively call `generateSubsets` with the next index.
4. Call the `generateSubsets` function with the initial index 0.
5. Return the `result` vector containing all possible subsets.

Time Complexity:
The time complexity is O(2^n), where n is the size of the input array `nums`. This is because there are 2^n possible subsets, and we generate all of them.

Space Complexity:
The space complexity is O(n), where n is the size of the input array `nums`. This is because we store the subsets in the `result` vector.
*/

class Solution {
  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> subset;
        generateSubsets(nums, 0, subset, result);
        return result;
    }

  private:
    void generateSubsets(const vector<int> &nums, int index, vector<int> &subset, vector<vector<int>> &result) {
        // Base case: If we have processed all elements, add the current subset to the result
        if (index == nums.size()) {
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);  // Include the current element
        generateSubsets(nums, index + 1, subset, result);  // Recursively call with the next index
        subset.pop_back();  // Exclude the current element
        generateSubsets(nums, index + 1, subset, result);  // Recursively call with the next index
    }
};