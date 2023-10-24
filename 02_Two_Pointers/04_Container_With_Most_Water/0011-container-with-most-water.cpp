/*
Problem: LeetCode 11 - Container With Most Water

Description:
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0).
Find two lines, which, together with the x-axis, forms a container, such that the container contains the most water.

Intuition:
To maximize the container's area, we need to find two vertical lines that enclose the most water.
The area is determined by the height of the shorter line and the distance between the lines.
We can start with the maximum width and move the pointers inward, always choosing the next height that is greater than the current one.

Approach:
1. Initialize two pointers, `left` pointing to the start of the array (index 0), and `right` pointing to the end of the array.
2. Initialize a variable `maxArea` to store the maximum container area.
3. Iterate while `left` is less than `right`:
   - Calculate the current container area as the minimum height between `height[left]` and `height[right]` multiplied by the width (`right - left`).
   - Update `maxArea` with the maximum value between `maxArea` and the current area.
   - Move the pointer with the smaller height inward, as moving the pointer with the greater height does not increase the area.
4. Return `maxArea`, which represents the maximum container area.

Time Complexity:
The time complexity is O(n), where n is the number of elements in the input array.
We only need to iterate through the array once from both ends.

Space Complexity:
The space complexity is O(1) as we are using a constant amount of space to store the pointers and the maximum area.
*/

class Solution {
  public:
    int maxArea(vector<int> &height) {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int currArea = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, currArea);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};

// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int leftPointer = 0, rightPointer = height.size() - 1;
//         int result = -1, currResult = 0;

//         while(leftPointer < rightPointer){
//             int dist = rightPointer - leftPointer;
//             currResult = min(height[leftPointer], height[rightPointer]) * dist;

//             result = max(result, currResult);

//             if( height[leftPointer] > height[rightPointer] )
//                 rightPointer--;
//             else
//                 leftPointer++;
//         }
//         return result;
//     }
// };

/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            water = max(water, (j - i) * h);
            while(height[i] <= h && i < j)
                i++;
            while(height[j] <= h && i < j)
                j--;
        }
        return water;
    }
};
*/