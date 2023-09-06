/*
Problem: LeetCode 20 - Valid Parentheses

Description:
Given a string `s` containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

Intuition:
To determine if a string of parentheses is valid, we can utilize a stack data structure. We iterate through the characters of the string and perform the following steps:
- If we encounter a closing bracket, we check if the stack is empty or if the top of the stack does not correspond to the current closing bracket. If either condition is true, the string is not valid.
- If we encounter an opening bracket, we push it onto the stack.
After iterating through all the characters, if the stack is empty, the string is valid; otherwise, it is not.

Approach:
1. Initialize an empty stack to store opening brackets.
2. Iterate through each character in the string `s`:
   - If the current character is a closing bracket, check if the stack is empty or if the top of the stack does not match the current closing bracket. Return false if either condition is true.
   - If the current character is an opening bracket, push it onto the stack.
3. After iterating through all characters, check if the stack is empty:
   - If the stack is empty, return true, indicating that all brackets have been matched.
   - If the stack is not empty, return false, indicating unmatched brackets.
4. The function returns true if all brackets are matched; otherwise, it returns false.

Time Complexity:
The time complexity is O(n), where n is the length of the input string `s`. We iterate through each character once.

Space Complexity:
The space complexity is O(n), where n is the length of the input string `s`. In the worst case, the stack may store all opening brackets.
*/

class Solution {
  public:
    bool isValid(string s) {
        stack<char> bracketStack;

        for (char ch : s) {
            if (ch == ')' || ch == '}' || ch == ']') {
                if (bracketStack.empty() || !isMatchingPair(bracketStack.top(), ch)) {
                    return false;
                }

                bracketStack.pop();
            } else {
                bracketStack.push(ch);
            }
        }

        return bracketStack.empty();
    }

  private:
    bool isMatchingPair(char opening, char closing) {
        return (opening == '(' && closing == ')') ||
               (opening == '{' && closing == '}') ||
               (opening == '[' && closing == ']');
    }
};

// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> stag;
//         for(int i = 0; i < s.size(); i++) {
//             if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
//                 if(stag.empty())
//                     return false;
//                 if(s[i] == ')' && stag.top() != '(')
//                     return false;
//                 if(s[i] == '}' && stag.top() != '{')
//                     return false;
//                 if(s[i] == ']' && stag.top() != '[')
//                     return false;
//                 stag.pop();
//             }
//             else {
//                 stag.push(s[i]);
//             }
//         }

//         if (!stag.empty()) {
//             return false;
//         }

//         return true;
//     }
// };