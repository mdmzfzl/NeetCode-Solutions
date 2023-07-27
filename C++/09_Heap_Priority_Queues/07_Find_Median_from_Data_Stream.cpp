/*
Problem: LeetCode 295 - Find Median from Data Stream

Description:
Design a data structure that supports adding integers to the structure and finding the median of the current elements.
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the average of the two middle values.

Intuition:
To efficiently find the median of a data stream, we can use two heaps: a max-heap to store the smaller half of the elements, and a min-heap to store the larger half of the elements.
The median will either be the root of the max-heap (if the heaps have equal size) or the average of the roots of both heaps (if the max-heap has one more element than the min-heap).

Approach:
1. Use two priority_queues (heaps) - a max-heap (`maxHeap`) and a min-heap (`minHeap`).
   - The max-heap (`maxHeap`) stores the smaller half of the elements.
   - The min-heap (`minHeap`) stores the larger half of the elements.
2. Maintain the following conditions:
   - The size of the max-heap is either equal to or one more than the size of the min-heap.
   - The root of the max-heap is smaller than or equal to the root of the min-heap.
3. When adding a new element:
   - If the max-heap is empty or the element is less than the root of the max-heap, push the element into the max-heap.
   - Otherwise, push the element into the min-heap.
   - Balance the heaps by moving the root of the max-heap to the min-heap if the sizes are not balanced.
4. To find the median:
   - If the size of the max-heap is greater than the min-heap, return the root of the max-heap.
   - Otherwise, return the average of the roots of both heaps.

Time Complexity:
Adding an element and finding the median both have a time complexity of O(log n), where n is the number of elements in the data stream. This is due to the heap operations.

Space Complexity:
The space complexity is O(n), where n is the number of elements in the data stream. This is because we store the elements in the heaps.
*/

class MedianFinder {
  private:
    priority_queue<int> maxHeap;  // Max-heap to store the smaller half of the elements
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Min-heap to store the larger half of the elements

  public:
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};