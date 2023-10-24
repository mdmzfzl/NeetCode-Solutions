/*
Problem: LeetCode 78 - Subsets

Key Idea:
To generate all possible subsets of a given set of numbers, we can use a recursive approach. Starting with an empty subset, we gradually build subsets by including or excluding each number in the set.

Approach:
1. Initialize an empty vector to store subsets.
2. Create a helper function, backtrack, that takes three parameters: the current index, the current subset being built, and the input vector of numbers.
3. In the helper function:
   a. If the current index is equal to the length of the input vector, push the current subset into the result vector.
   b. Recursively call the helper function for the next index while including the current number in the subset.
   c. Recursively call the helper function for the next index while excluding the current number from the subset.
4. Start the recursion with index 0 and an empty subset.
5. Return the result vector containing all generated subsets.

Time Complexity:
O(2^n), where n is the number of elements in the input vector. This is because there are 2^n possible subsets for n elements.

Space Complexity:
O(2^n) in the worst case, as there can be up to 2^n subsets.
*/

impl Solution {
    pub fn subsets(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = Vec::new();

        let mut current_subset: Vec<i32> = Vec::new();
        Self::backtrack(0, &mut current_subset, &nums, &mut result);

        result
    }

    // Helper function to recursively generate subsets
    fn backtrack(
        index: usize,
        current_subset: &mut Vec<i32>,
        nums: &Vec<i32>,
        result: &mut Vec<Vec<i32>>,
    ) {
        if index == nums.len() {
            // Base case: All elements processed, add current subset to the result
            result.push(current_subset.clone());
            return;
        }

        // Include the current element in the subset and recurse
        current_subset.push(nums[index]);
        Self::backtrack(index + 1, current_subset, nums, result);

        // Exclude the current element from the subset and recurse
        current_subset.pop();
        Self::backtrack(index + 1, current_subset, nums, result);
    }
}
