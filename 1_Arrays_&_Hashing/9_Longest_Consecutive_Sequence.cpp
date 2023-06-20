auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) 
            return 0;
        else if(nums.size() == 1) 
            return 1;
        
        sort(nums.begin(),nums.end());
        int ans = 1;
        int cnt = 1;

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i-1]+1 == nums[i]) {
                ++cnt;
                ans = max(ans, cnt);
            }
            else if(i > 0 && nums[i-1] == nums[i]) 
                continue;
            else 
                cnt = 1;
        }
        return ans;
    }
};

/*
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;

        // Using set because its sorted and takes O(log N) time
        set<int> S;
        int Max = 0, local_Max = 0;

        for(int i = 0; i < nums.size(); i++) 
            S.insert(nums[i]);
        
        vector<int> V(S.begin(), S.end());
        
        for(int i = 1; i < V.size(); i++) {
            if(V[i] - V[i-1] == 1) {
                local_Max++;
                if(Max < local_Max)
                    Max = local_Max;
            }
            else
                local_Max = 0;
        }
        return Max + 1;
    }
};
*/