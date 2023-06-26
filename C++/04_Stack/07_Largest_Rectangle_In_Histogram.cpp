/*
Given array of heights, return area of largest rectangle
Ex. heights = [2,1,5,6,2,3] -> 10 (5 x 2 at index 2 and 3)

Monotonic incr stack, if curr height lower extend back, find max area

Time: O(n)
Space: O(n)
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // pair: [index, height]
        stack<pair<int, int>> stk;
        int result = 0;
        
        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            
            while (!stk.empty() && stk.top().second > heights[i]) {
                int index = stk.top().first;
                int width = i - index;
                int height = stk.top().second;
                stk.pop();
                
                result = max(result, height * width);
                start = index;
            }
            
            stk.push({start, heights[i]});
        }
        
        while (!stk.empty()) {
            int width = heights.size() - stk.top().first;
            int height = stk.top().second;
            stk.pop();
            
            result = max(result, height * width);
        }
                          
        return result;
    }
};

/*
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        heights.push_back(0);           // To ensure the stack is flushed at the end
        int ans = heights[0], n = heights.size(), m = 0;
        hgt[0] = heights[0];
        pos[0] = 0;
        for(int i = 1; i < n; ++i) {
            pos[m+1] = i;
            for(; m >= 0 && heights[i] < hgt[m]; --m) {
                // cout<<hgt[m]<<":["<<pos[m]<<","<<i<<")\n";
                ans = max(ans, hgt[m] * (i-pos[m]));
            }
            hgt[++m] = heights[i];
        }
        return ans;
    }

private:
    int hgt [100001];
    int pos [100001];
};
*/