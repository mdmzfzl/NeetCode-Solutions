/*
Problem: LeetCode 1 - Two Sum

Key Idea:
The key idea is to use a hashmap to store the elements as we traverse through the input array. For each element, we check if the complement (target - current element) is already in the hashmap. If it is, we've found a solution; if not, we add the current element to the hashmap for future reference.

Approach:
1. Create an empty hashmap to store the elements.
2. Iterate through the input array:
   - For each element `num` at index `i`, calculate the complement `complement = target - num`.
   - Check if `complement` exists in the hashmap. If yes, return `[index_of_complement, i]`.
   - Otherwise, add `num` to the hashmap with its index as the value.
3. If no solution is found, return an empty vector.

Time Complexity:
O(n), where n is the number of elements in the input array. We iterate through the array once, and each lookup in the hashmap takes O(1) time on average.

Space Complexity:
O(n), as the hashmap can contain up to n elements in the worst case.
*/

use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut num_indices: HashMap<i32, i32> = HashMap::new();

        for (i, &num) in nums.iter().enumerate() {
            let complement = target - num;
            if let Some(&index) = num_indices.get(&complement) {
                return vec![index, i as i32];
            }
            num_indices.insert(num, i as i32);
        }

        vec![]
    }
}
