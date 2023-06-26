auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    bool isAnagram(string s, string t) {
        // HM -> Hash Map
        vector<int> HM(26, 0);
        for(char ch: s) 
            HM[ch-'a']++;
        for(char ch: t) {
            HM[ch-'a']--;
            if(HM[ch-'a'] < 0) 
                return false;
        }
        for(auto i: HM) {
            if(i != 0) 
                return false;
        }
        return true;
   }
};

// class Solution {
// public:
//     bool isAnagram(string s, string t) {       
//         if(s.size() != t.size())
//                 return false;
        
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
        
//         return s == t;
//     }
// };
