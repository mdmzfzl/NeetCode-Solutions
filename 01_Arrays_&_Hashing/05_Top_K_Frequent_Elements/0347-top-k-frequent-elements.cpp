/*
Problem: LeetCode 347 - Top K Frequent Elements

Description:
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Intuition:
To find the k most frequent elements, we can utilize a combination of a hash map and bucket sort. By counting the frequencies of elements using the hash map and using bucket sort to group elements by their frequencies, we can efficiently find the k most frequent elements.

Approach:
1. Initialize an empty hash map, m, to store the frequencies of elements.
2. Iterate through each element num in the input array nums:
    - Increment the frequency count of num in the hash map.
3. Create a vector of vectors, buckets, to act as buckets for grouping elements based on their frequencies.
4. Iterate through the key-value pairs in the hash map:
    - Place each key (element) in the corresponding bucket based on its frequency.
5. Create an empty vector, result, to store the k most frequent elements.
6. Iterate from the highest bucket index down to 0:
    - If the result vector size reaches k, break the loop.
    - If the current bucket is not empty, append its elements to the result vector.
7. Return the result vector, which represents the k most frequent elements.

Time Complexity:
The time complexity of this approach is O(n), where n is the size of the input array nums. This is because we iterate through the array once to count the frequencies and place elements in the buckets.

Space Complexity:
The space complexity is O(n), as we store the frequencies of elements in the hash map and the bucket vectors.
*/

class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;

        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }

        vector<vector<int>> buckets(n + 1);

        for (auto it = m.begin(); it != m.end(); it++) {
            buckets[it->second].push_back(it->first);
        }

        vector<int> result;

        for (int i = n; i >= 0; i--) {
            if (result.size() >= k) {
                break;
            }

            if (!buckets[i].empty()) {
                result.insert(result.end(), buckets[i].begin(), buckets[i].end());
            }
        }

        return result;
    }
};

/*
! Using Priority Queue
Problem: LeetCode 347 - Top K Frequent Elements

Description:
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Intuition:
To find the k most frequent elements, we can utilize a combination of a hash map and a priority queue (min-heap). By counting the frequencies of elements using the hash map and maintaining a min-heap of size k, we can efficiently find the k most frequent elements.

Approach:
1. Initialize an empty hash map to store the frequencies of elements.
2. Iterate through each element num in the input array nums:
    - Increment the frequency count of num in the hash map.
3. Initialize a min-heap to store the k most frequent elements based on their frequencies.
4. Iterate through the elements and frequencies in the hash map:
    - Push the current element into the min-heap.
    - If the size of the min-heap exceeds k, remove the smallest element (with the lowest frequency).
5. Return the elements in the min-heap, which represent the k most frequent elements.

Time Complexity:
The time complexity of this approach is O(n log k), where n is the size of the input array nums.
This is because we iterate through the array once to count the frequencies and perform log k operations for each element insertion and removal in the min-heap.

Space Complexity:
The space complexity is O(n), as we store the frequencies of elements in the hash map and the k most frequent elements in the min-heap.
*/
/*
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (auto& kvp : freqMap) {
            minHeap.push({kvp.second, kvp.first});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};
*/

// ! O(n log n) solution
/*
class Solution {
public:
    // Approach - First make a frequency map normally, then insert key value pairs(frequency first, value second) in vector and sort in descending order
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> M;
        vector< pair<int, int> > arr;
        vector<int> result;

        for(int i = 0; i < nums.size(); i++) {
            // it reaches end of map if it didn't find the element
            if(M.find(nums[i]) == M.end())
                M[nums[i]] = 1;
            else
                M[nums[i]]++;
        }

        for(auto i : M) {
            arr.push_back( make_pair(i.second, i.first) );
        }

        sort(arr.rbegin(), arr.rend());

        for(int i = 0; i < k; i++) {
            result.push_back(arr[i].second);
        }
        return result;
    }
};
*/