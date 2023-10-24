/*
Problem: LeetCode 207 - Course Schedule

Key Idea:
The key idea is to use a directed graph to represent the prerequisites as edges between courses. If there is a cycle in the graph, it means it's impossible to complete all courses.

Approach:
1. Create an adjacency list representation of the directed graph.
2. Initialize an array to keep track of the in-degrees (number of prerequisites) for each course.
3. Initialize a queue and enqueue all courses with no prerequisites (in-degree = 0).
4. While the queue is not empty:
   - Dequeue a course.
   - Decrement the in-degrees of its neighbors (courses that depend on it).
   - If a neighbor's in-degree becomes 0, enqueue it.
   - Increment a counter to track the number of courses taken.
5. If the counter equals the total number of courses, it means all courses can be taken, and we return true.
6. Otherwise, return false (there is a cycle in the graph).

Time Complexity:
O(V + E), where V is the number of courses (vertices) and E is the number of prerequisites (edges). We visit each vertex and each edge once.

Space Complexity:
O(V + E) for the adjacency list and in-degrees.
*/

impl Solution {
    pub fn can_finish(num_courses: i32, prerequisites: Vec<Vec<i32>>) -> bool {
        let mut graph: Vec<Vec<i32>> = vec![vec![]; num_courses as usize];
        let mut in_degrees: Vec<i32> = vec![0; num_courses as usize];

        // Build the directed graph and in-degrees
        for prerequisite in prerequisites.iter() {
            let course = prerequisite[0] as usize;
            let prereq = prerequisite[1] as usize;
            graph[prereq].push(course as i32);
            in_degrees[course as usize] += 1;
        }

        let mut queue: std::collections::VecDeque<i32> = std::collections::VecDeque::new();
        let mut courses_taken = 0;

        // Enqueue courses with no prerequisites
        for (course, &in_degree) in in_degrees.iter().enumerate() {
            if in_degree == 0 {
                queue.push_back(course as i32);
                courses_taken += 1;
            }
        }

        while let Some(course) = queue.pop_front() {
            for &next_course in graph[course as usize].iter() {
                in_degrees[next_course as usize] -= 1;
                if in_degrees[next_course as usize] == 0 {
                    queue.push_back(next_course);
                    courses_taken += 1;
                }
            }
        }

        courses_taken == num_courses
    }
}
