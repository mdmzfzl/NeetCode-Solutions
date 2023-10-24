/*
Problem: LeetCode 210 - Course Schedule II

Key Idea:
The key idea is to use a directed graph to represent the prerequisites as edges between courses. We need to find an order in which all courses can be taken, or determine that it's impossible.

Approach:
1. Create an adjacency list representation of the directed graph.
2. Initialize an array to keep track of the in-degrees (number of prerequisites) for each course.
3. Initialize a queue and enqueue all courses with no prerequisites (in-degree = 0).
4. Initialize a result vector to store the order of courses taken.
5. While the queue is not empty:
   - Dequeue a course.
   - Append it to the result vector.
   - Decrement the in-degrees of its neighbors (courses that depend on it).
   - If a neighbor's in-degree becomes 0, enqueue it.
6. If the size of the result vector equals the total number of courses, return it (all courses can be taken).
7. Otherwise, return an empty vector (impossible to complete all courses).

Time Complexity:
O(V + E), where V is the number of courses (vertices) and E is the number of prerequisites (edges). We visit each vertex and each edge once.

Space Complexity:
O(V + E) for the adjacency list, in-degrees, queue, and result vector.
*/

impl Solution {
    pub fn find_order(num_courses: i32, prerequisites: Vec<Vec<i32>>) -> Vec<i32> {
        let num_courses = num_courses as usize;
        let mut graph: Vec<Vec<i32>> = vec![vec![]; num_courses];
        let mut in_degrees: Vec<i32> = vec![0; num_courses];

        // Build the directed graph and in-degrees
        for prerequisite in prerequisites.iter() {
            let course = prerequisite[0] as usize;
            let prereq = prerequisite[1] as usize;
            graph[prereq].push(course as i32);
            in_degrees[course as usize] += 1;
        }

        let mut queue: std::collections::VecDeque<i32> = std::collections::VecDeque::new();
        let mut result: Vec<i32> = Vec::new();

        // Enqueue courses with no prerequisites
        for (course, &in_degree) in in_degrees.iter().enumerate() {
            if in_degree == 0 {
                queue.push_back(course as i32);
                result.push(course as i32);
            }
        }

        while let Some(course) = queue.pop_front() {
            for &next_course in graph[course as usize].iter() {
                in_degrees[next_course as usize] -= 1;
                if in_degrees[next_course as usize] == 0 {
                    queue.push_back(next_course);
                    result.push(next_course);
                }
            }
        }

        if result.len() == num_courses {
            result
        } else {
            Vec::new()
        }
    }
}
