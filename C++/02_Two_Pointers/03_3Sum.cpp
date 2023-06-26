// Sort the array
// use one loop to iterate through all elements 
// then another loop inside to find the two sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int numSize = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for(int i = 0; i < numSize - 2; i++) {            
            if(i==0 ||(i > 0 && nums[i] != nums[i-1])) {
                int leftPointer = i+1, rightPointer = numSize -1, sum = 0 - nums[i];
                while(leftPointer < rightPointer) {
                    if(nums[leftPointer] + nums[rightPointer] == sum) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[leftPointer]);
                        temp.push_back(nums[rightPointer]);
                        result.push_back(temp);

                        // Going through all same values(if any as it has multiple same values) 
                        while(leftPointer < rightPointer && nums[leftPointer] == nums[leftPointer+1]){
                            leftPointer++;
                        }
                        while(rightPointer > leftPointer && nums[rightPointer] == nums[rightPointer-1]){
                            rightPointer--;
                        }
                        // updating left and right pointer after the iteration
                        leftPointer++; rightPointer--;
                    }
                    else if(nums[leftPointer] + nums[rightPointer] < sum && leftPointer+1 < rightPointer)
                        leftPointer++;
                    else
                        rightPointer--;
                }
            }
        } 
        return result;
    }
};