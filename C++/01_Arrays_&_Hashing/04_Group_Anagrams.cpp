class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // we will store the sorted string and all its anagrams
        unordered_map<string, vector<string>> M;
        /*      
            Consider example 1 : strs = ["eat","tea","tan","ate","nat","bat"]                
            After the below opeartion of for loop map will contain - 
            aet -- eat, tea, ate
            ant -- tan, nat
            abt -- bat
        */
        for(int i = 0; i < strs.size(); i++) {
            string T = strs[i];
            sort(T.begin(), T.end());
            M[T].push_back(strs[i]);
        }

        // Now pushing all the anagrams(vector<string>) of one word, one by one, into result vector
        vector< vector<string> > result;
        for(auto i : M) 
            result.push_back(i.second);
        
        return result;
    }
};