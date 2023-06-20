class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> Map;
        for(int i = 0; i < nums.size(); i++) {
            if(Map.find(nums[i]) == Map.end())
                Map[nums[i]] = 1;
            else
                return true;
        }
        return false;        
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