/*
Problem: LeetCode 49 - Group Anagrams

Description:
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

Intuition:
An anagram is a word formed by rearranging the letters of another word. To group anagrams together, we can utilize a hash map. By sorting each string and using the sorted string as a key in the hash map, we can efficiently group the anagrams.

Approach:
1. Initialize an empty hash map to store the groups of anagrams.
2. Iterate through each string str in the input array strs:
    - Sort the characters of str to create a sorted string.
    - If the sorted string is already present in the hash map, add str to its corresponding group.
    - Otherwise, create a new group in the hash map with the sorted string as the key and str as the initial value.
3. Return the values of the hash map, which represent the grouped anagrams.

Time Complexity:
The time complexity of this approach is O(n * k * log k), where n is the size of the input array strs and k is the maximum length of a string in strs.
This is because we iterate through the array and sort each string, which takes O(k * log k) time for each string.

Space Complexity:
The space complexity is O(n * k), as we store all the strings in the hash map, where n is the number of groups and k is the maximum length of a string.
*/

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        // To store the sorted string and all its anagrams
        unordered_map<string, vector<string>> M;

        /*
            Consider example 1 : strs = ["eat","tea","tan","ate","nat","bat"]
            After the below opeartion of for loop map will contain -
            aet -- eat, tea, ate
            ant -- tan, nat
            abt -- bat
        */
        for (int i = 0; i < strs.size(); i++) {
            string T = strs[i];
            sort(T.begin(), T.end());
            M[T].push_back(strs[i]);
        }

        // Now pushing all the anagrams(vector<string>) of one word, one by one, into result vector
        vector< vector<string> > result;

        for (auto i : M) {
            result.push_back(i.second);
        }

        return result;
    }
};