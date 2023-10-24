/*
Problem: LeetCode 90 - Subsets II

Key Idea:
To find all unique subsets of an array that may contain duplicate elements, we can use a backtracking approach with a twist. The twist is to skip duplicates to avoid generating duplicate subsets.

Approach:
1. Sort the input array to bring duplicates together.
2. Initialize an empty vector to store the result subsets.
3. Create a helper function, backtrack, that takes three parameters: the current subset being built, the starting index for considering elements, and the result vector.
4. In the helper function:
   a. Add the current subset to the result vector.
   b. Iterate through the input array starting from the given index:
      i. If the current element is not a duplicate (i.e., it's different from the previous element), add it to the current subset and recursively call the helper function with the next index.
      ii. After the recursive call, backtrack by removing the last element from the current subset.
5. Start the recursion with an empty subset, 0 as the starting index, and the result vector.
6. Return the result vector containing all unique subsets.

Time Complexity:
The time complexity of this solution is O(2^N), where N is the number of elements in the input array. This is because there can be 2^N possible subsets.

Space Complexity:
The space complexity is O(N) for the recursion stack.
*/

impl Solution {
    pub fn subsets_with_dup(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = Vec::new();

        let mut current_subset: Vec<i32> = Vec::new();
        let mut sorted_nums = nums.clone();
        sorted_nums.sort();

        Self::backtrack(&mut current_subset, 0, &mut result, &sorted_nums);

        result
    }

    // Helper function to recursively generate subsets
    fn backtrack(
        current_subset: &mut Vec<i32>,
        start_index: usize,
        result: &mut Vec<Vec<i32>>,
        nums: &Vec<i32>,
    ) {
        result.push(current_subset.clone());

        for i in start_index..nums.len() {
            if i == start_index || nums[i] != nums[i - 1] {
                current_subset.push(nums[i]);
                Self::backtrack(current_subset, i + 1, result, nums);
                current_subset.pop();
            }
        }
    }
}
