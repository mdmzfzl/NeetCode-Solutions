/*
Problem: LeetCode 39 - Combination Sum

Description:
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target.
You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times.
Note: The solution set must not contain duplicate combinations.

Intuition:
To find all unique combinations that sum to the target, we can use a backtracking approach. The idea is to generate all possible combinations by trying out different candidate elements at each step. We explore each candidate, including it in the current combination if its value does not exceed the remaining target. By backtracking, we generate all valid combinations that sum up to the target.

Approach:
1. Sort the input array `candidates` to handle duplicates and generate combinations in a non-decreasing order.
2. Initialize an empty vector `combination` to store the current combination.
3. Initialize an empty vector `result` to store all valid combinations.
4. Define a helper function `backtrack`:
   - If the remaining target is equal to 0, add the current combination to the `result` vector.
   - Otherwise:
     - Iterate through the candidates from the current index to the end:
       - If the current candidate is greater than the remaining target, break the loop (as the remaining candidates will be larger and will not fit).
       - Include the current candidate in the combination.
       - Recursively call `backtrack` with the updated remaining target (target - current candidate) and the same index (to allow choosing the same candidate multiple times).
       - Exclude the current candidate from the combination (backtrack).
5. Call the `backtrack` function with the initial target and index 0.
6. Return the `result` vector containing all valid combinations.

Time Complexity:
The time complexity is determined by the number of valid combinations. In the worst case, the algorithm explores all possible combinations. The time complexity can be approximated as O(N^target), where N is the number of candidates and target is the given target integer.

Space Complexity:
The space complexity is determined by the recursion stack and the `result` vector that stores all valid combinations. The space complexity is O(target) to store the recursion stack, and the `result` vector may contain multiple combinations.
*/

class Solution {
  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());  // Sort the candidates in ascending order
        backtrack(candidates, target, 0, combination, result);  // Call the backtrack function
        return result;
    }

  private:
    // Backtracking function to find combinations that sum up to the target
    void backtrack(const vector<int> &candidates, int target, int index, vector<int> &combination, vector<vector<int>> &result) {
        // Base case: if the target is reached, add the current combination to the result
        if (target == 0) {
            result.push_back(combination);
            return;
        }

        // Iterate through the candidates starting from the given index
        for (int i = index; i < candidates.size(); ++i) {
            // If the current candidate is greater than the target, skip the remaining candidates
            if (candidates[i] > target) {
                break;
            }

            // Include the current candidate in the combination
            combination.push_back(candidates[i]);
            // Recursively call the backtrack function with the updated target and the same index
            backtrack(candidates, target - candidates[i], i, combination, result);
            // Exclude the current candidate from the combination (backtrack)
            combination.pop_back();
        }
    }
};