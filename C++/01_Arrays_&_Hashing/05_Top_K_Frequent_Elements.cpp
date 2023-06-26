class Solution {
public:
    // Approach - First make a frequency map normally, then insert key value pairs(frequency first, value second) in vector and sort in descending order
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> M;
        vector< pair<int, int> > arr;
        vector<int> result;

        for(int i = 0; i < nums.size(); i++) {
            // it reaches end of map if it didn't find the element
            if(M.find(nums[i]) == M.end()) 
                M[nums[i]] = 1;
            else
                M[nums[i]]++;
        }
        
        for(auto i : M) {
            arr.push_back( make_pair(i.second, i.first) );
        }
        
        sort(arr.rbegin(), arr.rend());

        for(int i = 0; i < k; i++) {
            result.push_back(arr[i].second);
        }
        return result;
    }
};