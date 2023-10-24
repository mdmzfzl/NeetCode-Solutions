/*
Problem: LeetCode 261 - Graph Valid Tree

Key Idea:
The key idea is to check whether the given undirected graph forms a valid tree. A valid tree has two properties:
1. It has n - 1 edges, where n is the number of nodes.
2. It is a connected graph, meaning all nodes are reachable from any node.

Approach:
1. Build an adjacency list representation of the undirected graph.
2. Initialize a set to keep track of visited nodes.
3. Perform a Depth-First Search (DFS) starting from node 0.
4. During DFS, check if we encounter any visited node that is not the parent of the current node (to avoid cycles).
5. After DFS, check if all nodes are visited. If not, return false (not connected).
6. Finally, check if the number of edges is n - 1. If true, return true; otherwise, return false.

Time Complexity:
O(V + E), where V is the number of nodes (vertices) and E is the number of edges in the graph.

Space Complexity:
O(V + E) for the adjacency list and visited set.
*/

impl Solution {
    pub fn valid_tree(n: i32, edges: Vec<Vec<i32>>) -> bool {
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

        // Perform DFS to check connectivity
        if !Self::dfs(0, &mut visited, &graph, n, -1) {
            return false;
        }

        // Check if all nodes are visited
        if visited.iter().all(|&v| v) {
            return edges.len() == n - 1;
        }

        false
    }

    fn dfs(
        node: usize,
        visited: &mut Vec<bool>,
        graph: &Vec<Vec<usize>>,
        n: usize,
        parent: i32,
    ) -> bool {
        visited[node] = true;

        for &neighbor in graph[node].iter() {
            if !visited[neighbor] {
                if !Self::dfs(neighbor, visited, graph, n, node as i32) {
                    return false;
                }
            } else if neighbor as i32 != parent {
                return false;
            }
        }

        true
    }
}
