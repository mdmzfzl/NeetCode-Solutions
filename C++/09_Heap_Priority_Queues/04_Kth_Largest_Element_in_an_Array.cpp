class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = k-1;
        priority_queue<int> PQ(nums.begin(), nums.end());
        while(size){
            PQ.pop();
            size -= 1;
        }
            
        return PQ.top();
    }
};

/*
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        nth_element(nums.begin(), nums.begin()+k - 1, nums.end(), greater<int>());
	    return nums[k-1];
    }
};
*/