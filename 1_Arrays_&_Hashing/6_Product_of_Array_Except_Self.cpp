class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        // First, compute the prefix product and store in res
        // res[i] = product of elements in nums from index 0, 1, ... to i - 1
        for (int i = 0; i < nums.size() - 1; i++) {
            res[i+1] = nums[i] * res[i]; 
        }
        // Second, compute the final result
        int suffixProduct = 1;
        for(int j = nums.size()-1; j > 0; j--) {
            suffixProduct *= nums[j];
            res[j-1] *= suffixProduct;
        }
        return res;
    }
};