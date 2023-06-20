class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> M;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            int compliment = target - nums[i];

            // If we find the compliment
            if(M.find(compliment) != M.end()) {
                // returning i and index of compliment
                res.push_back(M[compliment]); 
                res.push_back(i); 
            }
            else // insert pair
                M.insert( {nums[i], i});
        }
        return res;
    }
};