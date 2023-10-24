/*
Problem: LeetCode 269 - Alien Dictionary

Description:
Given a list of words in the alien language, find the order of the characters in this language.

The alien language is represented by a given dictionary, which will have words in an arbitrary order.
Each word consists of lowercase letters ('a' to 'z') and will not have duplicate characters.

It is guaranteed that no two words in the dictionary have the same ordering of letters.

If the order is invalid, return an empty string. There may be multiple valid orderings, you should return the smallest one in lexicographical order.

Intuition:
This problem can be solved using topological sorting. The given dictionary represents the relationship between characters in the alien language. The order of characters in the alien language can be determined by their relative positions in the words of the dictionary.

Approach:
1. Create a graph to represent the relationship between characters in the alien language.
2. Traverse the dictionary and add edges to the graph based on the order of characters in adjacent words.
3. Perform topological sorting on the graph to get the order of characters in the alien language.
4. Return the result as a string.

Time Complexity:
The time complexity of the solution is O(N), where N is the total number of characters in all the words in the dictionary. The reason is that we iterate through each character once to build the graph and perform topological sorting.

Space Complexity:
The space complexity of the solution is O(1) since we are using a fixed-size array of size 26 to represent the graph.

Topological Sorting:
- Intuition: Topological sorting is used to find the linear order of vertices in a directed acyclic graph (DAG) such that for every directed edge (u, v), vertex u comes before v in the ordering.
- Approach: We use a depth-first search (DFS) based approach to perform topological sorting. We start from a source vertex (a vertex with no incoming edges) and visit its neighbors recursively. After visiting all the neighbors, we add the current vertex to the result stack. The result stack will contain the vertices in the correct order.
*/

class Solution {
  public:
    string alienOrder(vector<string> &words) {
        // Initialize the graph and indegree array
        vector<vector<bool>> graph(26, vector<bool>(26, false));
        vector<int> indegree(26, -1);
        // Step 1: Build the graph and calculate indegrees
        buildGraph(words, graph, indegree);
        // Step 2: Perform topological sorting using DFS
        string result = topologicalSort(graph, indegree);
        return result;
    }

  private:
    // Helper function to build the graph and calculate indegrees
    void buildGraph(vector<string> &words, vector<vector<bool>> &graph, vector<int> &indegree) {
        for (string &word : words) {
            for (char c : word) {
                indegree[c - 'a'] = 0;
            }
        }

        for (int i = 1; i < words.size(); i++) {
            string prevWord = words[i - 1];
            string currWord = words[i];
            int len = min(prevWord.length(), currWord.length());

            for (int j = 0; j < len; j++) {
                char prevChar = prevWord[j];
                char currChar = currWord[j];

                if (prevChar != currChar) {
                    if (!graph[prevChar - 'a'][currChar - 'a']) {
                        graph[prevChar - 'a'][currChar - 'a'] = true;
                        indegree[currChar - 'a']++;
                    }

                    break;
                }
            }
        }
    }

    // Helper function for topological sorting using DFS
    string topologicalSort(vector<vector<bool>> &graph, vector<int> &indegree) {
        string result = "";
        stack<char> st;

        for (int i = 0; i < 26; i++) {
            if (indegree[i] == 0) {
                st.push('a' + i);
            }
        }

        while (!st.empty()) {
            char curr = st.top();
            st.pop();
            result += curr;

            for (int i = 0; i < 26; i++) {
                if (graph[curr - 'a'][i]) {
                    indegree[i]--;

                    if (indegree[i] == 0) {
                        st.push('a' + i);
                    }
                }
            }
        }

        // If there are still edges in the graph, it means there is a cycle
        for (int i = 0; i < 26; i++) {
            if (indegree[i] > 0) {
                return "";
            }
        }

        return result;
    }
};

/*
// Another DFS solution

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> indegree;

        // Step 1: Build the graph and calculate indegrees
        for (string& word : words) {
            for (char c : word) {
                indegree[c] = 0;
            }
        }

        for (int i = 1; i < words.size(); i++) {
            string prevWord = words[i - 1];
            string currWord = words[i];
            int len = min(prevWord.length(), currWord.length());

            for (int j = 0; j < len; j++) {
                char prevChar = prevWord[j];
                char currChar = currWord[j];

                if (prevChar != currChar) {
                    graph[prevChar].push_back(currChar);
                    indegree[currChar]++;
                    break;
                }
            }
        }

        // Step 2: Perform topological sorting using DFS
        string result;
        stack<char> st;

        for (const auto& entry : indegree) {
            if (entry.second == 0) {
                st.push(entry.first);
            }
        }

        while (!st.empty()) {
            char curr = st.top();
            st.pop();
            result += curr;

            for (char next : graph[curr]) {
                if (--indegree[next] == 0) {
                    st.push(next);
                }
            }
        }

        return result.size() == indegree.size() ? result : "";
    }
};
*/

/*
// BFS Solution

class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<vector<bool>> adjList(26, vector<bool>(26, false));
        vector<int> indegree(26, -1);

        // Step 1: Build the adjacency list and calculate indegrees
        buildGraph(words, adjList, indegree);

        // Step 2: Perform topological sorting using BFS
        string result = topologicalSort(adjList, indegree);

        return result;
    }

private:
    // Helper function to build the adjacency list and calculate indegrees
    void buildGraph(vector<string>& words, vector<vector<bool>>& adjList, vector<int>& indegree) {
        // Initialize the indegree for all characters
        for (string& word : words) {
            for (char c : word) {
                indegree[c - 'a'] = 0;
            }
        }

        // Compare adjacent words to build the adjacency list and update indegrees
        for (int i = 1; i < words.size(); i++) {
            string prevWord = words[i - 1];
            string currWord = words[i];
            int len = min(prevWord.length(), currWord.length());

            for (int j = 0; j < len; j++) {
                char prevChar = prevWord[j];
                char currChar = currWord[j];

                if (prevChar != currChar) {
                    if (!adjList[prevChar - 'a'][currChar - 'a']) {
                        adjList[prevChar - 'a'][currChar - 'a'] = true;
                        indegree[currChar - 'a']++;
                    }
                    break;
                }
            }
        }
    }

    // Helper function for topological sorting using BFS
    string topologicalSort(vector<vector<bool>>& adjList, vector<int>& indegree) {
        string result = "";

        queue<char> q;
        // Add characters with indegree 0 to the queue
        for (int i = 0; i < 26; i++) {
            if (indegree[i] == 0) {
                q.push('a' + i);
            }
        }

        // Perform BFS to get the topological ordering
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            result += curr;

            for (int i = 0; i < 26; i++) {
                if (adjList[curr - 'a'][i]) {
                    indegree[i]--;
                    if (indegree[i] == 0) {
                        q.push('a' + i);
                    }
                }
            }
        }

        // If there are still edges in the graph, it means there is a cycle
        if (result.length() != 26) {
            return "";
        }

        return result;
    }
};
*/