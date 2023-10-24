/*
Problem: LeetCode 787 - Cheapest Flights Within K Stops

Key Idea:
The key idea is to use a modified form of Dijkstra's algorithm to find the cheapest price from the source to the destination while considering the maximum number of stops.

Approach:
1. Create an adjacency list representation of the graph where each node is an airport, and each edge is a flight with its cost. You can use a vector of vectors for this purpose. The index of the outer vector represents the airport, and each inner vector contains pairs (to, price) representing flights from that airport.
2. Initialize a vector stops to keep track of the minimum number of stops required to reach each airport from the source
3. Initialize all elements to i32::MAX initially, except for the source airport, which should be set to 0.
4. Initialize a priority queue (min-heap) min_heap to store tuples (total_price, airport, stops) in reverse order of total_price (i.e., lowest total_price comes first).
5. Push a tuple (0, src, 0) onto the min_heap, where 0 is the total price, src is the source airport, and 0 is the number of stops.
6. Explore Nodes in Priority Queue:
  - While the min_heap is not empty:
      - Pop the tuple (total_price, from, steps) from the min_heap in reverse order.
          - If steps exceeds k or if from is equal to dst, return total_price as the answer.
          - Otherwise, update stops[from] with steps if steps is smaller than the current value.
          - For each flight (to, price) from from to other airports:
              - Calculate the new_total_price as total_price + price.
              - Push the tuple (new_total_price, to, steps + 1) onto the min_heap.
7. If no valid path is found after exploring all nodes, return -1.

Time Complexity:
O(E + V * log(V)), where E is the number of flights (edges) and V is the number of airports (nodes). The use of a priority queue ensures that we explore nodes in order of increasing total_price.

Space Complexity:
O(V), for stops vector and the min_heap.
*/

use std::cmp::Reverse;
use std::collections::BinaryHeap;

impl Solution {
    pub fn find_cheapest_price(n: i32, flights: Vec<Vec<i32>>, src: i32, dst: i32, k: i32) -> i32 {
        let mut graph = vec![vec![]; n as usize];
        for flight in &flights {
            let (from, to, price) = (flight[0] as usize, flight[1] as usize, flight[2]);
            graph[from].push((to, price));
        }

        let mut stops = vec![i32::MAX; n as usize];

        let mut min_heap = BinaryHeap::new();
        min_heap.push(Reverse((0, src as usize, 0)));

        while !min_heap.is_empty() {
            let Reverse((total_price, from, steps)) = min_heap.pop().unwrap();

            if steps > stops[from] || steps > k + 1 {
                continue;
            }
            if from as i32 == dst {
                return total_price;
            }

            stops[from] = steps;
            for &(to, price) in &graph[from] {
                min_heap.push(Reverse((total_price + price, to, steps + 1)));
            }
        }

        -1
    }
}
