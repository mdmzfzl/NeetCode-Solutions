/*
Problem: LeetCode 3 - Longest Substring Without Repeating Characters

Description:
Given a string `s`, find the length of the longest substring without repeating characters.

Intuition:
To find the longest substring without repeating characters, we can use a sliding window approach.
We can maintain a window that contains unique characters and keep expanding it until we encounter a repeating character.
At each step, we update the maximum length of the non-repeating substring.

Approach:
1. Initialize variables `left` and `right` to represent the left and right pointers of the sliding window.
   - Set both `left` and `right` to 0 initially.
2. Initialize a variable `maxLen` to store the maximum length of the non-repeating substring.
3. Initialize a set or map to keep track of the unique characters in the window.
4. Iterate while `right` is less than the length of the string:
   - Check if the character at `right` is already present in the set/map:
     - If it is present, remove the character at `left` from the set/map and increment `left`.
     - If it is not present, add the character at `right` to the set/map, calculate the current length of the non-repeating substring as `right - left + 1`, and update `maxLen` if necessary.
   - Increment `right` to expand the window.
5. Return `maxLen`, which represents the length of the longest substring without repeating characters.

Time Complexity:
The time complexity is O(n), where n is the length of the input string. We iterate through the string once with the sliding window approach.

Space Complexity:
The space complexity is O(min(n, m)), where n is the length of the input string and m is the size of the character set.
In the worst case, the character set can be as large as the input string, but it can also be limited by the number of distinct characters.
*/

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int maxLen = 0;
        unordered_set<char> charSet;

        while (right < s.length()) {
            if (charSet.count(s[right])) {
                charSet.erase(s[left]);
                left++;
            } else {
                charSet.insert(s[right]);
                maxLen = max(maxLen, right - left + 1);
                right++;
            }
        }

        return maxLen;
    }
};

/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result= 0;
        unordered_set<char> chegg;
        int i = 0, j = 0;

        while(i < s.size()) {
            if(chegg.find(s[i]) == chegg.end()) {
                chegg.insert(s[i]);
                i++;
            }
            else{
                chegg.erase(s[j]);
                j++;
            }
            result = max(result, i-j );
        }
        return result;
    }
};
*/

/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        vector<int> M(256, -1);
        int start = 0, end = 0;
        while(end < n) {
            if(M[s[end]] != -1) {
                start = max(start, M[s[end]] + 1);
            }
            M[s[end]] = end;
            ans = max(ans, end-start + 1);
            end++;
        }
        return ans;
    }
};
*/