/*
  -> The sliding window size will be fixed i.e. size of s1
  -> We need to keep moving window until 
     frequency of chars in winodw = frequency of chars in s1
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        unordered_map<char, int> FS1;
        unordered_map<char, int> FS2;

        for(int i = 0; i < s1.size(); i++) {
            FS1[s1[i]]++;
            FS2[s2[i]]++;
        }

        int L = 0; 
        if(FS1 == FS2)
                return true;

        for(int R = s1.size(); R < s2.size(); R++) {
            if(FS2[s2[L]] == 1)  // We will increment L later, so if freq is 1, delete it for direct comparision with FS1
                FS2.erase(s2[L]);
            else                 // Else decreasing the value, since we will increment L
                FS2[s2[L]]--;

            FS2[s2[R]]++;    // Updating value of newly added element in the window
            L++;             // Increasing L because we increased R and winodw size is fixed
            if(FS1 == FS2)
                return true;
        }
        return false;
    }
};