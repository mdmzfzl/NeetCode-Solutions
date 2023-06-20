class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        DFS(result, current, s, 0);
        return result;
    }

private:
    void DFS(vector<vector<string>> &result, vector<string> &current, const string& S, int start) {
        if(start == S.length()) {
            result.push_back(current);
            return;
        }

        for(int i = start; i < S.length(); i++) 
            if(isPalindrome(S, start, i)) {
                // If the substring is a palindrome
                // we extract it using sunstr and add it to the current vector.
                string substring = S.substr(start, i - start + 1);
                current.push_back(substring);  // Add it to the current partition
                DFS(result, current, S, i+1);  // Explore further with the next index
                current.pop_back();  // Backtrack by removing the last substring
            }
    }

    bool isPalindrome(const string& S, int start, int end) {
        while (start < end) {
            if (S[start] != S[end])
                return false;
            ++start;
            --end;
        }
        return true;
    }
};