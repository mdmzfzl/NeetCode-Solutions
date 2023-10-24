/*
Problem: LeetCode 743 - Network Delay Time

Key Idea:
The key idea is to find the minimum time it takes for a signal to reach all nodes in a weighted directed graph. This problem can be solved using Dijkstra's algorithm, a greedy algorithm for finding the shortest path in a weighted graph.

Approach:
1. Create a vector "dist" to store the minimum time to reach each node from the source node (initialized with infinity for all nodes except the source).
2. Create a priority queue (min heap) to keep track of the next node to visit based on their estimated distances.
3. Start with the source node, set its distance to 0, and push it into the priority queue.
4. While the priority queue is not empty:
   - Pop the node with the smallest estimated distance from the priority queue.
   - If this node has been visited before, skip it.
   - For each neighbor of the current node:
     - Calculate the tentative distance to the neighbor through the current node.
     - If the tentative distance is smaller than the current distance stored in "dist," update the distance and push the neighbor into the priority queue.
5. After processing all nodes, check if any node has infinite distance. If so, it's not reachable, so return -1. Otherwise, return the maximum distance in "dist" as the answer.

Time Complexity:
O(N^2 + E * log E), where N is the number of nodes and E is the number of edges. In the worst case, Dijkstra's algorithm can have O(N^2) complexity if using a naive priority queue. Using a binary heap-based priority queue can optimize it to O(E * log E).

Space Complexity:
O(N + E), where N is the number of nodes for the "dist" vector, and E is the number of edges for the adjacency list.
*/

use std::collections::{BinaryHeap, HashMap};

impl Solution {
    pub fn network_delay_time(times: Vec<Vec<i32>>, n: i32, k: i32) -> i32 {
        // Create an adjacency list to represent the graph.
        let mut graph: HashMap<i32, Vec<(i32, i32)>> = HashMap::new();
        for time in &times {
            let (u, v, w) = (time[0], time[1], time[2]);
            graph.entry(u).or_insert(Vec::new()).push((v, w));
        }

        // Initialize distances with infinity, except for the source.
        let mut dist: Vec<i32> = vec![std::i32::MAX; n as usize];
        dist[k as usize - 1] = 0;

        // Create a min heap to store (distance, node) pairs.
        let mut min_heap: BinaryHeap<(i32, i32)> = BinaryHeap::new();
        min_heap.push((0, k));

        while let Some((d, u)) = min_heap.pop() {
            if d > dist[u as usize - 1] {
                continue;
            }
            if let Some(neighbors) = graph.get(&u) {
                for (v, w) in neighbors {
                    let new_dist = dist[u as usize - 1] + w;
                    if new_dist < dist[*v as usize - 1] {
                        dist[*v as usize - 1] = new_dist;
                        min_heap.push((new_dist, *v));
                    }
                }
            }
        }

        // Check if any node is unreachable.
        if dist.iter().any(|&d| d == std::i32::MAX) {
            return -1;
        }

        // Return the maximum distance in "dist."
        *dist.iter().max().unwrap()
    }
}
