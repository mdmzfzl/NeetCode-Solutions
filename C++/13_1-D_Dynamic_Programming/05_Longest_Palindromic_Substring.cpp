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
