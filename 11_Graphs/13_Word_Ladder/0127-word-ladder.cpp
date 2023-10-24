/*
Problem: LeetCode 127 - Word Ladder

Description:
Given two words, beginWord and endWord, and a dictionary wordList, return the length of the shortest transformation sequence from beginWord to endWord, such that:
- Only one letter can be changed at a time.
- Each transformed word must exist in the wordList.

If there is no such transformation sequence, return 0.

Intuition:
This problem can be solved using a graph traversal algorithm such as breadth-first search (BFS). We can treat each word as a node in the graph and connect the words that differ by a single character. The problem then reduces to finding the shortest path from the beginWord to the endWord.

Approach:
1. Build a set from the wordList for efficient lookup.
2. Create a queue for BFS traversal and initialize it with the beginWord.
3. Initialize a distance variable to track the length of the transformation sequence.
4. Perform BFS:
   - Pop the front word from the queue.
   - For each character position in the word, replace it with each of the 26 alphabets and check if the resulting word is in the wordList.
   - If the resulting word is the endWord, return the current distance + 1.
   - If the resulting word is in the wordList, add it to the queue and remove it from the wordList to avoid revisiting.
5. If no transformation sequence is found, return 0.

Time Complexity:
The time complexity is O(N * M^2), where N is the number of words in the wordList and M is the length of the words. In the worst case, we may need to explore all possible transformations of each word.

Space Complexity:
The space complexity is O(N * M^2), where N is the number of words in the wordList and M is the length of the words. This is the space used for the wordList set, queue, and visited set.
*/

class Solution {
  public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());  // Convert wordList to a set for efficient lookup

        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;  // endWord is not in the wordList, no transformation sequence possible
        }

        queue<string> q;
        q.push(beginWord);
        int distance = 1;

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; ++i) {
                string currentWord = q.front();
                q.pop();

                // Check each character position of the word and replace it with all possible alphabets
                for (int j = 0; j < currentWord.length(); ++j) {
                    char originalChar = currentWord[j];

                    for (char c = 'a'; c <= 'z'; ++c) {
                        currentWord[j] = c;

                        if (currentWord == endWord) {
                            return distance + 1;  // Transformation sequence found, return the distance
                        }

                        if (wordSet.find(currentWord) != wordSet.end()) {
                            q.push(currentWord);  // Add the transformed word to the queue
                            wordSet.erase(currentWord);  // Remove the transformed word from the wordSet
                        }
                    }

                    currentWord[j] = originalChar;  // Revert back the character
                }
            }

            ++distance;  // Increment the distance for each level of BFS traversal
        }

        return 0;  // No transformation sequence found
    }
};

// Bidirectional BFS
/*
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end()); // Convert wordList to a set for efficient lookup

        if (wordSet.find(endWord) == wordSet.end()) {
            return 0; // endWord is not in the wordList, no transformation sequence possible
        }

        unordered_set<string> beginSet, endSet; // Sets for the current level of traversal from the beginWord and endWord
        beginSet.insert(beginWord);
        endSet.insert(endWord);

        int distance = 1; // Distance between beginWord and endWord

        while (!beginSet.empty() && !endSet.empty()) {
            // Always expand the smaller set to reduce the search space
            if (beginSet.size() > endSet.size()) {
                swap(beginSet, endSet);
            }

            unordered_set<string> temp; // Temporary set to store the next level of words

            for (const string& word : beginSet) {
                string currentWord = word;

                // Check each character position of the word and replace it with all possible alphabets
                for (int i = 0; i < currentWord.length(); ++i) {
                    char originalChar = currentWord[i];

                    for (char c = 'a'; c <= 'z'; ++c) {
                        currentWord[i] = c;

                        if (endSet.find(currentWord) != endSet.end()) {
                            return distance + 1; // Transformation sequence found, return the distance
                        }

                        if (wordSet.find(currentWord) != wordSet.end()) {
                            temp.insert(currentWord); // Add the transformed word to the next level set
                            wordSet.erase(currentWord); // Remove the transformed word from the wordSet
                        }
                    }

                    currentWord[i] = originalChar; // Revert back the character
                }
            }

            swap(beginSet, temp); // Update the current level set with the next level set
            ++distance; // Increment the distance for each level of BFS traversal
        }

        return 0; // No transformation sequence found
    }
};
*/