/*
Problem: LeetCode 323 - Number of Connected Components in an Undirected Graph

Key Idea:
The key idea is to use Depth-First Search (DFS) to find connected components in the undirected graph. We count the number of times we perform DFS as the number of connected components.

Approach:
1. Build an adjacency list representation of the undirected graph.
2. Initialize a set to keep track of visited nodes.
3. Initialize a variable `num_components` to count the number of connected components.
4. Iterate through all nodes (0 to n-1):
   - If the node is not in the visited set:
     - Perform DFS starting from this node.
     - Increment `num_components` by 1 after each DFS call.
5. Return `num_components` as the result.

Time Complexity:
O(V + E), where V is the number of nodes (vertices) and E is the number of edges in the graph.

Space Complexity:
O(V + E) for the adjacency list and the visited set.
*/

impl Solution {
    pub fn count_components(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        let n = n as usize;
        let mut graph: Vec<Vec<usize>> = vec![vec![]; n];

        // Build the adjacency list
        for edge in edges.iter() {
            let u = edge[0] as usize;
            let v = edge[1] as usize;
            graph[u].push(v);
            graph[v].push(u);
        }

        let mut visited: Vec<bool> = vec![false; n];
        let mut num_components = 0;

        // Perform DFS to find connected components
        for node in 0..n {
            if !visited[node] {
                Self::dfs(node, &mut visited, &graph);
                num_components += 1;
            }
        }

        num_components
    }

    fn dfs(node: usize, visited: &mut Vec<bool>, graph: &Vec<Vec<usize>>) {
        visited[node] = true;

        for &neighbor in graph[node].iter() {
            if !visited[neighbor] {
                Self::dfs(neighbor, visited, graph);
            }
        }
    }
}
