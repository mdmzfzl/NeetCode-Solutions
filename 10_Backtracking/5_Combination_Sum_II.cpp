class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;

        DFS(result, candidates, current, target, 0, 0);
        return result;
    }
private: 
    void DFS(vector<vector<int>> &result, vector<int> &candidates, vector<int> &current, int target, int sum, int start) {
        if(sum > target)
            return;
        
        if(sum == target) {
            result.push_back(current);
            return;
        }

        for(int i = start; i < candidates.size(); i++) { 
            if (i > start && candidates[i] == candidates[i-1]) 
                continue;
            current.push_back(candidates[i]);
            DFS(result, candidates, current, target, sum + candidates[i], i+1);
            current.pop_back();
        }
    }
};