/*
Problem: LeetCode 79 - Word Search

Key Idea:
To determine if a word exists in a 2D board, we can perform a depth-first search (DFS) starting from each cell in the board. We'll explore all possible paths to find the target word.

Approach:
1. Create a helper function, dfs, that takes four parameters: the current row and column indices, the current position in the word, and the board.
2. In the helper function:
   a. Check if the current position in the word matches the character at the current row and column in the board.
   b. If not, return false, indicating that the word cannot be formed from this position.
   c. If the current position in the word matches the character at the current row and column, mark the cell as visited (e.g., change the character to a special character like '#') to avoid revisiting it during the search.
   d. Recursively call the helper function for the adjacent cells (up, down, left, and right) with the updated position in the word.
   e. After the recursive calls, backtrack by restoring the original character at the current cell.
3. Iterate through all cells in the board, and for each cell, start the search with the first character of the word.
4. If any search from any cell returns true, it means the word exists on the board, so return true.
5. If no search from any cell returns true, return false, indicating that the word does not exist on the board.
6. The main function initializes the search for each cell and returns the result.

Time Complexity:
The time complexity of this solution is O(M * N * 4^L), where M and N are the dimensions of the board, L is the length of the word, and 4^L represents the maximum number of recursive calls (exploring all possible paths).

Space Complexity:
The space complexity is O(L), where L is the length of the word, due to the recursive call stack.
*/

impl Solution {
    pub fn exist(board: Vec<Vec<char>>, word: String) -> bool {
        let word_chars: Vec<char> = word.chars().collect();
        let rows = board.len();
        let cols = board[0].len();

        for row in 0..rows {
            for col in 0..cols {
                if Self::dfs(&mut board.clone(), row, col, &word_chars, 0) {
                    return true; // Word found
                }
            }
        }

        false
    }

    // Helper function for DFS search
    fn dfs(
        board: &mut Vec<Vec<char>>,
        row: usize,
        col: usize,
        word_chars: &Vec<char>,
        word_idx: usize,
    ) -> bool {
        if word_idx == word_chars.len() {
            return true; // Word found
        }

        if row < 0 || col < 0 || row >= board.len() || col >= board[0].len() {
            return false; // Out of bounds
        }

        if board[row][col] != word_chars[word_idx] {
            return false; // Mismatched character
        }

        // Mark the cell as visited
        let original_char = board[row][col];
        board[row][col] = '#';

        // Explore adjacent cells
        let found = Self::dfs(board, row - 1, col, word_chars, word_idx + 1)
            || Self::dfs(board, row + 1, col, word_chars, word_idx + 1)
            || Self::dfs(board, row, col - 1, word_chars, word_idx + 1)
            || Self::dfs(board, row, col + 1, word_chars, word_idx + 1);

        // Restore the original character
        board[row][col] = original_char;

        found
    }
}
