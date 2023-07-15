/*
Problem: LeetCode 647 - Palindromic Substrings

Description:
Given a string s, return the number of palindromic substrings in it.

Approach:
1. Iterate through each index i in the range [0, s.size()):
    a. Call the helper function with arguments s, i, i.
       This considers a palindrome with a single center character.
    b. Call the helper function with arguments s, i, i+1.
       This considers a palindrome with two center characters.
2. The helper function expands around the center (L, R) and counts the palindromic substrings.
3. Return the result, which represents the total count of palindromic substrings.

Time Complexity:
The time complexity of this approach is O(n^2), where n is the length of the input string s.
This is because we expand around each character in the string.

Space Complexity:
The space complexity is O(1), as we are not using any additional data structures.

Let's implement the solution!
*/

class Solution {
public:
    int countSubstrings(string s) {
        for(int i = 0; i < s.size(); i++) {
            helper(s, i, i);
            helper(s, i, i+1);
        }

        return result;
    }

private:
    int result = 0;
    void helper(string S, int L, int R) {
        while(L >= 0 && R < S.size() && S[L] == S[R]) {
            L--, R++;
            result++;
        }
    }
};
