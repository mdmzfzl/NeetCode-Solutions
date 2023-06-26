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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */