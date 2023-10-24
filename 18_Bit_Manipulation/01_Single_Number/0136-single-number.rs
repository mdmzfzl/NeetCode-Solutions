/*
Problem: LeetCode 136 - Single Number

Key Idea:
The key idea is to use the bitwise XOR operation to find the single number in the array. XOR has the property that it returns 1 for each bit position where the two input bits are different and 0 for each bit position where they are the same. Therefore, when we XOR all the elements in the array, all the elements that appear twice will cancel each other out, leaving only the single element.

Approach:
1. Initialize a variable 'result' to 0. This variable will store the single number.
2. Iterate through each element 'num' in the array.
3. Update 'result' by XOR-ing it with 'num'.
4. After the loop, 'result' will contain the single number that appears only once in the array.
5. Return 'result'.

Time Complexity:
O(n), where 'n' is the number of elements in the array. We iterate through the array once.

Space Complexity:
O(1), as we use a constant amount of extra space.
*/

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut result = 0;
        for num in nums {
            result ^= num;
        }
        result
    }
}

/*
// One liner

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        nums.iter().fold(0, |acc, x| acc ^ x)
    }
}
*/
