/*
Problem: LeetCode 127 - Word Ladder

Key Idea:
The key idea is to treat the given word list as a graph, where each word is a node, and two words are connected if they differ by only one character. We can then perform a breadth-first search (BFS) to find the shortest transformation sequence from the beginWord to the endWord.

Approach:
1. Build a set for fast word lookup in the word list.
2. Initialize a queue for BFS, starting with the beginWord.
3. Initialize a set to keep track of visited words.
4. Initialize a level variable to track the depth of the BFS.
5. Perform BFS:
   - For each word in the current level of the queue:
     - Generate all possible one-character transformations of the word.
     - Check if each transformation is in the word list and not visited.
     - If a transformation is the endWord, return the current level + 1 (depth).
     - Otherwise, add the transformation to the queue for the next level.
     - Mark the transformation as visited.
   - Increment the level.
6. If the BFS completes without finding the endWord, return 0 (no transformation sequence found).

Time Complexity:
O(M^2 * N), where M is the length of each word, and N is the total number of words in the word list. Generating all possible transformations for a word takes O(M^2) time, and we do this for each word in the word list.

Space Complexity:
O(N) for the word set and visited set, and O(M) for the queue and transformations.
*/

use std::collections::{HashSet, VecDeque};

impl Solution {
    pub fn ladder_length(begin_word: String, end_word: String, word_list: Vec<String>) -> i32 {
        let word_set: HashSet<String> = word_list.into_iter().collect();
        let mut visited: HashSet<String> = HashSet::new();
        let mut queue: VecDeque<String> = VecDeque::new();
        queue.push_back(begin_word.clone());
        visited.insert(begin_word.clone());
        let mut level = 1;

        while !queue.is_empty() {
            let level_size = queue.len();

            for _ in 0..level_size {
                if let Some(word) = queue.pop_front() {
                    let chars: Vec<char> = word.chars().collect();

                    for i in 0..chars.len() {
                        let original_char = chars[i];

                        for c in b'a'..=b'z' {
                            chars[i] = c as char;
                            let new_word: String = chars.iter().collect();

                            if word_set.contains(&new_word) {
                                if new_word == end_word {
                                    return level + 1;
                                }

                                if !visited.contains(&new_word) {
                                    visited.insert(new_word.clone());
                                    queue.push_back(new_word.clone());
                                }
                            }
                        }

                        chars[i] = original_char;
                    }
                }
            }

            level += 1;
        }

        0
    }
}
