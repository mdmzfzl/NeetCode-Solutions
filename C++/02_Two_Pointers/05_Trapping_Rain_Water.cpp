/*
Solution - 
The key is we can calculate the amount of water at any given index by 
-> taking minimum of (max of left nd right so far)
-> that will give us water in between them
-> then subtract the height to remove the elevation

SO make two array to store max height so far from left and right
and then just calculate, min(maxleft, maxright) - height[i];
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int heightSize = height.size();
        vector<int> leftMax(heightSize), rightMax(heightSize);
        int result = 0;

        // Filling the left and right max arrays
        for(int i = 1, j = heightSize - 2; i < heightSize, j >= 0; i++, j--) {
            if(leftMax[i-1] <= height[i-1])
                leftMax[i] = height[i-1];
            else
                leftMax[i] = leftMax[i-1];

            if(rightMax[j+1] <= height[j+1])
                rightMax[j] = height[j+1];
            else
                rightMax[j] = rightMax[j+1];
        }

        for(int i = 0; i < heightSize; i++) {
            int temp = min(leftMax[i], rightMax[i]) - height[i];
            if(temp < 0)
                temp = 0;
            
            result += temp;
        }
        return result;
    }
};

/*
class Solution {
public:
    int trap(vector<int>& H) {
        
        int n = H.size(), mx = 0, ans = 0;
        int idx = max_element(begin(H), end(H)) - begin(H);

        for(int i = 0; i < idx; i++) {
            ans += max(0, mx - H[i]);
            mx = max(mx, H[i]);
        }
        mx = 0;
        for(int i = n - 1; i > idx; i--) {
            ans += max(0, mx - H[i]);
            mx = max(mx, H[i]);
        }

        return ans;
    }
};
*/