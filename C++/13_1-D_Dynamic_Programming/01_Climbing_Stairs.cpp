/*
Problem: LeetCode 70 - Climbing Stairs

Description:
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Intuition:
The problem can be solved by recognizing that the number of distinct ways to reach the current step is equal to the sum of the number of distinct ways to reach the previous two steps.
By building up the solution from the base cases of 1 and 2 steps, we can use dynamic programming to calculate the number of distinct ways to reach any step.


Approach:
1. We can solve this problem using dynamic programming.
2. Initialize two variables, prev1 and prev2, to represent the number of distinct ways to reach the previous two steps.
   Initially, set prev1 and prev2 to 1, as there is only one way to reach the first and second steps.
3. Iterate through the steps starting from index 3 up to n:
    - For each step, calculate the number of distinct ways to reach it:
        - current = prev1 + prev2
        - Update prev1 = prev2 and prev2 = current for the next iteration.
4. Return prev2, which represents the number of distinct ways to reach the top of the staircase.

Time Complexity:
The time complexity of this approach is O(n), where n is the number of steps.
This is because we iterate through the steps once to calculate the number of distinct ways.

Space Complexity:
The space complexity is O(1), as we are using only a constant amount of extra space.

Let's implement the solution!
*/

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
            return n;

        int first = 1, second = 2;

        for(int  i = 2; i < n; i++) {
            int temp = second;
            second = first + second;
            first = temp;
        }
        return second;
    }
};