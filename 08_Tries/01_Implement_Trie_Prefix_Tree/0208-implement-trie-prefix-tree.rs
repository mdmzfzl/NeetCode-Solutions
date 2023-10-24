/*
Problem: LeetCode 208 - Implement Trie (Prefix Tree)

Key Idea:
The key idea is to use a Trie data structure to efficiently store and search for words with common prefixes.

Approach:
1. Create a struct `TrieNode` to represent a node in the Trie. Each node contains:
   - A boolean flag `is_end` to indicate whether the current node marks the end of a word.
   - An array of 26 elements (one for each lowercase letter) to store child nodes.
2. Create a struct `Trie` that represents the Trie data structure. It contains a single field `root`, which is the root node of the Trie.
3. Implement the following methods for the `Trie`:
   - `new()`: Initialize an empty Trie with a root node.
   - `insert(word: String)`: Insert a word into the Trie by iterating through its characters and creating nodes as necessary.
   - `search(word: String) -> bool`: Search for a word in the Trie by traversing nodes and checking the `is_end` flag.
   - `starts_with(prefix: String) -> bool`: Check if any word in the Trie starts with the given prefix.
   
Time Complexity:
- Insertion, search, and starts_with operations all have a time complexity of O(L), where L is the length of the word or prefix being processed.

Space Complexity:
- The space complexity is O(M * L), where M is the number of words inserted, and L is the average length of words. Each character in a word occupies space in the Trie.
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

pub struct Trie {
    root: TrieNode,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Trie {
    pub fn new() -> Self {
        Trie { root: TrieNode::new() }
    }

    pub fn insert(&mut self, word: String) {
        let mut node = &mut self.root;
        for c in word.chars() {
            let index = (c as u8 - b'a') as usize;
            node = node.children[index].get_or_insert_with(|| Box::new(TrieNode::new()));
        }
        node.is_end = true;
    }

    pub fn search(&self, word: String) -> bool {
        let mut node = &self.root;
        for c in word.chars() {
            let index = (c as u8 - b'a') as usize;
            if let Some(next) = &node.children[index] {
                node = next;
            } else {
                return false;
            }
        }
        node.is_end
    }

    pub fn starts_with(&self, prefix: String) -> bool {
        let mut node = &self.root;
        for c in prefix.chars() {
            let index = (c as u8 - b'a') as usize;
            if let Some(next) = &node.children[index] {
                node = next;
            } else {
                return false;
            }
        }
        true
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * let obj = Trie::new();
 * obj.insert(word);
 * let ret_2: bool = obj.search(word);
 * let ret_3: bool = obj.starts_with(prefix);
**/

/**
struct Trie {
    children: HashMap<char, Trie>,
    is_end: bool,
}

impl Trie {
    fn new() -> Self {
        Trie {
            children: HashMap::new(),
            is_end: false,
        }
    }

    fn insert(&mut self, word: String) {
        let mut node = self;
        for c in word.chars() {
            node = node.children.entry(c).or_insert(Trie::new());
        }
        node.is_end = true;
    }

    fn search(&self, word: String) -> bool {
        let mut node = self;
        for c in word.chars() {
            if let Some(next_node) = node.children.get(&c) {
                node = next_node;
            } else {
                return false;
            }
        }
        node.is_end
    }

    fn starts_with(&self, prefix: String) -> bool {
        let mut node = self;
        for c in prefix.chars() {
            if let Some(next_node) = node.children.get(&c) {
                node = next_node;
            } else {
                return false;
            }
        }
        true
    }
}
**/