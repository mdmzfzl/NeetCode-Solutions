/*
Problem: LeetCode 202 - Happy Number

Description:
A happy number is a number defined by the following process:
- Starting with any positive integer, replace the number by the sum of the squares of its digits.
- Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
- Those numbers for which this process ends in 1 are happy.

Intuition:
To determine if a number is a happy number, we can use a set to keep track of all the numbers we have encountered during the process. If we encounter a number that we have seen before, it means there is a cycle, and the number is not a happy number.

Approach:
1. We start with the given number and calculate the sum of the squares of its digits.
2. We continue this process until the sum becomes 1 or until we encounter a number that we have seen before.
3. If the sum becomes 1, we return true, indicating that the number is a happy number.
4. If we encounter a number we have seen before, we return false, indicating that the number is not a happy number.

Time Complexity:
The time complexity of this approach is difficult to determine as it depends on the number of iterations required to reach 1 or find a cycle. In practice, the process usually converges quickly for happy numbers, so the time complexity is considered to be approximately O(log n).

Space Complexity:
The space complexity is O(log n) as we use a set to keep track of the numbers encountered during the process, and the number of unique numbers encountered is limited.
*/

class Solution {
  public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = getNextNumber(n);
        }

        return n == 1;
    }

  private:
    int getNextNumber(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }
};