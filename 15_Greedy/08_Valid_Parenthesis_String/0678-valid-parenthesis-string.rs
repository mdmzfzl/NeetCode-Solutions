/*
Problem: LeetCode 678 - Valid Parenthesis String

Key Idea:
The key idea is to maintain two counters, 'balance_low' and 'balance_high,' to keep track of the possible minimum and maximum open parentheses.

Approach:
1. Initialize two variables 'balance_low' and 'balance_high' to 0. These variables will track the minimum and maximum open parentheses count.
2. Iterate through each character 'ch' in the input string 's':
   - If 'ch' is '(', increment both 'balance_low' and 'balance_high' because it can be used as an open parenthesis.
   - If 'ch' is '*', decrement 'balance_low' (considering it as an empty string) and increment 'balance_high' (considering it as an open parenthesis or empty string).
   - If 'ch' is ')', decrement both 'balance_low' and 'balance_high' because it can be used as a close parenthesis.
   - If 'ch' is any other character, it should not exist in a valid string, so we use 'unreachable!' to indicate an unreachable code path.
3. After processing each character, check if 'balance_high' is negative. If it is, return false because there are more closing parentheses than open parentheses, and it's impossible to balance them.
4. To ensure 'balance_low' is non-negative, use 'balance_low.max(0)' to set it to zero if it becomes negative.
5. After processing the entire string, check if 'balance_low' is zero. If it is, return true because it means all open parentheses have corresponding close parentheses.
6. If 'balance_low' is not zero, return false because there are unmatched open parentheses.

Time Complexity:
O(n), where n is the length of the input string 's.' We perform a single pass through the string.

Space Complexity:
O(1), as we use only a constant amount of extra space for variables.
*/

impl Solution {
    pub fn check_valid_string(s: String) -> bool {
        let (mut balance_low, mut balance_high) = (0, 0);

        for ch in s.chars() {
            match ch {
                '(' => {
                    balance_low += 1;
                    balance_high += 1;
                }
                '*' => {
                    balance_low -= 1;
                    balance_high += 1;
                }
                ')' => {
                    balance_low -= 1;
                    balance_high -= 1;
                }
                _ => unreachable!(),
            }

            if balance_high < 0 {
                return false;
            }

            balance_low = balance_low.max(0);
        }

        balance_low == 0
    }
}
