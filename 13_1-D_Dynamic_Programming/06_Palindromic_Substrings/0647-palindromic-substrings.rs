/*
Problem: LeetCode 647 - Palindromic Substrings

Key Idea:
The key idea is to use dynamic programming to count palindromic substrings.

Approach:
1. Initialize a variable `count` to keep track of the total number of palindromic substrings found. Initially, set it to 0.
2. Create a 2D boolean array `is_palindrome` of size n x n, where n is the length of the input string.
   - `is_palindrome[i][j]` will be true if the substring from index i to j is a palindrome.
3. Iterate through the input string:
   - For each character at index `i`, set `is_palindrome[i][i]` to true, as single characters are palindromes.
   - For each pair of adjacent characters at indices `i` and `i+1`, check if they are the same. If they are, set `is_palindrome[i][i+1]` to true, indicating a palindrome of length 2.
4. Iterate through the string from length 3 to n:
   - For each substring of length `len`, starting from index `i`, check if the characters at indices `i` and `i+len-1` are the same.
   - If they are the same and the substring between them (`i+1` to `i+len-2`) is also a palindrome (`is_palindrome[i+1][i+len-2]` is true), then set `is_palindrome[i][i+len-1]` to true, indicating a palindrome of length `len`.
5. During the iteration in step 4, whenever `is_palindrome[i][i+len-1]` is set to true, increment `count` by 1.
6. After all iterations, `count` will represent the total number of palindromic substrings.
7. Return `count` as the result.

Time Complexity:
O(n^2), where n is the length of the input string. We fill in the `is_palindrome` table in a nested loop.

Space Complexity:
O(n^2), as we use a 2D boolean array of size n x n to store the palindrome information.
*/

impl Solution {
    pub fn count_substrings(s: String) -> i32 {
        let n = s.len();
        let s = s.chars().collect::<Vec<_>>();
        let mut is_palindrome = vec![vec![false; n]; n];
        let mut count = 0;

        // Single characters are palindromes
        for i in 0..n {
            is_palindrome[i][i] = true;
            count += 1;
        }

        // Check for palindromes of length 2
        for i in 0..n - 1 {
            if s[i] == s[i + 1] {
                is_palindrome[i][i + 1] = true;
                count += 1;
            }
        }

        // Check for palindromes of length >= 3
        for len in 3..=n {
            for i in 0..=n - len {
                let j = i + len - 1;
                if s[i] == s[j] && is_palindrome[i + 1][j - 1] {
                    is_palindrome[i][j] = true;
                    count += 1;
                }
            }
        }

        count
    }
}

/*
// Alternate solution

impl Solution {
    pub fn count_substrings(s: String) -> i32 {
        let s = s.chars().collect::<Vec<char>>();
        let length = s.len() as i32;
        let mut count = 0;

        for i in 0..length {
            // Odd-length palindromes
            let (mut left, mut right) = (i, i);
            while left >= 0 && right < length && s[left as usize] == s[right as usize] {
                count += 1;
                left -= 1;
                right += 1;
            }

            // Even-length palindromes
            let (mut left, mut right) = (i, i + 1);
            while left >= 0 && right < length && s[left as usize] == s[right as usize] {
                count += 1;
                left -= 1;
                right += 1;
            }
        }

        count
    }
}
*/
