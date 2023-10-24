/*
Problem: LeetCode 268 - Missing Number

Key Idea:
We can solve this by calculating the sum of all numbers from 0 to 'n' using the formula 'n * (n + 1) / 2' and subtracting the sum of the elements in the array from it.

Approach:
1. Initialize a variable 'expected_sum' to 0. This variable will store the sum of all numbers from 0 to 'n'.
2. Initialize a variable 'actual_sum' to 0. This variable will store the sum of the elements in the input array.
3. Iterate through the input array and add each element to 'actual_sum'.
4. Calculate 'expected_sum' using the formula 'n * (n + 1) / 2', where 'n' is the length of the input array.
5. The missing number is 'expected_sum - actual_sum'.
6. Return the missing number.

Time Complexity:
O(n), where 'n' is the length of the input array. We iterate through the array once to calculate 'actual_sum' and 'expected_sum'.

Space Complexity:
O(1), as we use only a constant amount of extra space.
*/

impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let n = nums.len() as i32;
        let expected_sum = n * (n + 1) / 2;
        let actual_sum: i32 = nums.iter().sum();

        expected_sum - actual_sum
    }
}

/*
impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        (nums.len() * (nums.len() + 1) / 2) as i32 - nums.iter().sum::<i32>()
    }
}
*/
