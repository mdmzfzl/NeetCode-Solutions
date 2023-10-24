/*
Problem: LeetCode 40 - Combination Sum II

Key Idea:
To find all unique combinations of candidates that sum to a target value, we can use a backtracking approach. However, to avoid duplicate combinations, we need to make sure that we don't consider the same candidate multiple times in a single combination and skip duplicates.

Approach:
1. Sort the input candidates to bring duplicates together.
2. Initialize an empty vector to store the result combinations.
3. Create a helper function, backtrack, that takes four parameters: the current combination being built, the current index in the candidates, the remaining target value, and the result vector.
4. In the helper function:
   a. If the remaining target is 0, add the current combination to the result vector.
   b. Otherwise, iterate through the candidates starting from the given index:
      i. If the current candidate is greater than the remaining target, stop the iteration (candidates are sorted).
      ii. If the current index is greater than the start index and the current candidate is the same as the previous candidate, skip it to avoid duplicates.
      iii. Add the current candidate to the current combination and recursively call the helper function with the updated index and remaining target reduced by the current candidate.
      iv. After the recursive call, backtrack by removing the last candidate from the current combination.
5. Start the recursion with an empty combination, 0 as the starting index, the target value, and the result vector.
6. Return the result vector containing all unique combinations.

Time Complexity:
The time complexity of this solution is O(2^N), where N is the number of elements in the input candidates. In the worst case, all possible combinations are considered.

Space Complexity:
The space complexity is O(N) for the recursion stack.
*/

impl Solution {
    pub fn combination_sum2(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = Vec::new();

        let mut current_combination: Vec<i32> = Vec::new();
        let mut sorted_candidates = candidates.clone();
        sorted_candidates.sort();

        Self::backtrack(
            &mut current_combination,
            0,
            target,
            &mut result,
            &sorted_candidates,
        );

        result
    }

    // Helper function to recursively generate combinations
    fn backtrack(
        current_combination: &mut Vec<i32>,
        start_index: usize,
        remaining_target: i32,
        result: &mut Vec<Vec<i32>>,
        candidates: &Vec<i32>,
    ) {
        if remaining_target == 0 {
            result.push(current_combination.clone());
            return;
        }

        for i in start_index..candidates.len() {
            if candidates[i] > remaining_target {
                break;
            }

            if i > start_index && candidates[i] == candidates[i - 1] {
                continue; // Skip duplicates
            }

            current_combination.push(candidates[i]);
            Self::backtrack(
                current_combination,
                i + 1,
                remaining_target - candidates[i],
                result,
                candidates,
            );
            current_combination.pop();
        }
    }
}
