/*
Problem: LeetCode 1584 - Minimum Cost to Connect All Points

Key Idea:
The key idea is to treat the given points as nodes in a graph, where the edges represent the distance between points. To minimize the cost of connecting all points, we can use Kruskal's algorithm, a greedy algorithm for finding the minimum spanning tree (MST) of a graph.

Approach:
1. Create a vector to store all edges, where each edge is a tuple of (distance, point1, point2).
2. Sort the edges in ascending order based on distance.
3. Initialize a vector "parent" to keep track of the parent node for each point in the graph. Initially, each point is its own parent.
4. Initialize variables "min_cost" to keep track of the minimum cost and "num_connected" to keep track of the number of connected components (initially equal to the number of points).
5. Iterate through the sorted edges:
   - For each edge (distance, point1, point2):
     - Check if point1 and point2 belong to different connected components. If they do, merge the components by updating their parent pointers.
     - Add the distance to "min_cost."
     - Decrement "num_connected" by 1.
     - If "num_connected" becomes 1, all points are connected, and we can break from the loop.
6. Return "min_cost" as the minimum cost to connect all points.

Time Complexity:
O(E * log E), where E is the number of edges (combinations of points). Sorting the edges takes O(E * log E) time, and the iteration through edges also takes O(E * log E) time in the worst case.

Space Complexity:
O(N), where N is the number of points. This is used for the "parent" vector.
*/

impl Solution {
    pub fn min_cost_connect_points(points: Vec<Vec<i32>>) -> i32 {
        fn find_parent(point: usize, parent: &mut Vec<usize>) -> usize {
            if parent[point] != point {
                parent[point] = find_parent(parent[point], parent);
            }
            parent[point]
        }

        let n = points.len();
        let mut edges: Vec<(i32, usize, usize)> = Vec::new();

        for i in 0..n {
            for j in (i + 1)..n {
                let distance =
                    (points[i][0] - points[j][0]).abs() + (points[i][1] - points[j][1]).abs();
                edges.push((distance, i, j));
            }
        }

        edges.sort_by_key(|edge| edge.0);
        let mut parent: Vec<usize> = (0..n).collect();
        let mut min_cost = 0;
        let mut num_connected = n;

        for edge in edges {
            let parent1 = find_parent(edge.1, &mut parent);
            let parent2 = find_parent(edge.2, &mut parent);

            if parent1 != parent2 {
                parent[parent1] = parent2;
                min_cost += edge.0;
                num_connected -= 1;

                if num_connected == 1 {
                    break;
                }
            }
        }

        min_cost
    }
}

/*
impl Solution {
    pub fn min_cost_connect_points(points: Vec<Vec<i32>>) -> i32 {
        let points = points.into_iter().map(|p| (p[0], p[1])).collect::<Vec<_>>();
        let n = points.len();

        let mut connected = vec![false; n];
        let mut distances = vec![i32::MAX; n];

        let mut min_index = 0;
        let mut min_cost = 0;

        let mut total_cost = 0;

        for _ in 0..n {
            connected[min_index] = true;
            total_cost += min_cost;

            let current_point = points[min_index];
            min_cost = i32::MAX;

            for (idx, point) in points.iter().enumerate() {
                if !connected[idx] {
                    let distance = (current_point.0 - point.0).abs() + (current_point.1 - point.1).abs();
                    distances[idx] = distances[idx].min(distance);

                    if distances[idx] < min_cost {
                        min_cost = distances[idx];
                        min_index = idx;
                    }
                }
            }
        }

        total_cost
    }
}
*/
