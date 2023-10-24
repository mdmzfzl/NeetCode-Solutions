/*
Problem: LeetCode 211 - Design Add and Search Words Data Structure

Description:
Design a data structure that supports adding new words and finding if a string matches any previously added string.
The word may contain only lowercase alphabets '.' or be an empty string.

Intuition:
To solve this problem, we can use a Trie data structure to store the words. The Trie allows efficient insertion and search operations. For the '.' character, we need to consider all possible characters at that position.

Approach:
1. TrieNode:
   - Define a TrieNode class that represents each node in the Trie.
   - Each TrieNode has an array of pointers to child nodes, representing the lowercase alphabets and the '.' character.
   - Each TrieNode also has a boolean flag to indicate if it represents a complete word.

2. WordDictionary:
   - Define a WordDictionary class that contains the root of the Trie.
   - Implement the addWord method to add a word to the Trie:
     - Start from the root and iterate over each character in the word.
     - For each character, check if the corresponding child node exists. If not, create a new node and link it to the current node.
     - Move to the child node and repeat the process for the next character.
     - After iterating through all characters, mark the last node as a complete word.
   - Implement the search method to search for a word in the Trie:
     - Start from the root and iterate over each character in the word.
     - For each character, check if the corresponding child node exists. If not, return false.
     - Move to the child node and repeat the process for the next character.
     - After iterating through all characters, check if the last node represents a complete word.
   - Implement the searchWithWildcard method to search for a word with wildcard characters ('.') in the Trie:
     - Use a recursive approach to search for the word.
     - If the current character is a wildcard ('.'), iterate over all possible child nodes and recursively search for the remaining word.
     - If the current character is not a wildcard, check if the corresponding child node exists and recursively search for the remaining word.
     - Return true if any of the recursive searches return true.
     - Return false if no matching word is found.

Time Complexity:
- Adding a word: O(m), where m is the length of the word being added.
- Searching a word: O(m), where m is the length of the word being searched.
- Searching a word with wildcard: O(n*m), where n is the number of words in the Trie and m is the length of the word being searched.

Space Complexity:
- The space complexity is O(n*m), where n is the number of words added to the Trie and m is the average length of the words.

*/

class TrieNode {
  public:
    bool isWord;
    TrieNode *children[26];

    TrieNode() {
        isWord = false;

        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
  private:
    TrieNode *root;

  public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode *node = root;

        for (char c : word) {
            int index = c - 'a';

            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }

            node = node->children[index];
        }

        node->isWord = true;
    }

    bool search(string word) {
        return searchHelper(word, root, 0);
    }

    bool searchHelper(string word, TrieNode *node, int index) {
        if (index == word.length()) {
            return node->isWord;
        }

        char c = word[index];

        if (c != '.') {
            int childIndex = c - 'a';

            if (node->children[childIndex]) {
                return searchHelper(word, node->children[childIndex], index + 1);
            } else {
                return false;
            }
        } else {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] && searchHelper(word, node->children[i], index + 1)) {
                    return true;
                }
            }

            return false;
        }
    }
};

/*
class WordDictionary {
private:
    struct TrieNode {
        TrieNode* child[26];
        bool isWord;

        TrieNode() {
            for(auto &i: child)
                i = nullptr;
            isWord = false;
        }
    };
    TrieNode* root;

    bool searchInNode(string& word, int i, TrieNode* node) {
        if (node == NULL)
            return false;

        if (i == word.size())
            return node->isWord;

        // if its an alphabet and not .
        if (word[i] != '.')
            return searchInNode(word, i + 1, node->child[word[i] - 'a']);

        // If the current character is a dot, we need to check all children of the current node
        // recursively by skipping over the dot character and moving to the next character of the word
        for (int j = 0; j < 26; j++)
            if (searchInNode(word, i + 1, node->child[j]))
                return true;

        return false;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode *current = root;

        for(auto c: word) {
            int i = c - 'a';
            if(!current->child[i])
                current->child[i] = new TrieNode();

            current = current->child[i];
        }
        current->isWord = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        return searchInNode(word, 0, node);
    }
};
*/