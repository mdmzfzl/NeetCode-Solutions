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
