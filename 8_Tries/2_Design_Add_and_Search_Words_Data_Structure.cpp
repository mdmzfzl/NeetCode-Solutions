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

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */