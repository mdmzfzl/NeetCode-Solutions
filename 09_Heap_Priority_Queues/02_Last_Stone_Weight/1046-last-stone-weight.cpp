/*
Problem: LeetCode 1046 - Last Stone Weight

Description:
You are given an array `stones` where `stones[i]` represents the weight of the ith stone.
In each turn, you choose the two heaviest stones and smash them together.
If the stones have the same weight, they both get destroyed, and if they have different weights, the heavier stone gets destroyed and the lighter stone's weight is reduced by the difference.
When only one stone remains, return its weight. If no stones remain, return 0.

Intuition:
To find the last stone weight, we can use a max-heap to keep track of the heaviest stones.
In each turn, we remove the two largest stones from the heap, calculate their difference, and add the result back to the heap.
We repeat this process until the heap contains only one stone.

Approach:
1. Implement a function `lastStoneWeight` that takes the input array `stones` as a parameter.
2. Create a max-heap using `priority_queue<int>` in C++ to store the stone weights. The largest element will always be at the top of the heap.
3. Populate the max-heap with the elements from the `stones` array.
4. While the heap has more than one stone:
   - Remove the two largest stones from the heap using `pop()`.
   - Calculate the difference between the two stones.
   - If the difference is non-zero, add it back to the heap using `push()`.
5. After the loop ends, the heap will contain only one stone.
   - If the heap is empty, return 0 as no stones remain.
   - If the heap is not empty, return the top element of the heap, which represents the last stone weight.

Time Complexity:
- Building the max-heap: O(n), where n is the number of elements in the input array.
- Performing heap operations: O(log(n)) per operation.
- Overall time complexity: O(n*log(n)), where n is the number of elements in the input array.

Space Complexity:
- The space complexity is O(n), where n is the number of elements in the input array, for storing the max-heap.
*/

class Solution {
  public:
    int lastStoneWeight(vector<int> &stones) {
        priority_queue<int> maxHeap; // Max-heap to store the stone weights

        // Populate the max-heap with the elements from the 'stones' array
        for (int stone : stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size() > 1) {
            int stone1 = maxHeap.top(); // Get the heaviest stone
            maxHeap.pop();
            int stone2 = maxHeap.top(); // Get the second heaviest stone
            maxHeap.pop();
            int diff = stone1 - stone2; // Calculate the difference

            if (diff > 0) {
                maxHeap.push(diff); // Add the difference back to the heap
            }
        }

        if (maxHeap.empty()) {
            return 0; // No stones remain
        }

        return maxHeap.top(); // Return the last stone weight
    }
};