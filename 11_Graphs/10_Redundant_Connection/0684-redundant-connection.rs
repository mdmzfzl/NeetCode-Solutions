/*
Problem: LeetCode 684 - Redundant Connection

Key Idea:
The key idea is to use a Union-Find (Disjoint Set Union) data structure to detect the redundant connection that forms a cycle in the given graph.

Approach:
1. Initialize a parent array where each node initially points to itself.
2. Iterate through the given edges:
   - For each edge (u, v), find the root nodes of u and v (representing their sets).
   - If the root nodes are the same, it means there is already a path from u to v, and adding this edge would create a cycle. This edge is the redundant connection.
   - Otherwise, union the two sets by updating the parent of one of the root nodes to point to the other.
3. Return the redundant connection edge.

Time Complexity:
O(n * α(n)), where n is the number of nodes, and α(n) is the inverse Ackermann function, which is very slow-growing. In practice, α(n) is close to a constant, so the time complexity is nearly linear.

Space Complexity:
O(n) for the parent array.
*/

impl Solution {
    pub fn find_redundant_connection(edges: Vec<Vec<i32>>) -> Vec<i32> {
        let n = edges.len();
        let mut parent: Vec<usize> = (0..n + 1).collect();

        fn find(mut x: usize, parent: &mut Vec<usize>) -> usize {
            while parent[x] != x {
                x = parent[x];
            }
            x
        }

        for edge in edges.iter() {
            let u = edge[0] as usize;
            let v = edge[1] as usize;

            let root_u = find(u, &mut parent);
            let root_v = find(v, &mut parent);

            if root_u == root_v {
                return edge.clone();
            } else {
                parent[root_u] = root_v;
            }
        }

        vec![]
    }
}
