/*
Problem: LeetCode 211 - Add and Search Word - Data structure

Key Idea:
The key idea is to use a Trie data structure to efficiently store and search for words with wildcard characters.

Approach:
1. Create a struct `TrieNode` to represent a node in the Trie. Each node contains:
   - A boolean flag `is_end` to indicate whether the current node marks the end of a word.
   - An array of 26 elements (one for each lowercase letter) to store child nodes.
2. Create a struct `WordDictionary` that represents the word dictionary. It contains a single field `root`, which is the root node of the Trie.
3. Implement the following methods for the `WordDictionary`:
   - `new()`: Initialize an empty dictionary with a root node.
   - `add_word(word: String)`: Insert a word into the Trie by iterating through its characters and creating nodes as necessary.
   - `search(word: String) -> bool`: Search for a word in the Trie by traversing nodes. For each character:
     - If it is a regular letter, move to the corresponding child node.
     - If it is a dot ('.'), recursively search all child nodes for the remaining word.

Time Complexity:
- Adding a word has a time complexity of O(L), where L is the length of the word.
- Searching for a word has a time complexity of O(26^M), where M is the number of dots ('.') in the word. In the worst case, all child nodes need to be explored.

Space Complexity:
- The space complexity is O(M * L), where M is the number of words added, and L is the average length of words. Each character in a word occupies space in the Trie.
*/

struct TrieNode {
    is_end: bool,
    children: [Option<Box<TrieNode>>; 26],
}

impl TrieNode {
    fn new() -> Self {
        TrieNode {
            is_end: false,
            children: Default::default(),
        }
    }
}

pub struct WordDictionary {
    root: TrieNode,
}

impl WordDictionary {
    pub fn new() -> Self {
        WordDictionary {
            root: TrieNode::new(),
        }
    }

    pub fn add_word(&mut self, word: String) {
        let mut node = &mut self.root;
        for c in word.chars() {
            let index = (c as u8 - b'a') as usize;
            node = node.children[index].get_or_insert_with(|| Box::new(TrieNode::new()));
        }
        node.is_end = true;
    }

    pub fn search(&self, word: String) -> bool {
        self.search_recursive(&self.root, word.chars().collect())
    }

    fn search_recursive(&self, node: &TrieNode, word: Vec<char>) -> bool {
        if word.is_empty() {
            return node.is_end;
        }

        let c = word[0];
        if c == '.' {
            for child in &node.children {
                if let Some(child_node) = child {
                    if self.search_recursive(child_node, word[1..].to_vec()) {
                        return true;
                    }
                }
            }
        } else {
            let index = (c as u8 - b'a') as usize;
            if let Some(child_node) = &node.children[index] {
                return self.search_recursive(child_node, word[1..].to_vec());
            }
        }

        false
    }
}
