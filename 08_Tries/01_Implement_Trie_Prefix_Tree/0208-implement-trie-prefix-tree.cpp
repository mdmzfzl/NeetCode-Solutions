/*
Problem: LeetCode 208 - Implement Trie (Prefix Tree)

Description:
Implement a trie with insert, search, and startsWith methods.

Intuition:
A trie, also known as a prefix tree, is a tree-like data structure that stores a set of strings. Each node in the trie represents a prefix or a complete word. The trie allows efficient insertion, search, and prefix matching operations.

Approach:
1. TrieNode:
   - Define a TrieNode class that represents each node in the trie.
   - Each TrieNode has an array of pointers to child nodes, representing the 26 lowercase letters of the English alphabet.
   - Each TrieNode also has a boolean flag to indicate if it represents a complete word.

2. Trie:
   - Define a Trie class that contains the root of the trie.
   - Implement the insert method to insert a word into the trie:
     - Start from the root and iterate over each character in the word.
     - For each character, check if the corresponding child node exists. If not, create a new node and link it to the current node.
     - Move to the child node and repeat the process for the next character.
     - After iterating through all characters, mark the last node as a complete word.
   - Implement the search method to search for a word in the trie:
     - Start from the root and iterate over each character in the word.
     - For each character, check if the corresponding child node exists. If not, the word is not in the trie.
     - Move to the child node and repeat the process for the next character.
     - After iterating through all characters, check if the last node represents a complete word.
   - Implement the startsWith method to check if there is any word in the trie that starts with the given prefix:
     - Start from the root and iterate over each character in the prefix.
     - For each character, check if the corresponding child node exists. If not, there are no words with the given prefix.
     - Move to the child node and repeat the process for the next character.
     - After iterating through all characters, return true, indicating that there are words with the given prefix.

Time Complexity:
- Insert: O(m), where m is the length of the word being inserted.
- Search: O(m), where m is the length of the word being searched.
- StartsWith: O(m), where m is the length of the prefix being checked.

Space Complexity:
- The space complexity is O(n*m), where n is the number of words inserted into the trie and m is the average length of the words.

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

class Trie {
  private:
    TrieNode *root;

  public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
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
        TrieNode *node = root;

        for (char c : word) {
            int index = c - 'a';

            if (!node->children[index]) {
                return false;
            }

            node = node->children[index];
        }

        return node->isWord;
    }

    bool startsWith(string prefix) {
        TrieNode *node = root;

        for (char c : prefix) {
            int index = c - 'a';

            if (!node->children[index]) {
                return false;
            }

            node = node->children[index];
        }

        return true;
    }
};

/*
class Trie {
private:
    // Defining TrieNode Datatype
    struct TrieNode {
        // Can have 26 diffenet childen because thats the amt of alphabets
        TrieNode *child[26];
        // To check where the word ends
        bool isWord;

        //Constructor to initialise values
        TrieNode() {
            isWord = false;
            for (auto &c : child)
                c = nullptr;
        }
    };
    // Root pointer
    TrieNode *root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        // Pointer to point the character we insert in trie
        TrieNode* current = root;
        for(auto i: word) {
            // index of the character i.e. a = 0, z = 25
            int index = i - 'a';
            if(current->child[index] == NULL)
                current->child[index] = new TrieNode();

            // Pointing current to the character we just inserted
            current = current->child[index];
        }
        current->isWord = true;
    }

    bool search(string word) {
        TrieNode *current = root;
        for(auto i: word) {
            int index = i - 'a';

            // If the child isn't there, return false. Else keep going.
            if(current->child[index] == NULL)
                return false;

            current = current->child[index];
        }
        // Will return true if it's a word
        return current->isWord;
    }

    // Same code as search but here we dont need to check if its a word
    bool startsWith(string prefix) {
        TrieNode *current = root;
        for(auto i: prefix) {
            int index = i - 'a';

            // If the child isn't there, return false. Else keep going.
            if(current->child[index] == NULL)
                return false;

            current = current->child[index];
        }
        return true;
    }
};
*/