/*
The key intuition to solve the problem is that given a number of stairs n, if we know the number ways to get to the points [n-1] and [n-2], then the total ways to get to the point [n] is n[n-1]+ [n-2]. Because from the [n-1] point, we can take one single step to reach [n]. And from the [n-2] point, we could take two steps to get there.

Basically fibonacci series.
*/

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;

        int first = 1, second = 2;

        for(int  i = 2; i < n; i++) {
            int temp = second;
            second = first + second;
            first = temp;
        }
        return second;
    }
};