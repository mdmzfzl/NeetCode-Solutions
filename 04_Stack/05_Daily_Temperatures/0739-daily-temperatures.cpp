/*
Problem: LeetCode 739 - Daily Temperatures

Description:
Given a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day with a warmer temperature, put 0 instead.

Intuition:
To determine the number of days until a warmer temperature, we can use a stack to keep track of the previous temperatures. By iterating through the temperatures in reverse order, we can compare each temperature with the temperatures in the stack to find the next warmer day.

Approach:
1. Initialize an empty stack to store the indices of temperatures.
2. Initialize a result vector with 0s of the same size as the input temperatures.
3. Iterate through the temperatures in reverse order:
   - While the stack is not empty and the current temperature is greater than the temperature at the index at the top of the stack:
     - Pop the index from the stack and calculate the number of days until a warmer temperature (current index - popped index).
     - Update the result vector at the popped index with the number of days.
   - Push the current index onto the stack.
4. Return the result vector.

Time Complexity:
The time complexity is O(n), where n is the number of temperatures. We iterate through the temperatures once.

Space Complexity:
The space complexity is O(n), where n is the number of temperatures. In the worst case, the stack may store all the indices of the temperatures.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> stack;

        for (int i = n - 1; i >= 0; --i) {
            while (!stack.empty() && temperatures[i] >= temperatures[stack.top()]) {
                stack.pop();
            }

            if (!stack.empty()) {
                result[i] = stack.top() - i;
            }

            stack.push(i);
        }

        return result;
    }
};
