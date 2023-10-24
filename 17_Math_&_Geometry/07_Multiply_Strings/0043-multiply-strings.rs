/*
Problem: LeetCode 43 - Multiply Strings

Key Idea:
The key idea is to simulate the process of manual multiplication, where we multiply each digit of one number with each digit of the other number and add the results at the appropriate positions. This can be efficiently done using two nested loops.

Approach:
1. Convert the input strings 'num1' and 'num2' into vectors of integers, where each digit is represented as an integer.
2. Initialize a vector 'result' with zeros, with a length equal to the sum of the lengths of 'num1' and 'num2' to store the intermediate results.
3. Use two nested loops to multiply each digit of 'num1' with each digit of 'num2' and add the results at the correct positions in 'result'.
4. After the multiplication, we may have carry values at various positions in 'result', so we need to perform a carry operation to ensure that each digit is within the range [0, 9].
5. Convert the 'result' vector back to a string representation of the multiplied number by removing leading zeros.
6. Return the final result.

Time Complexity:
O(M * N), where M and N are the lengths of the input strings 'num1' and 'num2'. The nested loops perform multiplications for each digit pair.

Space Complexity:
O(M + N), as we use vectors to store the digits of 'num1', 'num2', and 'result', where M and N are the lengths of 'num1' and 'num2'.
*/

impl Solution {
    pub fn multiply(num1: String, num2: String) -> String {
        let num1: Vec<u8> = num1.chars().map(|c| (c as u8) - b'0').collect();
        let num2: Vec<u8> = num2.chars().map(|c| (c as u8) - b'0').collect();
        let len1 = num1.len();
        let len2 = num2.len();

        let mut result: Vec<u8> = vec![0; len1 + len2];

        for i in (0..len1).rev() {
            for j in (0..len2).rev() {
                let product = num1[i] * num2[j];
                let sum = result[i + j + 1] + product;
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        // Convert result to string, removing leading zeros
        let mut result_str = String::new();
        let mut leading_zeros = true;

        for digit in result {
            if digit != 0 {
                leading_zeros = false;
            }
            if !leading_zeros {
                result_str.push((digit + b'0') as char);
            }
        }

        if result_str.is_empty() {
            return "0".to_string();
        }

        result_str
    }
}

/*
impl Solution {
    pub fn multiply(num1: String, num2: String) -> String {
        let len1 = num1.len();
        let len2 = num2.len();
        let mut result_digits = vec![0; len1 + len2];

        for (i, ch1) in num1.chars().rev().enumerate() {
            for (j, ch2) in num2.chars().rev().enumerate() {
                let digit1 = ch1.to_digit(10).unwrap() as i32;
                let digit2 = ch2.to_digit(10).unwrap() as i32;
                let product = digit1 * digit2 + result_digits[i + j];
                result_digits[i + j] = product % 10;
                result_digits[i + j + 1] += product / 10;
            }
        }

        while result_digits.len() > 1 && result_digits.last() == Some(&0) {
            result_digits.pop();
        }

        result_digits.into_iter().rev().map(|d| d.to_string()).collect::<String>()
    }
}
*/
