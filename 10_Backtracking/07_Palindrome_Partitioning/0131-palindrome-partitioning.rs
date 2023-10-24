/*
Problem: LeetCode 131 - Palindrome Partitioning

Key Idea:
To generate all possible palindrome partitions of a given string, we can use a backtracking approach. We start from the beginning of the string and recursively try to partition it into palindromes.

Approach:
1. Create a helper function, backtrack, that takes three parameters: the current position in the string, the current partition, and the result vector to store all valid partitions.
2. In the helper function:
   a. Check if the current position has reached the end of the string. If yes, add the current partition to the result vector.
   b. Otherwise, iterate through the string from the current position to the end.
   c. For each substring from the current position to the current index, check if it is a palindrome.
   d. If it is a palindrome, add it to the current partition and recursively call the helper function for the next position.
   e. After the recursive call, remove the last added substring to backtrack and explore other possibilities.
3. Initialize an empty result vector to store all valid partitions.
4. Start the recursive partitioning from the beginning of the string with an empty current partition.
5. Return the result vector containing all valid partitions.

Time Complexity:
The time complexity of this solution is O(N * 2^N), where N is the length of the input string. In the worst case, there can be 2^N possible partitions, and for each partition, we spend O(N) time to check if it is a palindrome.

Space Complexity:
The space complexity is O(N) for the recursive call stack and O(N) for the result vector, so it is O(N) in total.
*/

impl Solution {
    pub fn partition(s: String) -> Vec<Vec<String>> {
        let mut result: Vec<Vec<String>> = Vec::new();
        let mut current: Vec<String> = Vec::new();

        Self::backtrack(&s, 0, &mut current, &mut result);

        result
    }

    fn is_palindrome(s: &str) -> bool {
        let chars: Vec<char> = s.chars().collect();
        let mut left = 0;
        let mut right = chars.len() - 1;
        while left < right {
            if chars[left] != chars[right] {
                return false;
            }
            left += 1;
            right -= 1;
        }
        true
    }

    fn backtrack(s: &str, start: usize, current: &mut Vec<String>, result: &mut Vec<Vec<String>>) {
        if start == s.len() {
            // Reached the end of the string, add the current partition to the result.
            result.push(current.clone());
            return;
        }

        for end in start + 1..=s.len() {
            let substr = &s[start..end];
            if Self::is_palindrome(substr) {
                current.push(substr.to_string());
                Self::backtrack(s, end, current, result);
                current.pop(); // Backtrack
            }
        }
    }
}
