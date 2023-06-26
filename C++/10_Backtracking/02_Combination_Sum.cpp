class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if(candidates.size() == 0 || target < 0)
            return result;
        vector<int> current;

        sort(candidates.begin(), candidates.end());
        DFS(result, candidates, current, target, 0, 0);
        return result;
    }
private:
    void DFS(vector<vector<int>> &result, vector<int> &candidates, vector<int> &current, int target, int sum, int start) {
        if(sum > target)
            return;
        
        if(sum == target) 
            result.push_back(current);
        
        for(int i = start; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            DFS(result, candidates, current, target, sum + candidates[i], i);
            current.pop_back();
        }
    }
};