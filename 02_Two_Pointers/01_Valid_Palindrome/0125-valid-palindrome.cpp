/*
Problem: LeetCode 125 - Valid Palindrome

Description:
Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Intuition:
To check if a string is a palindrome, we need to compare characters from both ends of the string. We can ignore non-alphanumeric characters and treat uppercase and lowercase letters as the same.

Approach:
1. Initialize two pointers, `left` pointing to the start of the string, and `right` pointing to the end of the string.
2. Iterate while `left` is less than `right`:
   - Skip non-alphanumeric characters by incrementing `left` or decrementing `right` if the character at that position is not alphanumeric.
   - Convert both characters to lowercase and compare them. If they are not equal, return false.
   - Increment `left` and decrement `right` to move to the next pair of characters.
3. If the loop completes without finding any non-matching characters, return true.

Time Complexity:
The time complexity is O(n), where n is the length of the input string. We iterate through the string once to check if it is a valid palindrome.

Space Complexity:
The space complexity is O(1) since we are using a constant amount of space to store the pointers and perform the comparison.
*/

class Solution {
  public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            // isalnum -> Is alphabet or number
            if (!isalnum(s[left])) {
                left++;
                continue;
            }

            if (!isalnum(s[right])) {
                right--;
                continue;
            }

            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
