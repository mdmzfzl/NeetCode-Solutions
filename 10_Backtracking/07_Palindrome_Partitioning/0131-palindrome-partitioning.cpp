/*
Problem: LeetCode 131 - Palindrome Partitioning

Description:
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
A palindrome string is a string that reads the same backward as forward.

Intuition:
To find all possible palindrome partitioning of a given string, we can use a backtracking approach. The idea is to generate all possible partitions by trying out different substrings at each step.
We check if the current substring is a palindrome and continue the search for the remaining part of the string. By backtracking, we generate all valid palindrome partitionings.

Approach:
1. Initialize an empty vector `partition` to store the current partition.
2. Initialize an empty vector `result` to store all valid partitions.
3. Define a helper function `backtrack`:
   - If the start index is equal to the length of the string, add the current partition to the `result` vector.
   - Otherwise:
     - Iterate through the substring starting from the current index:
       - If the substring is a palindrome:
         - Include the substring in the partition.
         - Recursively call `backtrack` with the updated start index (next index after the substring).
         - Exclude the substring from the partition (backtrack).
4. Call the `backtrack` function with the initial start index of 0.
5. Return the `result` vector containing all valid partitions.

Time Complexity:
The time complexity is O(N * 2^N), where N is the length of the string `s`. This is because there can be up to 2^N possible palindrome partitions, and for each partition, we check if each substring is a palindrome.

Space Complexity:
The space complexity is O(N) for the recursion stack, where N is the length of the string `s`. The `result` vector may contain multiple partitions, but the overall space complexity is dominated by the recursion stack.
*/

class Solution {
  public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> partition;
        backtrack(s, 0, partition, result);  // Call the backtrack function to generate all valid partitions
        return result;
    }

  private:
    // Depth First Search
    void backtrack(const string &s, int start, vector<string> &partition, vector<vector<string>> &result) {
        if (start == s.length()) {
            result.push_back(partition);  // Add the current partition to the result
            return;
        }

        for (int i = start; i < s.length(); ++i) {
            if (isPalindrome(s, start, i)) {  // Check if the substring is a palindrome
                partition.push_back(s.substr(start, i - start + 1));  // Include the palindrome substring in the partition
                backtrack(s, i + 1, partition, result);  // Recursively call with the next index
                partition.pop_back();  // Exclude the last added substring (backtrack)
            }
        }
    }

    bool isPalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {  // If characters don't match, it's not a palindrome
                return false;
            }

            ++start;
            --end;
        }

        return true;  // All characters matched, it's a palindrome
    }
};