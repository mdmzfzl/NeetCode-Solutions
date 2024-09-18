public class Solution {
    public int[] TopKFrequent(int[] nums, int k) {
        var frequencyMap = new Dictionary<int, int>();
        foreach (int num in nums) {
            if (!frequencyMap.ContainsKey(num)) {
                frequencyMap[num] = 0;
            }
            frequencyMap[num]++;
        }

        // The PriorityQueue uses frequency as priority (lower frequency = higher priority to dequeue)
        var minHeap = new PriorityQueue<int, int>();
        foreach (var (num, freq) in frequencyMap) {
            minHeap.Enqueue(num, freq);

            // Maintain only k elements in the heap
            if (minHeap.Count > k) {
                minHeap.Dequeue();
            }
        }

        var result = new int[k];
        for (int i = k - 1; i >= 0; i--) {
            result[i] = minHeap.Dequeue();
        }
        return result;
    }
}
