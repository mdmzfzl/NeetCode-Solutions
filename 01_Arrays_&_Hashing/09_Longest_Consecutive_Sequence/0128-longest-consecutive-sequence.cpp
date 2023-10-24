/*
Problem: LeetCode 128 - Longest Consecutive Sequence

Description:
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

Intuition:
To find the longest consecutive sequence, we can sort the array in ascending order and then iterate through it to count the longest consecutive sequence. However, this approach would have a time complexity of O(n log n) due to the sorting operation. We can instead use a HashSet to efficiently find consecutive elements.

Approach:
1. Create a HashSet `numSet` and insert all the numbers from the input array `nums`.
2. Initialize a variable `maxLength` to store the maximum length of consecutive elements.
3. Iterate through each number `num` in the `numSet`:
   - Check if the current number `num - 1` is not present in the `numSet`. If true, it means the current number is the start of a consecutive sequence.
   - Initialize a variable `length` to 1 to count the current consecutive sequence length.
   - Iterate through consecutive numbers starting from the current number `num + 1` until a number is not present in the `numSet`, incrementing the `length` accordingly.
   - Update `maxLength` with the maximum value between `maxLength` and `length`.
4. Return `maxLength`, which represents the length of the longest consecutive sequence.

Time Complexity:
The time complexity of this approach is O(n), where n is the number of elements in the input array. It is determined by the iteration through the `numSet`, which contains all the unique numbers.

Space Complexity:
The space complexity is O(n) as we need to store all the numbers from the input array in the `numSet`.
*/

class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLength = 0;

        for (int num : numSet) {
            // Check if the current number is the start of a consecutive sequence
            if (numSet.count(num - 1) == 0) {
                int length = 1;

                // Iterate through consecutive numbers starting from the current number
                while (numSet.count(num + length) != 0) {
                    length++;
                }

                maxLength = max(maxLength, length);
            }
        }

        return maxLength;
    }
};

// auto init = [](){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.empty())
//             return 0;
//         else if(nums.size() == 1)
//             return 1;

//         sort(nums.begin(),nums.end());
//         int ans = 1;
//         int cnt = 1;

//         for(int i = 0; i < nums.size(); i++) {
//             if(i > 0 && nums[i-1]+1 == nums[i]) {
//                 ++cnt;
//                 ans = max(ans, cnt);
//             }
//             else if(i > 0 && nums[i-1] == nums[i])
//                 continue;
//             else
//                 cnt = 1;
//         }
//         return ans;
//     }
// };

/*
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;

        // Using set because its sorted and takes O(log N) time
        set<int> S;
        int Max = 0, local_Max = 0;

        for(int i = 0; i < nums.size(); i++)
            S.insert(nums[i]);

        vector<int> V(S.begin(), S.end());

        for(int i = 1; i < V.size(); i++) {
            if(V[i] - V[i-1] == 1) {
                local_Max++;
                if(Max < local_Max)
                    Max = local_Max;
            }
            else
                local_Max = 0;
        }
        return Max + 1;
    }
};
*/