/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

/*
So the basic idea is to start from the root or any arbitrary node and mark the node and move to the adjacent unmarked node and continue this loop until there is no unmarked adjacent node. 
Then backtrack and check for other unmarked nodes and traverse them. Finally, print the nodes in the path.
So we are using HashMap to put all the visited node or old node there with clone one to.
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) 
            return NULL;
        
        for(int i = 0; i < 101; i++) 
            M[i] = NULL;

        DFS(node);
        return M[1];
    }

private:
    Node* M[101];     // Since values cant exceed 100 and are all unique

    void DFS(Node* current) {
        M[current->val] = new Node(current->val);

        for(auto i: current->neighbors) {
            // If it doest exist
            if(M[i->val] == NULL)
                DFS(i);
            
            // Adding M[i->val] to list of neighbours of M[current->val]
            M[current->val]->neighbors.emplace_back(M[i->val]);
            // emplace_back is like push_back
        }
    }
};

/*
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) 
            return NULL;
        DFS(node);
        return M[node];
    }

private:
    unordered_map<Node*, Node*> M;

    void DFS(Node* node){
        Node *copy = new Node(node->val);

        // Marked it as visited as it is present in our hashmap now we have to check for its neighbours 
        M[node] = copy; 

        for(auto adj:node->neighbors) 
            // we iterate through the neighbours and push it into the neighbours of the copy node,
            // also if the neighbours is not visited, we call dfs recursively on that adj neighbour
            if(M.find(adj) != M.end())
                // we are pushing it by it's value in original copy
                copy->neighbors.push_back(M[adj]);

            else {
                DFS(adj);
                copy->neighbors.push_back(M[adj]);
            }
    }
};
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

/*
class Solution {
public:
    unordered_map<Node*,Node*>mp;
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        Node* head=new Node(node->val);
        mp[node]=head;
        for (auto i:node->neighbors){
            if (mp.count(i)) head->neighbors.push_back(mp[i]);
            else
                head->neighbors.push_back(cloneGraph(i));
        }
        return head;
    }
};
*/