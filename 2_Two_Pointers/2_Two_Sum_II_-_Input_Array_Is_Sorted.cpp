// Use two pointers
// Since arra is sorted, if the sum of two pointers is greater than target then shift the right pointer
// if the sum is lesser, then shift the left pointer
// return if found target

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector<int> result; 
        
        while(left < right) {
            int sum = numbers[left] + numbers[right];
            if(sum == target) {
                result.push_back(left + 1);
                result.push_back(right + 1);
                break;
            }

            else if(sum < target) // increasing left pointer if the sum is lower than target
                left++;

            else                   // decreasing right pointer if sum is greater
                right--;
        }
        
        return result;
    }
};
