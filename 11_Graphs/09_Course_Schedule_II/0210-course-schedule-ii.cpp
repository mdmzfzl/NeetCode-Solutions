/*
Problem: LeetCode 210 - Course Schedule II

Description:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

Intuition:
This problem can be approached as a graph problem where the courses represent nodes and the prerequisites represent directed edges. To determine the ordering of courses, we can use the topological sorting algorithm. If there is a cycle in the graph, it means there is a dependency loop, and we cannot finish all the courses.

Approach:
1. Build an adjacency list representation of the graph using the prerequisites.
2. Initialize an array to store the in-degree of each course. In-degree represents the number of prerequisites for each course.
3. Create a queue and enqueue all the courses with an in-degree of 0.
4. Perform a topological sorting:
   - While the queue is not empty, dequeue a course:
     - Decrement the in-degree of its neighbors by 1.
     - If any neighbor has an in-degree of 0, enqueue it.
     - Add the dequeued course to the result list.
5. If all the courses have been visited, return the result list. Otherwise, return an empty array.

Time Complexity:
The time complexity is O(V + E), where V is the number of courses (nodes) and E is the number of prerequisites (edges). We visit each course and prerequisite once.

Space Complexity:
The space complexity is O(V + E), where V is the number of courses (nodes) and E is the number of prerequisites (edges). This is the space used for the adjacency list, the in-degree array, the queue, and the result list.
*/

class Solution {
  public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph(numCourses);   // Adjacency list representation of the graph
        vector<int> inDegree(numCourses, 0);      // In-degree of each course
        vector<int> result;                       // Result list of the course order

        // Build the graph and calculate the in-degree of each course
        for (const auto &prerequisite : prerequisites) {
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
            result.push_back(course);   // Add the course to the result list

            // Decrement the in-degree of neighbors and enqueue if their in-degree becomes 0
            for (const auto &neighbor : graph[course]) {
                if (--inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If all the courses have been visited, return the result list
        if (result.size() == numCourses) {
            return result;
        }

        return {};   // Return an empty array if it is impossible to finish all courses
    }
};