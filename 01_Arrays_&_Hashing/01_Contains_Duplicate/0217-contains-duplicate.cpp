/*
Problem: LeetCode 217 - Contains Duplicate

Intuition:
To solve this problem, we can utilize the property of a hash set. By storing each element encountered in the set and checking for collisions, we can efficiently determine if any duplicates exist in the array. If a collision occurs, it indicates the presence of a duplicate element.

Approach:
1. Initialize an empty hash set.
2. Iterate through each element num in the input array nums:
    - If num is already present in the hash set, return true as we have found a duplicate.
    - Otherwise, add num to the hash set.
3. If no duplicates are found after iterating through all elements, return false.

Time Complexity:
The time complexity of this approach is O(n), where n is the size of the input array nums. This is because we iterate through the array once and perform constant-time operations for each element.

Space Complexity:
The space complexity is O(n), as the hash set can potentially store all elements of the input array.
*/

class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num) > 0) {
                return true; // Duplicate found
            }

            seen.insert(num);
        }

        return false; // No duplicates found
    }
};

/*
auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        size_t count = nums.size();

        // Sort using LSD Radix
        Sort(reinterpret_cast<unsigned int*>(&(nums[0])), count);

        --count;
        for(size_t i = 0; i < count; ++i)
            if(nums[i] == nums[i+1])
                return true;

        return false;
    }

private:
    void Sort(unsigned int* start, size_t len) {
        unsigned int* buffer = new unsigned int[len];
        LSDRadix(start, buffer, len);
        delete[] buffer;
    }

    void LSDRadix(unsigned int* input, unsigned int* buffer, size_t len) {
        for(int bits = 0; bits < 16; bits += 8) {
            size_t count[256] = {0};
            for(int x = 0; x < len; ++x)
                ++count[(input[x] >> bits) & 0xff];
            for(int x = 0; x < 255; ++x)
                count[x + 1] += count[x];
            for(int x = len - 1; x >= 0; --x)
                buffer[--count[(input[x] >> bits) & 0xff]] = input[x];
            unsigned int* temp = input;
            input = buffer;
            buffer = temp;
        }
    }
};
*/