/*
Problem: LeetCode 90 - Subsets II

Description:
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Intuition:
To find all possible subsets of a given array that may contain duplicates, we can use a backtracking approach. The idea is to generate all possible combinations by trying out different elements at each step, while avoiding duplicate subsets. We sort the array to handle duplicates and skip adding duplicate elements to the current subset.

Approach:
1. Sort the input array `nums` to handle duplicates and generate combinations in a non-decreasing order.
2. Initialize an empty vector `subset` to store the current subset.
3. Initialize an empty vector `result` to store all subsets.
4. Define a helper function `backtrack`:
   - Add the current subset to the `result` vector.
   - Iterate through the elements in the input array `nums`:
     - If the current element is a duplicate (not the first occurrence), skip it to avoid duplicate subsets.
     - Include the current element in the subset.
     - Recursively call `backtrack` with the next index.
     - Exclude the current element from the subset.
5. Call the `backtrack` function with the initial index 0.
6. Return the `result` vector containing all subsets.

Time Complexity:
The time complexity is O(2^n), where n is the size of the input array `nums`. This is because there are 2^n possible subsets, and we generate all of them.

Space Complexity:
The space complexity is O(n), where n is the size of the input array `nums`. This is because we store the subsets in the `result` vector.
*/

class Solution {
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(), nums.end());  // Sort the array to handle duplicates
        backtrack(nums, 0, subset, result);
        return result;
    }

  private:
    void backtrack(const vector<int> &nums, int index, vector<int> &subset, vector<vector<int>> &result) {
        result.push_back(subset);  // Add the current subset to the result vector

        for (int i = index; i < nums.size(); ++i) {
            if (i > index && nums[i] == nums[i - 1]) {
                continue;  // Skip duplicate elements to avoid duplicate subsets
            }

            subset.push_back(nums[i]);  // Include the current element in the subset
            backtrack(nums, i + 1, subset, result);  // Recursively call with the next index
            subset.pop_back();  // Exclude the current element (backtrack)
        }
    }
};