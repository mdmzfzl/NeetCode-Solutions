class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> current;
        DFS(result, nums, current, 0);
        return result;
    }
private:
    // To handle duplicates, we skip adding elements that are the same as the previous element at the same level of recursion. This ensures that duplicate subsets are not generated.
    void DFS(vector<vector<int>> &result, vector<int> &nums, vector<int> &current, int start) {
        result.push_back(current);
        
        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i] == nums[i-1])   // Skip duplicates to avoid duplicate subsets
                continue;
            current.push_back(nums[i]);
            DFS(result, nums, current, i+1);
            current.pop_back();
        }
    }
};