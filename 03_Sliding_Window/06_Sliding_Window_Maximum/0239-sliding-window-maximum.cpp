/*
Problem: LeetCode 239 - Sliding Window Maximum

Description:
Given an array of integers `nums` and an integer `k`, return the maximum sliding window of size `k` in the array.

Intuition:
To find the maximum sliding window of size `k`, we can use a sliding window and a deque (double-ended queue).
The deque will store the indices of elements in decreasing order of their values.
By maintaining this order, the maximum element in the window will always be at the front of the deque.

Approach:
1. We start by initializing an empty deque to store the indices of elements.
2. We iterate through the array `nums` from left to right:
   - Remove indices from the back of the deque if the corresponding elements are smaller than the current element.
   - Add the current element's index to the back of the deque.
   - If the index at the front of the deque is outside the current window, remove it.
   - If the current index is greater than or equal to `k - 1` (i.e., the window size), it means we have processed `k` elements and can start collecting the maximum values.
     - Add the maximum value (which is the element at the front of the deque) to the result vector.
3. Return the result vector.

Time Complexity:
The time complexity is O(n), where n is the length of the input array `nums`. We iterate through `nums` once.

Space Complexity:
The space complexity is O(k), where k is the size of the sliding window. The deque stores at most `k` indices.
*/

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> result;
        deque<int> indices;

        for (int i = 0; i < nums.size(); i++) {
            // Remove indices from the back of the deque if the corresponding elements are smaller than the current element
            while (!indices.empty() && nums[indices.back()] < nums[i]) {
                indices.pop_back();
            }

            indices.push_back(i);

            // Remove the index at the front of the deque if it is outside the current window
            if (indices.front() <= i - k) {
                indices.pop_front();
            }

            // Add the maximum value to the result if the current index is in the window
            if (i >= k - 1) {
                result.push_back(nums[indices.front()]);
            }
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