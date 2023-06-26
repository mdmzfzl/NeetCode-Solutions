/*
    All courses can be completed if there's no cycle, check for cycles

    Time: O(V + E)
    Space: O(V + E)
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        // build adjacency list of prereqs
        for (int i = 0; i < prerequisites.size(); i++) {
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        unordered_set<int> visit;
        unordered_set<int> cycle;
        
        vector<int> result;
        for (int course = 0; course < numCourses; course++) {
            if (!dfs(course, m, visit, cycle, result)) {
                return {};
            }
        }
        return result;
    }
private:
    // a course has 3 possible states:
    // visited -> course added to result
    // visiting -> course not added to result, but added to cycle
    // unvisited -> course not added to result or cycle
    bool dfs(int course, unordered_map<int, vector<int>>& m, unordered_set<int>& visit,
        unordered_set<int>& cycle, vector<int>& result) {
        
        if (cycle.find(course) != cycle.end()) {
            return false;
        }
        if (visit.find(course) != visit.end()) {
            return true;
        }
        cycle.insert(course);
        for (int i = 0; i < m[course].size(); i++) {
            int nextCourse = m[course][i];
            if (!dfs(nextCourse, m, visit, cycle, result)) {
                return false;
            }
        }
        cycle.erase(course);
        visit.insert(course);
        result.push_back(course);
        return true;
    }
};

/**
 * ? Approach - Topological sort using DFS
 * * 1. Initialize a 2D vector graph and result & inDegree vector, to help us in keeping track of whether a node is visited or not.
 * * 2. Start DFS from a course which has 0 prerequisites i.e the inDegree is 0 and mark it as visited.
 * * 3. After completion of a course, add the current course to our result. Since we added a course we will reduce the indegree for all the courses whose prerequisites was the current course.
 * * 4. If the indegree bof a course becomes 0, add them into DFS and start DFS call from that course.
 * * 5. Repeat the steps by calling dfs again for each course with indegree 0.
 * * 6. In the end, return result if it contains all numCourses i.e Check size of result. If size == numCourses, return result, else return []
*/
/*
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //Initializing a 2D graph, result and inDegree array
        vector<vector<int>> graph(numCourses);
        vector<int> result, inDegree(numCourses);
        
        // inDegree
        for(auto& prereq : prerequisites)
            graph[prereq[1]].push_back(prereq[0]),
            inDegree[prereq[0]]++;
        
        // DFS call
        function<void(int)> dfs = [&](int current) {
            // Adding the current course into the result 
            result.push_back(current);            
            // Marking the current course that we added as visited
            inDegree[current] = -1;                     
            
            // If any next course has a indegree of 0 i.e. if it has no prerequisites requirement than make dfs call for that course
            for(auto nextCourse : graph[current])          
                if(--inDegree[nextCourse] == 0)     
                    dfs(nextCourse);                
        };
        
        // If the indegree becomes 0 of a course then again add them into DFS and start DFS call from that course .
        for(int i = 0; i < numCourses; i++)
            if(inDegree[i] == 0) dfs(i);                   
        
        //In the end return `result` if it contains all `numCourses` else return  []
        if(size(result) == numCourses) return result;
        return {};
    }
};
*/