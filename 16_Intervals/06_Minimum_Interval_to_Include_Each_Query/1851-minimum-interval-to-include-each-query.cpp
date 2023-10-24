/*
Problem: LeetCode 1851 - Minimum Interval to Include Each Query

Description:
You are given a 2D integer array intervals, where intervals[i] = [lefti, righti] describes the ith interval starting from lefti and ending at righti (inclusive). The size of the array is n and 1-indexed.

You are also given an integer array queries, where queries[j] = [leftj, rightj] describes the jth query starting from leftj and ending at rightj (inclusive). The size of the array is m and 1-indexed.

Find the minimum interval for each query such that it is completely covered by an interval in intervals and lci <= leftj <= rightj <= rci.

Return an integer array answer, where answer[j] is the minimum interval length for the jth query.

Intuition:
To solve this problem efficiently, we can use a two-step approach:
1. Sort both intervals and queries in ascending order based on their lengths.
2. Use a priority queue (min heap) to keep track of the right boundaries of the current intervals.

Approach:
1. Create two separate vectors of pairs: one for intervals and one for queries, where the first element of each pair represents the length of the interval/query, and the second element is the index of the interval/query in the original arrays.
2. Sort both vectors in ascending order based on their lengths.
3. Initialize a priority queue (min heap) to keep track of the right boundaries of the current intervals. We'll insert the intervals in the queue based on their right boundary.
4. Iterate through the sorted intervals:
   a. While the current query length is smaller or equal to the current interval length, update the result for the query and remove it from the priority queue.
5. Continue to process the next interval.
6. Return the answer vector containing the minimum interval lengths for each query.

Time Complexity:
The time complexity is O(n log n + m log m), where n is the number of intervals and m is the number of queries. Sorting both vectors of pairs takes O(n log n + m log m) time, and processing intervals and queries takes O(n + m log n) time.

Space Complexity:
The space complexity is O(n + m) to store the vectors of pairs and the priority queue.
*/

class Solution {
  public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries) {
        vector<int> sortedQueries = queries;
        // [size of interval, end of interval]
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // {query -> size of interval}
        unordered_map<int, int> m;
        // Also need only valid intervals, so sort by start time & sort queries
        sort(intervals.begin(), intervals.end());
        sort(sortedQueries.begin(), sortedQueries.end());
        vector<int> result;
        int i = 0;

        for (int j = 0; j < sortedQueries.size(); j++) {
            int query = sortedQueries[j];

            // Push intervals into the min heap whose start time is less than or equal to the current query value
            while (i < intervals.size() && intervals[i][0] <= query) {
                int left = intervals[i][0];
                int right = intervals[i][1];
                pq.push({right - left + 1, right});
                i++;
            }

            // Pop the invalid intervals from the min heap (intervals whose end time is less than the current query value)
            while (!pq.empty() && pq.top().second < query) {
                pq.pop();
            }

            // Store the minimum interval size for the current query in the unordered_map
            if (!pq.empty()) {
                m[query] = pq.top().first;
            } else {
                m[query] = -1;
            }
        }

        // Build the result vector using the unordered_map for each query
        for (int j = 0; j < queries.size(); j++) {
            result.push_back(m[queries[j]]);
        }

        return result;
    }
};