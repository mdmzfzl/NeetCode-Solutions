/*
Problem: LeetCode 125 - Valid Palindrome

Key Idea:
The key idea is to compare the characters in the string while ignoring non-alphanumeric characters and considering case-insensitivity.

Approach:
1. Convert the input string to lowercase to handle case-insensitivity.
2. Use two pointers, `left` and `right`, initialized to the start and end of the string.
3. Iterate while `left` is less than `right`:
   - Skip non-alphanumeric characters and increment `left` or decrement `right`.
   - Compare the characters at `left` and `right`. If they are not equal, return `false`.
   - Increment `left` and decrement `right` to continue comparing.
4. If the iteration completes without returning `false`, the string is a valid palindrome.

Time Complexity:
O(n), where n is the length of the input string. We perform a single pass through the string while comparing characters.

Space Complexity:
O(1), as we use only a constant amount of extra space for pointers and variables.
*/

impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let chars: Vec<char> = s.chars().collect();
        let mut left = 0;
        let mut right = chars.len() - 1;

        while left < right {
            while left < right && !chars[left].is_ascii_alphanumeric() {
                left += 1;
            }
            while left < right && !chars[right].is_ascii_alphanumeric() {
                right -= 1;
            }

            if chars[left].to_ascii_lowercase() != chars[right].to_ascii_lowercase() {
                return false;
            }

            left += 1;
            right -= 1;
        }

        true
    }
}

/*
// Alternative Solution

pub fn is_palindrome(s: String) -> bool {
    // Step 1: Filter out non-alphanumeric characters and convert to lowercase
    let cleaned: String = s.chars()                            // Iterate over characters in the input string
        .filter(|c| c.is_ascii_alphanumeric())                 // Keep only alphanumeric characters
        .map(|c| c.to_ascii_lowercase())                       // Convert characters to lowercase
        .collect();                                            // Collect the filtered characters into a new String

    // Step 2: Create a reversed version of the cleaned string
    let reversed: String = cleaned.chars().rev().collect();  // Reverse the characters and collect into a String

    // Step 3: Check if the cleaned string is equal to its reversed version
    cleaned == reversed                                      // Compare the cleaned and reversed strings

    // The result of the comparison is the final result of the function
}
*/