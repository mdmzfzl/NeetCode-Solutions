/*
Problem: LeetCode 40 - Combination Sum II

Description:
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Intuition:
To find all unique combinations that sum to the target, we can use a backtracking approach. The idea is to generate all possible combinations by trying out different candidate elements at each step.
However, we need to skip duplicate combinations to avoid duplicates in the solution set.

Approach:
1. Sort the input array `candidates` to handle duplicates and generate combinations in a non-decreasing order.
2. Initialize an empty vector `combination` to store the current combination.
3. Initialize an empty vector `result` to store all valid combinations.
4. Define a helper function `backtrack`:
   - If the current sum is equal to the target, add the current combination to the `result` vector.
   - Otherwise:
     - Iterate through the candidates from the current index to the end:
       - If the current candidate is greater than the remaining target, break the loop (as the remaining candidates will be larger and won't fit).
       - If the current candidate is a duplicate (not the first occurrence), skip it to avoid duplicate combinations.
       - Include the current candidate in the combination.
       - Recursively call `backtrack` with the updated sum and the next index.
       - Exclude the current candidate from the combination.
5. Call the `backtrack` function with the initial sum of 0 and index 0.
6. Return the `result` vector containing all valid combinations.

Time Complexity:
The time complexity is O(2^n), where n is the size of the input array `candidates`. This is because there are 2^n possible combinations, and we generate all of them.

Space Complexity:
The space complexity is O(n), where n is the size of the input array `candidates`. This is because we store the combinations in the `result` vector.
*/

class Solution {
  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());  // Sort the candidates
        backtrack(candidates, target, 0, combination, result);
        return result;
    }

  private:
    void backtrack(const vector<int> &candidates, int target, int index, vector<int> &combination, vector<vector<int>> &result) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            if (candidates[i] > target) {
                break;  // Skip remaining candidates since they will be larger and won't fit
            }

            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;  // Skip duplicate candidates to avoid duplicate combinations
            }

            combination.push_back(candidates[i]);  // Include the current candidate
            backtrack(candidates, target - candidates[i], i + 1, combination, result);  // Recursively call with updated target and next index
            combination.pop_back();  // Exclude the current candidate (backtrack)
        }
    }
};