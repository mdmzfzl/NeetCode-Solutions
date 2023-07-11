class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int prev = 0, curr = 0, next = 0;

        for(int i = 0; i < nums.size(); i++) {
            next = max(prev + nums[i], curr);
            prev = curr;
            curr = next;
        }
        return curr;
    }
};
