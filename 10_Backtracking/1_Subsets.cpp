// For every node we have a choice to either select an element or not
// https://youtu.be/REOH22Xwdkk
// skip to 5:20 for the tree drawing

/*
// Iterative solution
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        // pushing empty subset
        result.push_back({});

        for(int i = 0; i < nums.size(); i++) {
            int size = result.size();
            // result size is diff every iteration
            for(int j = 0; j < size; j++) {
                // temp = previous subarrays in result 1 by 1
                vector<int> temp = result[j];
                // pb number from nums to temp
                temp.push_back(nums[i]);
                result.push_back(temp);
            }
        }
        return result;
    }
};
*/

// Recursive solution using DFS
// Backtracking uses DFS
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        
        DFS(result, current, nums, 0);
        return result;
    }
private:
    void DFS(vector<vector<int>> &result, vector<int> &current, vector<int> nums, int start) {
        result.push_back(current);
        for(int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            DFS(result, current, nums, i+1);
            current.pop_back();
        }
    }
};