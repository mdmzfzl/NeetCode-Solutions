/*
Problem: LeetCode 332 - Reconstruct Itinerary

Key Idea:
The key idea is to treat the given list of tickets as a directed graph, where each airport is a node, and the tickets represent directed edges. We need to find an itinerary that starts from "JFK" and visits all airports once while minimizing the lexicographical order.

Approach:
1. Build a graph using a HashMap with airport codes as keys and a BinaryHeap (min heap) containing Reverse references to destination airports.
2. Create a vector to store the final itinerary.
3. Start with "JFK" as the initial airport and use a stack to perform a Depth-First Search (DFS).
4. While the stack is not empty:
   - If there are destinations available for the current airport:
     - Pop the smallest destination airport from the BinaryHeap.
     - Push the destination airport onto the stack.
   - If there are no destinations available:
     - Pop the airport from the stack and add it to the final itinerary.
5. Reverse the final itinerary vector to obtain the correct order.

Time Complexity:
- O(E * log E), where E is the number of edges (tickets).
- Building the adjacency list takes O(E) time.
- For each airport, we perform a log E operation when popping from the BinaryHeap.

Space Complexity:
- O(E) for the adjacency list and the final itinerary.
*/

use std::cmp::Reverse;
use std::collections::{BinaryHeap, HashMap};

impl Solution {
    pub fn find_itinerary(tickets: Vec<Vec<String>>) -> Vec<String> {
        let mut graph: HashMap<&str, BinaryHeap<Reverse<&str>>> = HashMap::new();

        // Build the graph.
        for ticket in &tickets {
            graph
                .entry(&ticket[0])
                .or_insert(BinaryHeap::new())
                .push(Reverse(&ticket[1]));
        }

        let mut itinerary: Vec<String> = Vec::with_capacity(tickets.len() + 1);
        let mut stack: Vec<&str> = vec!["JFK"];

        while let Some(src) = stack.last().cloned() {
            if let Some(dsts) = graph.get_mut(src) {
                if let Some(dst) = dsts.pop() {
                    stack.push(dst.0);
                    continue;
                }
            }

            if let Some(last) = stack.pop() {
                itinerary.push(last.to_string());
            }
        }

        itinerary.reverse();
        itinerary
    }
}
