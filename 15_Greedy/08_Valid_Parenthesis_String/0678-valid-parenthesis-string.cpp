/*
Problem: LeetCode 678 - Valid Parenthesis String

Description:
Given a string s containing only three types of characters: '(', ')', and '*',
return true if s is valid.

The string is valid if the following conditions are met:
- Any left parenthesis '(' must have a corresponding right parenthesis ')'.
- Any right parenthesis ')' must have a corresponding left parenthesis '('.
- Left parenthesis '(' must go before the corresponding right parenthesis ')'.
- '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.

Intuition:
To check the validity of the given string, we can use a greedy approach along with two stacks.
We will keep two stacks, one to store the indices of the left parenthesis '(' and another to store the indices of the '*' encountered so far.
At any point, if we encounter a right parenthesis ')', we will first try to match it with the topmost left parenthesis in the left stack.
If the left stack is empty, we will try to match it with the topmost '*' in the '*' stack.
If both stacks are empty, we can't find a matching parenthesis, and the string is invalid.
Otherwise, we continue to pop the matched parenthesis and '*' from their respective stacks until we find a match or both stacks become empty.
If after processing the entire string, both stacks are empty, the string is valid.

Approach:
1. Initialize two stacks to store the indices of left parenthesis '(' and '*' encountered so far.
2. Iterate through the string.
3. If we encounter '(', push its index into the left stack.
4. If we encounter '*', push its index into the '*' stack.
5. If we encounter ')':
   - If the left stack is not empty, pop the topmost index from the left stack as it matches the current ')'.
   - Otherwise, if the '*' stack is not empty, pop the topmost index from the '*' stack as it can act as a right parenthesis.
   - If both stacks are empty, return false as we can't find a matching parenthesis.
6. After processing the entire string, we have some left parenthesis '(' and '*' without matches. Now, we need to match each remaining '(' with a '*' (if possible).
   To do this, we can pop pairs of '(' and '*' from their respective stacks until either of them becomes empty.
   If the left stack becomes empty first, it means we have matched all '(' with '*'. If the '*' stack becomes empty first, it means we have some '*' left without matches.
   We can ignore the '*' after matching all possible '(' as they can act as an empty string.
7. If both stacks become empty during this process, return true, indicating that the string is valid.
8. If any of the stacks still has elements, it means we can't find a match for some left parenthesis, and the string is invalid.

Time Complexity:
The time complexity is O(n), where n is the length of the string.

Space Complexity:
The space complexity is O(n), as in the worst case, both stacks can have all elements of the string.
*/

class Solution {
  public:
    bool checkValidString(string s) {
        stack<int> leftStack, starStack;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                leftStack.push(i);
            } else if (s[i] == '*') {
                starStack.push(i);
            } else {
                if (!leftStack.empty()) {
                    leftStack.pop();
                } else if (!starStack.empty()) {
                    starStack.pop();
                } else {
                    return false;
                }
            }
        }

        while (!leftStack.empty() && !starStack.empty()) {
            if (leftStack.top() > starStack.top()) {
                return false;
            }

            leftStack.pop();
            starStack.pop();
        }

        return leftStack.empty();
    }
};

/*
class Solution {
public:
    bool checkValidString(string s) {
        int leftOpen = 0; // Keep track of possible open parentheses
        int leftMin = 0; // Minimum possible open parentheses
        for (char c : s) {
            if (c == '(') {
                leftOpen++;
                leftMin++;
            } else if (c == ')') {
                leftOpen--;
                leftMin = max(leftMin - 1, 0); // Ensure leftMin doesn't go negative
            } else { // c == '*'
                leftOpen++;
                leftMin = max(leftMin - 1, 0); // Ensure leftMin doesn't go negative
            }

            if (leftOpen < 0) {
                return false; // If there are too many closing parentheses, return false
            }
        }
        return leftMin == 0; // Check if all open parentheses can be matched
    }
};
*/