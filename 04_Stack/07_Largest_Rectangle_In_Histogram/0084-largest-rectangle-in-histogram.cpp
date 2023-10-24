/*
Problem: LeetCode 84 - Largest Rectangle in Histogram

Description:
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Intuition:
To find the largest rectangle in a histogram, we can utilize a stack to keep track of the indices of increasing heights. By iterating through the histogram, we can calculate the area of each rectangle formed by the heights.

Approach:
1. Initialize a stack to store the indices of increasing heights.
2. Initialize the maximum area to 0.
3. Iterate through each bar in the histogram:
   - While the stack is not empty and the current bar's height is less than the height at the index at the top of the stack:
     - Pop the index from the stack and calculate the area of the rectangle formed by the popped bar.
     - Update the maximum area if the calculated area is greater.
   - Push the current index onto the stack.
4. After iterating through all bars, there might be remaining bars in the stack. Process them similarly to step 3 to calculate the areas and update the maximum area.
5. Return the maximum area.

Time Complexity:
The time complexity is O(n), where n is the number of bars in the histogram. We iterate through each bar once.

Space Complexity:
The space complexity is O(n), where n is the number of bars in the histogram. In the worst case, all bars are stored in the stack.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        stack<int> stack;
        int maxArea = 0;

        for (int i = 0; i <= n; ++i) {
            while (!stack.empty() && (i == n || heights[i] < heights[stack.top()])) {
                int height = heights[stack.top()];
                stack.pop();
                int width = stack.empty() ? i : i - stack.top() - 1;
                maxArea = max(maxArea, height * width);
            }

            stack.push(i);
        }

        return maxArea;
    }
};