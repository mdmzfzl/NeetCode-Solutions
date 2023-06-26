class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(result, nums, 0);
        return result;
    }
private:
    void backtrack(vector<vector<int>> &result, vector<int> &nums, int start) {
        if(start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for(int i = start; i < nums.size(); i++) {
            // swapping allows us to explore all possible permutations by considering different elements at the current position.
            // since start is zero we will swap indices, [0, 1], 0, 2], ... , [0, n-1]
            swap(nums[i], nums[start]);
            backtrack(result, nums, start+1);
            // Once we come out of the recursion, we backtrack by swapping back the elements at indices start and i. This is necessary to restore the original order of elements and avoid duplicates.
            swap(nums[i], nums[start]);           
        }
    }
};