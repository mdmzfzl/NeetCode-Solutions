/*
Problem: LeetCode 152 - Maximum Product Subarray

Key Idea:
The key idea is to maintain two variables: `max_product` and `min_product`. These variables keep track of the maximum and minimum product subarrays ending at the current index. We need to consider the minimum product because multiplying a large negative number by a negative number can result in a large positive product.

Approach:
1. Initialize three variables: `max_product`, `min_product`, and `result`, all initially set to the first element of the input array `nums[0]`.
2. Iterate through the array `nums` from the second element to the end.
3. For each element `nums[i]`, update `max_product` and `min_product` as follows:
   - Calculate the product of `max_product` with `nums[i]` and `min_product` with `nums[i]`.
   - Update `max_product` by taking the maximum of these two products and `nums[i]` itself.
   - Update `min_product` by taking the minimum of these two products and `nums[i]` itself.
   - Update `result` by taking the maximum of `result` and `max_product`.
4. After the iteration, `result` will contain the maximum product subarray.
5. Return `result` as the result.

Time Complexity:
O(n), where n is the length of the input array `nums`. We perform a single pass through the array.

Space Complexity:
O(1), as we use a constant amount of extra space to store variables.
*/

impl Solution {
    pub fn max_product(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut max_product = nums[0];
        let mut min_product = nums[0];
        let mut result = nums[0];

        for i in 1..n {
            let temp_max = max_product;
            max_product = nums[i]
                .max(max_product * nums[i])
                .max(min_product * nums[i]);
            min_product = nums[i].min(temp_max * nums[i]).min(min_product * nums[i]);
            result = result.max(max_product);
        }

        result
    }
}
