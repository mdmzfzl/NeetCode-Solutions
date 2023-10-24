/*
Problem: LeetCode 17 - Letter Combinations of a Phone Number

Key Idea:
To generate all possible letter combinations of a phone number, we can use a backtracking approach. We start with an empty combination and explore all possible letters for each digit of the phone number.

Approach:
1. Create a helper function, backtrack, that takes three parameters: the current digit index, the current combination, and the result vector to store all valid combinations.
2. In the helper function:
   a. Check if the current digit index has reached the end of the phone number. If yes, add the current combination to the result vector.
   b. Otherwise, get the letters corresponding to the current digit.
   c. Iterate through the letters and append each letter to the current combination.
   d. Recursively call the helper function for the next digit index.
   e. After the recursive call, remove the last added letter to backtrack and explore other possibilities.
3. Initialize an empty result vector to store all valid combinations.
4. Start the recursive combination from the first digit with an empty current combination.
5. Return the result vector containing all valid combinations.

Time Complexity:
The time complexity of this solution is O(4^N * N), where N is the number of digits in the input phone number. For each digit, there can be up to 4 letters, and we explore all possible combinations.

Space Complexity:
The space complexity is O(N) for the recursive call stack and O(N) for the result vector, so it is O(N) in total.
*/

impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
        let mapping: Vec<Vec<char>> = vec![
            vec![' '],
            vec![],
            vec!['a', 'b', 'c'],
            vec!['d', 'e', 'f'],
            vec!['g', 'h', 'i'],
            vec!['j', 'k', 'l'],
            vec!['m', 'n', 'o'],
            vec!['p', 'q', 'r', 's'],
            vec!['t', 'u', 'v'],
            vec!['w', 'x', 'y', 'z'],
        ];

        let mut result: Vec<String> = Vec::new();
        let mut current: String = String::new();

        if !digits.is_empty() {
            Self::backtrack(&digits, 0, &mut current, &mut result, &mapping);
        }

        result
    }

    fn backtrack(
        digits: &str,
        index: usize,
        current: &mut String,
        result: &mut Vec<String>,
        mapping: &Vec<Vec<char>>,
    ) {
        if index == digits.len() {
            // Reached the end of the digits, add the current combination to the result.
            result.push(current.clone());
            return;
        }

        let digit = digits.chars().nth(index).unwrap() as usize - '0' as usize;
        for &letter in &mapping[digit] {
            current.push(letter);
            Self::backtrack(digits, index + 1, current, result, mapping);
            current.pop(); // Backtrack
        }
    }
}

/*
// Faster Solution

impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
        if digits.is_empty() {
            return Vec::new();
        }

        const PHONE_MAP: [&str; 8] = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];
        let mut combinations = Vec::new();

        fn backtrack(
            current_combination: String,
            remaining_digits: &str,
            phone_map: &[&str; 8],
            combinations: &mut Vec<String>,
        ) {
            if remaining_digits.is_empty() {
                combinations.push(current_combination);
            } else {
                let digit = remaining_digits.chars().next().unwrap();
                let digit_idx = digit as usize - '2' as usize;
                let letters = phone_map[digit_idx];
                for letter in letters.chars() {
                    let new_combination = format!("{}{}", current_combination, letter);
                    backtrack(new_combination, &remaining_digits[1..], phone_map, combinations);
                }
            }
        }

        backtrack(String::new(), &digits, &PHONE_MAP, &mut combinations);
        combinations
    }
}
*/
