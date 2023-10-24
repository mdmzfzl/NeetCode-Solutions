/*
Problem: LeetCode 212 - Word Search II

Key Idea:
The key idea is to use a Trie data structure to efficiently store the given words and then perform a depth-first search (DFS) on the board to find words that match the Trie structure.

Approach:
1. Create a Trie structure with methods for inserting words and tracking word solutions. Each Trie node has 26 children (one for each lowercase letter) and a flag to mark the end of a word.
2. Insert all the words from the given list into the Trie.
3. Initialize an empty result vector `ans` to store the found words.
4. Iterate through each cell of the board and call the DFS function:
   - In the DFS function, mark the current cell as visited by replacing its character with a space.
   - Check if there's a Trie node corresponding to the character at the current cell.
   - If a word solution is found in the Trie, add it to the result vector `ans`.
   - Recursively explore the neighboring cells (up, down, left, right) that have valid characters and Trie nodes associated with them.
   - Restore the original character at the current cell.
5. After processing all cells on the board, return the `ans` vector containing the found words.

Time Complexity:
- Building the Trie from the given words takes O(W*L), where W is the total number of characters in all words, and L is the average word length.
- The DFS operation on the board has a worst-case time complexity of O(N*M*4^L), where N and M are the dimensions of the board, and L is the maximum word length. This is because, in the worst case, the algorithm explores four neighboring cells at each step for each cell on the board.

Space Complexity:
- The space complexity of the Trie structure is O(W*L), where W is the total number of characters in all words, and L is the average word length.
- The space complexity of the DFS stack is O(L), where L is the maximum word length.
*/

struct Trie {
    children: Vec<Option<Trie>>,
    is_solution: Option<String>,
}

impl Trie {
    fn new() -> Self {
        Trie {
            children: (0..26).map(|_| None).collect(),
            is_solution: None,
        }
    }

    fn insert(&mut self, word: String) {
        let mut curr = self;
        for byte in word.bytes() {
            let index = (byte - b'a') as usize;
            curr = curr.children[index].get_or_insert_with(Trie::new);
        }
        curr.is_solution = Some(word);
    }
}

impl Solution {
    pub fn find_words(mut board: Vec<Vec<char>>, words: Vec<String>) -> Vec<String> {
        let mut trie = Trie::new();
        for word in words {
            trie.insert(word);
        }
        let (n, m) = (board.len(), board[0].len());
        let mut ans = Vec::new();
        for i in 0..n {
            for j in 0..m {
                Self::dfs(&mut board, &mut trie, &mut ans, i, j);
            }
        }
        ans
    }

    fn dfs(board: &mut Vec<Vec<char>>, trie: &mut Trie, ans: &mut Vec<String>, i: usize, j: usize) {
        let c = board[i][j];
        board[i][j] = ' ';
        if let Some(next) = trie.children[(c as u8 - b'a') as usize].as_mut() {
            if let Some(word) = next.is_solution.take() {
                ans.push(word);
            }
            for &(x, y) in &[
                (i + 1, j),
                (i.wrapping_sub(1), j),
                (i, j + 1),
                (i, j.wrapping_sub(1)),
            ] {
                if x < board.len()
                    && y < board[0].len()
                    && board[x][y] != ' '
                    && next.children[(board[x][y] as u8 - b'a') as usize].is_some()
                {
                    Self::dfs(board, next, ans, x, y);
                }
            }
        }
        board[i][j] = c;
    }
}

/*
// Another Solution

use std::collections::HashMap;

type TrieNode = HashMap<char, Trie>;

#[derive(Default)]
struct Trie {
    children: TrieNode,
    word: Option<String>,
}

impl Trie {
    fn new() -> Self {
        Trie {
            children: TrieNode::new(),
            word: None,
        }
    }
}

impl Solution {
    pub fn find_words(mut board: Vec<Vec<char>>, words: Vec<String>) -> Vec<String> {
        let letter_freq = board.iter().flatten().fold(HashMap::new(), |mut acc, &ch| {
            *acc.entry(ch).or_insert(0) += 1;
            acc
        });

        let mut root = Trie::default();
        for word in words {
            let should_reverse = match (word.chars().next(), word.chars().last()) {
                (Some(first), Some(last)) => {
                    letter_freq.get(&first).unwrap_or(&0) > letter_freq.get(&last).unwrap_or(&0)
                }
                _ => false,
            };

            let processed_word: String = if should_reverse {
                word.chars().rev().collect()
            } else {
                word.clone()
            };

            let mut node = &mut root;
            for letter in processed_word.chars() {
                node = node.children.entry(letter).or_insert_with(Trie::default);
            }
            node.word = Some(word);
        }

        let mut matched_words = Vec::new();
        let (row_num, col_num) = (board.len(), board[0].len());

        fn backtracking(
            row: usize,
            col: usize,
            parent: &mut Trie,
            board: &mut Vec<Vec<char>>,
            matched_words: &mut Vec<String>,
            row_num: usize,
            col_num: usize,
        ) {
            let letter = board[row][col];
            let curr_node = match parent.children.get_mut(&letter) {
                Some(node) => node,
                None => return,
            };

            if let Some(word_match) = curr_node.word.take() {
                matched_words.push(word_match);
            }

            board[row][col] = '#';

            const ROW_ADJUST: [isize; 4] = [-1, 0, 1, 0];
            const COL_ADJUST: [isize; 4] = [0, 1, 0, -1];

            for i in 0..4 {
                let new_row = row as isize + ROW_ADJUST[i];
                let new_col = col as isize + COL_ADJUST[i];

                if new_row >= 0
                    && new_row < row_num as isize
                    && new_col >= 0
                    && new_col < col_num as isize
                {
                    backtracking(
                        new_row as usize,
                        new_col as usize,
                        curr_node,
                        board,
                        matched_words,
                        row_num,
                        col_num,
                    );
                }
            }

            board[row][col] = letter;

            if curr_node.children.is_empty() && curr_node.word.is_none() {
                parent.children.remove(&letter);
            }
        }

        for (row, col) in (0..row_num).flat_map(|r| (0..col_num).map(move |c| (r, c))) {
            if root.children.contains_key(&board[row][col]) {
                backtracking(
                    row,
                    col,
                    &mut root,
                    &mut board,
                    &mut matched_words,
                    row_num,
                    col_num,
                );
            }
        }

        matched_words
    }
}
*/
