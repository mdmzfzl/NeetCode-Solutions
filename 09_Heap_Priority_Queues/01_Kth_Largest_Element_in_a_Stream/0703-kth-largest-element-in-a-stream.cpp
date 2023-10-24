/*
Problem: LeetCode 703 - Kth Largest Element in a Stream

Description:
Design a class to find the kth largest element in a stream.
Note that it is the kth largest element in the sorted order, not the kth distinct element.

Intuition:
To find the kth largest element in a stream efficiently, we can use a min-heap of size k.
As new elements are added to the stream, we compare them with the root of the min-heap.
If the new element is larger than the root, we replace the root with the new element and perform heapify to maintain the heap property.

Approach:
1. Implement a class KthLargest with the following members:
   - A min-heap to store the k largest elements. Use a priority_queue in C++ with the smallest element on top.
   - A variable k to store the value of k.

2. In the constructor of KthLargest:
   - Initialize the variable k.
   - Iterate through the given vector of integers and add each element to the min-heap.
   - If the size of the min-heap exceeds k, remove the smallest element from the heap.

3. In the add function:
   - If the size of the min-heap is less than k, simply add the new element to the heap.
   - If the new element is larger than the root of the min-heap, replace the root with the new element and perform heapify.
   - Return the value of the root of the min-heap, which represents the kth largest element.

Time Complexity:
- Construction: O(n*log(k)), where n is the number of elements in the input vector.
- Adding an element: O(log(k)), as we need to perform heapify after adding an element.

Space Complexity:
- The space complexity is O(k), as we store the k largest elements in the min-heap.
*/

// static int pr = []() {
//     std::ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     return 0;
// }();

class KthLargest {
  private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap to store the k largest elements

  public:
    KthLargest(int k, vector<int> &nums) {
        this->k = k;

        for (int num : nums) {
            minHeap.push(num);

            // removing elements till k elements remain
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }

    int add(int val) {
        minHeap.push(val);

        if (minHeap.size() > k) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};
