/*
  -> Have a L and R pointer
  -> keep increasing R till you find all chars in T that need to be in S, with help of count
  -> Once count is 0, start increasing L
  -> Keep going till you find an element thats in T, increment L and count and repeat from step 1 again
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length())
            return "";

        unordered_map<char, int> M;
        for(int i = 0; i < t.size(); i++)
            M[t[i]]++;
        
        int L = 0, R = 0;
        int count = t.size();  // No. of chars in t that need to be n S
        int minLength = INT_MAX;
        int minStart = 0; // We have to return string, so this variable is for storing teh starting index 

        while(R < s.size()) {
            if(M[s[R]] > 0)     // If we find an element from T(which we put in M)
                count--;

            // We will decrease the value here also, since count only counts unique elements
            // Elements in M will decrease till 0(which then decreases count)
            // and elements that dont exist in M will be -ve
            M[s[R]]--;
            R++;
            while(count == 0) {
                if(R-L < minLength) {
                    minLength = R-L;
                    minStart = L;
                }
                M[s[L]]++; // Updating the value in Map
                // If the current L element is from T, then increase count
                if(M[s[L]] > 0) {   
                    count++;
                }
                L++;
            }
        }
        // If the ans is empty string, minLength(= MAX_INT) will not be changed
        if (minLength != INT_MAX) {
            return s.substr(minStart, minLength);
        }
        return "";
    }
};

/*
class Solution {
public:
    string minWindow(string s, string t) {
        int cnt[128] = {}, diff = t.size();
        for(int i = 0; i < t.size(); i++) 
            cnt[t[i]]++;
        int left = 0, right = 0, idx = 0, size = 2e5;
        while(right < s.size()) {
            if(cnt[s[right++]]-- > 0) 
                diff--;
            while(diff == 0) {
                if(right-left < size) 
                    size = right-(idx = left);
                if(cnt[s[left++]]++ == 0) 
                    diff++;
            }
        }
        return (size == 2e5) ? "" : s.substr(idx, size);
    }
};
*/