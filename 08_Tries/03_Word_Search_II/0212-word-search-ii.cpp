/*
Problem: LeetCode 212 - Word Search II

Description:
Given an m x n board of characters and a list of words, find all words in the board.
Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
The same letter cell may not be used more than once in a word.

Intuition:
To find all the words in the board, we can use the Trie data structure to efficiently search for each word. We perform a depth-first search (DFS) starting from each cell on the board, checking if the current sequence of characters forms a valid word in the Trie.

Approach:
1. TrieNode:
   - Define a TrieNode class that represents each node in the Trie.
   - Each TrieNode has an unordered_map to store the child nodes, representing the lowercase alphabets.
   - Each TrieNode also has a boolean flag to indicate if it represents a complete word.

2. Build the Trie:
   - Construct a Trie by inserting each word from the given list into the Trie.

3. DFS Search:
   - Perform a depth-first search (DFS) starting from each cell on the board.
   - At each cell, check if the current character exists in the Trie and move to the corresponding child node.
   - Mark the current cell as visited.
   - If the current node represents a complete word, add it to the result.
   - Recursively explore the neighboring cells (up, down, left, right).
   - Backtrack by unmarking the current cell and removing the last character from the current sequence.

4. Word Search II:
   - Initialize an empty vector to store the found words.
   - Iterate through each cell on the board and perform the DFS search.
   - Return the found words as the result.

Time Complexity:
- Building the Trie: O(m), where m is the total number of characters in all words.
- DFS Search: O((m*n)*3^l), where m and n are the dimensions of the board and l is the average length of the words.

Space Complexity:
- The space complexity is O(m), where m is the total number of characters in all words (used for constructing the Trie).
- The space complexity of the recursive stack for DFS is O(l), where l is the maximum length of the words.
*/

class TrieNode {
  public:
    bool isWord;
    unordered_map<char, TrieNode *> children; // Map to store the child nodes

    TrieNode() {
        isWord = false;
    }
};

class Solution {
  public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        TrieNode *root = buildTrie(words); // Build the Trie
        int rows = board.size();
        int cols = board[0].size();
        vector<string> result;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                string currentWord = ""; // Initialize the current word for each cell
                dfs(board, i, j, root, currentWord, result); // Perform DFS search
            }
        }

        return result;
    }

  private:
    TrieNode *buildTrie(vector<string> &words) {
        TrieNode *root = new TrieNode();

        for (string &word : words) {
            TrieNode *node = root;

            for (char c : word) {
                if (node->children.find(c) == node->children.end()) {
                    node->children[c] = new TrieNode();
                }

                node = node->children[c];
            }

            node->isWord = true;
        }

        return root;
    }

    void dfs(vector<vector<char>> &board, int row, int col, TrieNode *node, string &currentWord, vector<string> &result) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] == '#') {
            return;
        }

        char c = board[row][col];

        if (node->children.find(c) == node->children.end()) {
            return;
        }

        node = node->children[c];
        currentWord += c;

        if (node->isWord) {
            result.push_back(currentWord); // Add the found word to the result
            node->isWord = false; // Mark the word as visited
        }

        board[row][col] = '#'; // Mark the current cell as visited
        // Explore the neighboring cells (up, down, left, right)
        dfs(board, row - 1, col, node, currentWord, result);
        dfs(board, row + 1, col, node, currentWord, result);
        dfs(board, row, col - 1, node, currentWord, result);
        dfs(board, row, col + 1, node, currentWord, result);
        board[row][col] = c; // Backtrack: unmark the current cell
        currentWord.pop_back(); // Remove the current character from the current word
    }
};