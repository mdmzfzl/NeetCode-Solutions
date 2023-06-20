/*
Algorithm:
If MID equals target, return
else if, L to MID is sorted, check if lies from L to MID, else MID to R
else, MID to R must be sorted(because it failed the previous else case), 
     check if lies bw MID and R, if not then it should lie in the other half
return -1 after end of loop
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int L = 0, R = size - 1;

        while(L <= R) {
            int mid = L + (R-L)/2;

            // If target is found
            if(nums[mid] == target)
                return mid;
                
            // Checking if L half sorted or not
            else if(nums[L] <= nums[mid]) {
                // Checking if target lies in this half
                if(nums[L] <= target && target <= nums[mid])
                    R = mid - 1;
                // If it doesn't then it has to be in other half
                else
                    L = mid + 1;
            }
            // If L half is not sorted, R half will be sorted
            else {
                // Checking if target lies bw MID and R
                if(nums[mid] <= target && target <= nums[R])
                    L = mid + 1;
                // If not bw MID and R, has to be in bw L and MID
                else
                    R = mid - 1;
            }
        }
        return -1;
    }
};
