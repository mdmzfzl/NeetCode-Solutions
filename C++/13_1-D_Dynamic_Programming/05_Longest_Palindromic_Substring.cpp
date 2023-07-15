/*
Problem: LeetCode 5 - Longest Palindromic Substring

Description:
Given a string s, return the longest palindromic substring in s.

Approach:
1. Iterate through each index i in the range [0, s.size() - 1):
    a. Call the helper function with arguments s, i, i.
       This considers a palindrome with a single center character.
    b. Call the helper function with arguments s, i, i+1.
       This considers a palindrome with two center characters.
2. The helper function expands around the center (L, R) and updates the start and maxLength variables.
   If a longer palindromic substring is found, start and maxLength are updated accordingly.
3. Return the substring of s starting from index start and having length maxLength.

Time Complexity:
The time complexity of this approach is O(n^2), where n is the length of the input string s.
This is because we expand around each character in the string.

Space Complexity:
The space complexity is O(1), as we are not using any additional data structures.

Let's implement the solution!
*/

// Consider each element as middle of a palindrome and keep expanding
class Solution {
public:
    string longestPalindrome(string s) {
        // Two possibilities, palindrome can be even or odd length
        for(int i = 0; i < s.size() - 1; i++) {
            // To check odd palindromes
            helper(s, i, i);
            // To check even palindromes
            helper(s, i, i+1);
        }

        return s.substr(start, maxLength);
    }

private:
    // Need the index and length to cut the string using substr
    int start = 0, maxLength = 1;
    void helper(string S, int L, int R) {
        while(L >= 0 && R < S.size() && S[L] == S[R]) 
            L--, R++;
        
        int len = R - L - 1;
        if(len > maxLength) {
            start = L + 1;
            maxLength = len;
        }
    }
};
