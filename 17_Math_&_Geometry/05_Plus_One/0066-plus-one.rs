/*
Problem: LeetCode 66 - Plus One

Key Idea:
The key idea is to simulate the addition of one to the given number as if it were an integer. This is essentially adding 1 to the last digit and handling any carryover that might occur.

Approach:
1. Start iterating from the least significant digit (the rightmost digit) to the most significant digit (the leftmost digit).
2. Add 1 to the current digit.
3. Check if there is a carryover from the addition. If there is a carryover, set the current digit to 0 and continue to the next digit.
4. If there is no carryover, the addition is complete, and we can return the updated array.
5. If the loop completes and there is still a carryover, it means we need to insert a new digit at the beginning of the array with a value of 1.

Time Complexity:
O(n), where 'n' is the number of digits in the input array. In the worst case, we may need to traverse the entire array.

Space Complexity:
O(1), as we modify the input array in-place and do not use any additional data structures.
*/

impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let mut digits = digits;
        let mut carry = 1;

        for i in (0..digits.len()).rev() {
            let sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }

        if carry > 0 {
            digits.insert(0, 1);
        }

        digits
    }
}
