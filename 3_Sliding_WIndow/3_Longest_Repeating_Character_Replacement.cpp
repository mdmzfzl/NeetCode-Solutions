/*
  -> Have two pointer L and R start at 0
  -> Keep incrementing R until size of the window(R-L) minus 
     the most frequent element is lesser than or equal to k.
     i.e Window Size - Most Frequent Element count <= K
     Because K is the max number of changes we can make
  -> If Window Size - Most Frequent Element count > K, then increment L
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int L = 0, R = 0;
        int maxFreq = 0, maxLength = 0;
        unordered_map<char, int> M; //For storing chars and their frequency 
        
        while(R < s.size()) {
            // int winLen = R - L + 1; // Sliding window length
            M[s[R]]++;      // Updating frequency in Map
            maxFreq = max(maxFreq, M[s[R]]); // if curr freq is greater than maxFreq, update
            if(R-L+1 - maxFreq > k) { 
                M[s[L]]--;      // Decrementing count of L'th element because we're gonna move L
                L++;
            }
            // Technically we will never need to reduce the maxFreq, 
            // because answer will be set around around it
            // We can adjust the length, so basically the ans is maxFreq + K
            maxLength = max(maxLength, R-L+1);
            R++;                //Moving R
        }
        return maxLength;
    }
};

/*
class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size() == 1)
            return 1;
        int i{}, j{}, res{}, maxCount{0};
        vector<int> a(26, 0);
        while(j < s.size()) {
            a[s[j] - 'A']++;
            if(maxCount < a[s[j]-'A'])
                maxCount = a[s[j]-'A'];
            if((j - i + 1) - maxCount > k){
                a[s[i]-'A']--;
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
    return res;
    }
};
*/