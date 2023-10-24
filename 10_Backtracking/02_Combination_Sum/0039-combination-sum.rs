/*
Problem: LeetCode 39 - Combination Sum

Key Idea:
To find all unique combinations of numbers in a given array that sum up to a target value, we can use a recursive backtracking approach. Starting with an empty combination, we gradually build combinations by considering each number in the array and exploring all possible combinations.

Approach:
1. Initialize an empty vector to store the result combinations.
2. Create a helper function, backtrack, that takes four parameters: the current index, the current combination being built, the remaining target value, and the input vector of numbers.
3. In the helper function:
   a. If the remaining target value becomes zero, push the current combination into the result vector as a valid combination.
   b. If the remaining target value becomes negative or the current index exceeds the array bounds, return without making any changes.
   c. Recursively call the helper function with the current index to include the current number in the combination and subtract the number from the remaining target value.
   d. Recursively call the helper function with the next index to exclude the current number from the combination and keep the target value unchanged.
4. Start the recursion with index 0, an empty combination, and the target value equal to the input target.
5. Return the result vector containing all valid combinations.

Time Complexity:
The time complexity of this solution is exponential, as there can be many valid combinations. In the worst case, it can be O(N^target), where N is the number of elements in the input vector.

Space Complexity:
The space complexity depends on the number of valid combinations. In the worst case, it can be O(target) for the recursion stack.
*/

impl Solution {
    pub fn combination_sum(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = Vec::new();

        let mut current_combination: Vec<i32> = Vec::new();
        Self::backtrack(
            0,
            &mut current_combination,
            target,
            &candidates,
            &mut result,
        );

        result
    }

    // Helper function to recursively generate combinations
    fn backtrack(
        index: usize,
        current_combination: &mut Vec<i32>,
        remaining_target: i32,
        candidates: &Vec<i32>,
        result: &mut Vec<Vec<i32>>,
    ) {
        if remaining_target == 0 {
            // Base case: Target sum reached, add current combination to result
            result.push(current_combination.clone());
            return;
        }

        if remaining_target < 0 || index >= candidates.len() {
            // Base case: Invalid combination, return without changes
            return;
        }

        // Include the current number in the combination and recurse
        current_combination.push(candidates[index]);
        Self::backtrack(
            index,
            current_combination,
            remaining_target - candidates[index],
            candidates,
            result,
        );

        // Exclude the current number from the combination and recurse with the next number
        current_combination.pop();
        Self::backtrack(
            index + 1,
            current_combination,
            remaining_target,
            candidates,
            result,
        );
    }
}
