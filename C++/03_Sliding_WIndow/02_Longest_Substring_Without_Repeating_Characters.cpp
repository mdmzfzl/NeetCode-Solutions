/*
  -> Use set because it only has unique elements
  -> Start 2 pointers from 0
  -> Keep moving right pointer as long as characters in set are unique
  -> move left pointer if you encounter an element thats in set
  -> Calculate the max every loop
*/

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