/*
Problem: LeetCode 207 - Course Schedule

Description:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Intuition:
This problem can be approached as a graph problem where the courses represent nodes and the prerequisites represent directed edges. To determine if it is possible to finish all courses, we need to check if there is a cycle in the graph. If there is a cycle, it means there is a dependency loop, and we cannot finish all the courses.

Approach:
1. Build an adjacency list representation of the graph using the prerequisites.
2. Initialize a visited array to track the visited nodes during the DFS traversal.
3. Iterate through each node in the graph and perform a DFS traversal to detect cycles:
   - If the current node is being visited, it means there is a cycle, so return false.
   - If the current node is not visited, perform a DFS traversal on its neighbors.
4. If no cycles are detected after the DFS traversal, return true.

Time Complexity:
The time complexity is O(V + E), where V is the number of courses (nodes) and E is the number of prerequisites (edges). We visit each course and prerequisite once.

Space Complexity:
The space complexity is O(V + E), where V is the number of courses (nodes) and E is the number of prerequisites (edges). This is the space used for the adjacency list and the visited array.
*/

class Solution {
  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph(numCourses);  // Adjacency list representation of the graph
        vector<int> visited(numCourses, 0);     // Visited array to track the visited nodes

        // Build the graph
        for (const auto &prerequisite : prerequisites) {
            int course = prerequisite[0];
            int prerequisiteCourse = prerequisite[1];
            graph[course].push_back(prerequisiteCourse);
        }

        // Perform a DFS traversal to detect cycles
        for (int course = 0; course < numCourses; ++course) {
            if (!dfs(course, graph, visited)) {
                return false;
            }
        }

        return true;
    }

  private:
    bool dfs(int course, vector<vector<int>> &graph, vector<int> &visited) {
        // If the current course is being visited, it means there is a cycle
        if (visited[course] == 1) {
            return false;
        }

        // If the current course is already visited, return true
        if (visited[course] == -1) {
            return true;
        }

        visited[course] = 1;  // Mark the current course as being visited

        // Perform a DFS traversal on the neighbors
        for (const auto &neighbor : graph[course]) {
            if (!dfs(neighbor, graph, visited)) {
                return false;
            }
        }

        visited[course] = -1;  // Mark the current course as visited
        return true;
    }
};

// Topological sort
// Same time and space complexity but this can be more efficient in terms of practical performance
/*
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);   // Adjacency list representation of the graph
        vector<int> inDegree(numCourses, 0);      // In-degree of each course

        // Build the graph and calculate the in-degree of each course
        for (const auto& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int prerequisiteCourse = prerequisite[1];
            graph[prerequisiteCourse].push_back(course);
            ++inDegree[course];
        }

        queue<int> q;   // Queue to store courses with in-degree 0

        // Enqueue courses with in-degree 0
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform topological sorting
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            --numCourses;    // Decrement the number of remaining courses

            // Decrement the in-degree of neighbors and enqueue if their in-degree becomes 0
            for (const auto& neighbor : graph[course]) {
                if (--inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return numCourses == 0;
    }
};
*/