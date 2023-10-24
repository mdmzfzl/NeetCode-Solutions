/*
Problem: LeetCode 238 - Product of Array Except Self

Key Idea:
The key idea is to compute the product of all elements to the left of each element and the product of all elements to the right of each element. The final product for each element is the product of these left and right products.

Approach:
1. Create two arrays, `prefix` and `postfix`, of the same size as the input array to store the products of elements to the left and right of each index, respectively.
2. Initialize `prefix[0] = 1` and `postfix[n-1] = 1`, where n is the length of the input array.
3. Populate the `prefix` array by iterating through the input array from left to right. `prefix[i]` will be the product of `prefix[i-1]` and `nums[i-1]`.
4. Populate the `postfix` array by iterating through the input array from right to left. `postfix[i]` will be the product of `postfix[i+1]` and `nums[i+1]`.
5. For each index i, the result for that index is `prefix[i] * postfix[i]`.

Time Complexity:
O(n), where n is the length of the input array. We iterate through the input array three times.

Space Complexity:
O(n), as we use two additional arrays, `prefix` and `postfix`, each of size n.
*/

impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut prefix = vec![1; n];
        let mut postfix = vec![1; n];

        for i in 1..n {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        for i in (0..n - 1).rev() {
            postfix[i] = postfix[i + 1] * nums[i + 1];
        }

        let mut result = vec![1; n];
        for i in 0..n {
            result[i] = prefix[i] * postfix[i];
        }

        result
    }
}
