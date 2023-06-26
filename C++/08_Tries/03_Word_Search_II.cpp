class Solution {
private: 
    // Defining TrieNode datatype
    struct TrieNode {
        TrieNode* child[26];
        // Instead of storing isWord, we are storing the word itself
        string word;

        // If word is empty all children will point to nullptr
        TrieNode() : word("") {
            for(auto &i: child)
                i = nullptr;
        }
    };

    // Building a trie for storing all words we need to search
    TrieNode* BuildTrie(vector<string> words) {
        TrieNode* root = new TrieNode();
        // Iterating through all words
        for(int i = 0; i < words.size(); i++) {
            string word = words[i];
            TrieNode* current = root;

            // Inserting the word
            for(auto i: word) {
                // index of the character i.e. a = 0, z = 25
                int index = i - 'a';
                // If char doesnt exist then we make it
                if(current->child[index] == NULL)
                    current->child[index] = new TrieNode();
                
                // Pointing current to the character we just inserted
                current = current->child[index];
            }
            current->word = word;
        }
        return root;
    }

    // DFS for searching a word
    void DFS(vector<vector<char>> &board, vector<string> &result, TrieNode *node, int i, int j) {
        char c = board[i][j];

        // # is what we are using to identify an already traversed character
        // if we traversed or the character doesnt exist, return 
        if(c == '#' || !node->child[c - 'a'])
            return;
        
        node = node->child[c - 'a'];

        // If we reached the node where word ends, then word exists and we push it into reuslt
        if(node->word.size() > 0) {
            result.push_back(node->word);
            node->word = "";
        }

        // Marking the current node as traversed to check for this word
        board[i][j] = '#';

        // Traversing all directions possible from current position
        if(i > 0)
            DFS(board, result, node, i-1, j);
        if(j > 0)
            DFS(board, result, node, i, j-1);
        if(i < board.size() - 1)
            DFS(board, result, node, i+1, j);
        if(j < board[0].size() - 1)
            DFS(board, result, node, i, j+1);
        
        // Reverting current element to original character for checking other words
        board[i][j] = c;
    }

    // Clearing memory when done
    // Optional to do
    void clear(TrieNode *root) {
        // for(int i = 0; i < 26; i++) if(root-> child[i]) clear(root -> child[i]);
        for(auto &i: root->child)
            if(i)  // if it exists
                clear(i);
        delete(root);
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Building our trie of all words we want to search
        TrieNode* root = BuildTrie(words);
        vector<string> result;

        for(int i = 0; i < board.size(); i++) 
            for(int j = 0; j < board[0].size(); j++)
                DFS(board, result, root, i, j);
        
        clear(root);
        return result;
    }
};