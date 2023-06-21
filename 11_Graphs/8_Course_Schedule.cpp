/**
 * ? Approach - Using Topological sort
 * * 1. First we build an adjacency matrix for the given graph.
 * * 2. We create an array indegree and indegree[i] is the number of edges approaching a node.
 * * 3. If no node has indegree 0, then a cycle exists and we can definitely not finish all the courses.
 * * 4. If there's a node with indegree 0, we start with the node, we move to it's child nodes and keep on decrementing their indegrees.
 * * 5. If in the end, we're able to reach all nodes, that means we can finish all the courses, so we return true.
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
*/

class Solution {
public: 
    bool canFinish(int n, vector<vector<int>> &p) {
        if (p.size() == 0) 
            return true; //all courses independent

        vector<int> indegree(n, 0); //counts the number of edges approaching a particular node
        vector<vector<int>> graph(n); //adjacency matrix of the given graph
    
        for (auto & x: p) {
            graph[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }

        queue < int > q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i), indegree[i]--;
        }
        if (q.size() == 0) return false; //cycle exists if there is no node with indegree 0

        int count = 0; //No. of nodes you're able to reach till the end
        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                count++;
                for (auto child: graph[curr]) {
                    indegree[child]--; //decrement the indegree of the nodes until you've reached all nodes
                    if (indegree[child] == 0) q.push(child);
                }
            }
        }
        if (count == n) 
            return true;
        return false;
    }
};

/*
class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adjacency(numCourses);
    vector<bool> visited(numCourses);

    for (vector<int>& p : prerequisites) {
      if (p[0] == p[1]) return false;
      adjacency[p[0]].push_back(p[1]);
    }

    for (int course = 0; course < numCourses; course++) {
      if (!dfs(course, adjacency, visited)) return false;
    }

    return true;
  }

  bool dfs(int course, vector<vector<int>>& adjacency, vector<bool>& visited) {
    if (visited[course]) return false;

    visited[course] = true;

    vector<int>& prerequisites = adjacency[course];

    for (int i = prerequisites.size() - 1; i > -1; i--) {
      if (!dfs(prerequisites[i], adjacency, visited)) return false;
      prerequisites.pop_back();
    }

    visited[course] = false;

    return true;
  }
};
*/

/*
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n],ino(n,0);
        for(auto p : pre) {
            adj[p[0]].push_back(p[1]);
            ino[p[1]]++;
        }
        vector<int> topo;
        queue<int> q;
        for(int i=0;i<n;i++) {
            if(ino[i]==0) {
                q.push(i);
            } 
        }
        while(!q.empty()) {
            int f = q.front();q.pop();
            topo.push_back(f);
            for(auto k : adj[f]) {
                ino[k]--;
                if(ino[k]==0) q.push(k);
            }
        }
        return topo.size()==n;
    }
};
*/