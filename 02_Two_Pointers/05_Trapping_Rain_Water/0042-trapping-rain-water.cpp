/*
Problem: LeetCode 42 - Trapping Rain Water

Description:
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Intuition:
To determine the amount of water that can be trapped, we need to consider the height of each bar and the width between the bars.
The amount of water trapped at a particular position depends on the minimum height of the tallest bars on its left and right sides minus the elevation.

Approach:
1. Initialize two pointers, `left` pointing to the start of the array (index 0), and `right` pointing to the end of the array.
2. Initialize variables `leftMax` and `rightMax` to keep track of the maximum heights encountered on the left and right sides.
3. Initialize a variable `water` to store the total trapped water.
4. Iterate while `left` is less than `right`:
   - If the height at `left` is less than or equal to the height at `right`:
     - Update `leftMax` with the maximum value between `leftMax` and the current height at `left`.
     - Calculate the amount of water that can be trapped at `left` by subtracting the height at `left` from `leftMax`.
     - Add the calculated water to the total `water` variable.
     - Increment `left`.
   - If the height at `left` is greater than the height at `right`:
     - Update `rightMax` with the maximum value between `rightMax` and the current height at `right`.
     - Calculate the amount of water that can be trapped at `right` by subtracting the height at `right` from `rightMax`.
     - Add the calculated water to the total `water` variable.
     - Decrement `right`.
5. Return the total trapped `water`.

Time Complexity:
The time complexity is O(n), where n is the number of elements in the input array. We iterate through the array once from both ends.

Space Complexity:
The space complexity is O(1) as we are using a constant amount of space to store the pointers and variables.
*/

class Solution {
  public:
    int trap(vector<int> &height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
                right--;
            }
        }

        return water;
    }
};

/*
Solution -
The key is we can calculate the amount of water at any given index by
-> taking minimum of (max of left nd right so far)
-> that will give us water in between them
-> then subtract the height to remove the elevation

SO make two array to store max height so far from left and right
and then just calculate, min(maxleft, maxright) - height[i];
*/

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int heightSize = height.size();
//         vector<int> leftMax(heightSize), rightMax(heightSize);
//         int result = 0;

//         // Filling the left and right max arrays
//         for(int i = 1, j = heightSize - 2; i < heightSize, j >= 0; i++, j--) {
//             if(leftMax[i-1] <= height[i-1])
//                 leftMax[i] = height[i-1];
//             else
//                 leftMax[i] = leftMax[i-1];

//             if(rightMax[j+1] <= height[j+1])
//                 rightMax[j] = height[j+1];
//             else
//                 rightMax[j] = rightMax[j+1];
//         }

//         for(int i = 0; i < heightSize; i++) {
//             int temp = min(leftMax[i], rightMax[i]) - height[i];
//             if(temp < 0)
//                 temp = 0;

//             result += temp;
//         }
//         return result;
//     }
// };

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