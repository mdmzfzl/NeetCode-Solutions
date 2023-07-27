/*
Problem: LeetCode 763 - Partition Labels

Description:
Given a string s, partition s such that every substring in the partition is a palindrome.
Return a list of integers representing the length of each partition.

Intuition:
To partition the string into palindromic substrings, we need to find the last occurrence of each character in the string.
If we know the last index of each character in the string, we can use that information to determine the boundaries of each partition.
We can do this by iterating through the string and keeping track of the maximum index of each character encountered so far.

Approach:
1. Create a hash map to store the last index of each character in the string.
2. Initialize two variables `start` and `end` to 0, which will represent the current partition's start and end.
3. Initialize an empty vector `result` to store the lengths of each partition.
4. Iterate through the string.
5. For each character encountered, update its last index in the hash map.
6. If the current index equals the maximum index of the character found so far, it means we have reached the end of the current partition.
   - Add the length of the current partition to the `result` vector.
   - Update the `start` variable to the next index (i.e., the index immediately after the end of the current partition).
7. After iterating through the string, return the `result` vector.

Time Complexity:
The time complexity of this approach is O(n), where n is the length of the string.

Space Complexity:
The space complexity is O(1) as the size of the hash map is constant (26 characters).
*/

class Solution {
  public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastOccurrence;
        vector<int> result;
        int start = 0, end = 0;

        // Store the last occurrence of each character in the hash map
        for (int i = 0; i < s.length(); ++i) {
            lastOccurrence[s[i]] = i;
        }

        // Iterate through the string and find the boundaries of each partition
        for (int i = 0; i < s.length(); ++i) {
            end = max(end, lastOccurrence[s[i]]);

            // If we have reached the end of the current partition
            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return result;
    }
};