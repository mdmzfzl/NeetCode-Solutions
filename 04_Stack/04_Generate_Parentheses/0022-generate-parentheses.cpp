/*
Problem: LeetCode 22 - Generate Parentheses

Description:
Given an integer n, generate all combinations of well-formed parentheses of length 2n.

Intuition:
To generate all combinations of well-formed parentheses, we can use a backtracking approach. At each step, we have two choices: either to place an opening parenthesis or a closing parenthesis.

Approach:
1. Initialize an empty result vector to store all valid combinations.
2. Define a helper function, backtrack, that takes the current combination, the count of opening parentheses, the count of closing parentheses, and the result vector.
3. In the backtrack function:
   - If the length of the current combination is equal to 2n, add it to the result vector.
   - If the count of opening parentheses is less than n, recursively call the backtrack function with the current combination appended with an opening parenthesis and an incremented count of opening parentheses.
   - If the count of closing parentheses is less than the count of opening parentheses, recursively call the backtrack function with the current combination appended with a closing parenthesis and an incremented count of closing parentheses.
4. Call the backtrack function initially with an empty combination, 0 opening parentheses, 0 closing parentheses, and the result vector.
5. Return the result vector containing all valid combinations.

Time Complexity:
The time complexity is O(4^n / sqrt(n)), as there are Catalan numbers of well-formed parentheses combinations.

Space Complexity:
The space complexity is O(4^n / sqrt(n)), as there can be a total of 4^n / sqrt(n) combinations generated.
*/

class Solution {
  public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n, 0, 0, "", result);
        return result;
    }
  private:
    void generate(int n, int open, int close, string str, vector<string> &result) {
        if (open == n && close == n) {
            result.push_back(str);
            return;
        }

        if (open < n) {
            generate(n, open + 1, close, str + '(', result);
        }

        if (open > close) {
            generate(n, open, close + 1, str + ')', result);
        }
    }
};