/*
Problem: LeetCode 46 - Permutations

Key Idea:
To find all permutations of a given array of distinct integers, we can use a backtracking approach. Starting with an empty permutation, we gradually build permutations by considering each unused element in the input array and exploring all possible choices.

Approach:
1. Initialize an empty vector to store the result permutations.
2. Create a helper function, backtrack, that takes three parameters: the current permutation being built, a boolean array to track used elements, and the result vector.
3. In the helper function:
   a. If the current permutation size equals the input array size, push the current permutation into the result vector as a valid permutation.
   b. Iterate through the input array:
      i. If the current element is not used, mark it as used, add it to the current permutation, and recursively call the helper function.
      ii. After the recursive call, backtrack by marking the current element as unused and removing it from the current permutation.
4. Start the recursion with an empty permutation, a boolean array of all unused elements, and the result vector.
5. Return the result vector containing all valid permutations.

Time Complexity:
The time complexity of this solution is O(N!), where N is the number of elements in the input array. This is because there can be N! possible permutations.

Space Complexity:
The space complexity is O(N) for the recursion stack and the boolean array to track used elements.
*/

impl Solution {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = Vec::new();

        let mut current_permutation: Vec<i32> = Vec::new();
        let mut used: Vec<bool> = vec![false; nums.len()];

        Self::backtrack(&mut current_permutation, &mut used, &mut result, &nums);

        result
    }

    // Helper function to recursively generate permutations
    fn backtrack(
        current_permutation: &mut Vec<i32>,
        used: &mut Vec<bool>,
        result: &mut Vec<Vec<i32>>,
        nums: &Vec<i32>,
    ) {
        if current_permutation.len() == nums.len() {
            // Base case: Permutation size equals array size, add to result
            result.push(current_permutation.clone());
            return;
        }

        for (i, &num) in nums.iter().enumerate() {
            if !used[i] {
                // Mark element as used, add to current permutation, and recurse
                used[i] = true;
                current_permutation.push(num);
                Self::backtrack(current_permutation, used, result, nums);

                // Backtrack: Mark element as unused and remove from current permutation
                used[i] = false;
                current_permutation.pop();
            }
        }
    }
}
