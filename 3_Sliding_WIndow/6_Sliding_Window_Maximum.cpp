/*
  -> Use a Deque because you can push/pop from both front and back
  -> In a sliding window just store the max value and pop all values before it
  -> If the next value is lesser, then store it
  -> This way front of the deque will always be greater
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int L = 0, R = 0;
        // We will store the indices, since we can get the value by using nums[index]
        deque<int> Indices;

        while(R < nums.size()) {
            // Before pushing we need to pop all smaller values before it
            // While Deque is not empty and last element in the Deque is lesser than the value we're inserting
            while((!Indices.empty()) && nums[Indices.back()] < nums[R]) 
                Indices.pop_back();
            
            // After popping lesser value, We add the greater value(index of it)
            Indices.push_back(R);

            // Remove left value from window if out of bounds
            if(L > Indices.front())
                Indices.pop_front();

            // Since L and R are both starting from 0, we need to check if our winow is atleast size k
            // So we can pushback the result
            if(R + 1 >= k) {    // For each iteration we append our maximum
                result.push_back(nums[Indices.front()]); // front() is the index of maximum
                L++;            // Incrementing L once the window is atleast size K
            }
            R++; // R will always increase
        }
        return result;
    }
};

/*
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int offset = 1e4;
        std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int mp[(int)(2 * 1e4 + 1)] = {0};
        int maxval = INT_MIN;

        for(int i = 0; i < k; i++) {
            mp[offset + nums[i]]++;
            maxval = max(maxval, nums[i]);
        }

        vector<int> ans;
        ans.push_back(maxval);

        for(int j = k; j < nums.size(); j++) {
            mp[offset + nums[j - k]]--;
            mp[offset + nums[j]]++;
            maxval = max(maxval, nums[j]);
            int mpos = maxval + offset;
            while(mp[mpos] == 0) {
                mpos--;
            }
            maxval = mpos - offset;
            ans.push_back(maxval);
        }

        return ans;

    }
};
*/