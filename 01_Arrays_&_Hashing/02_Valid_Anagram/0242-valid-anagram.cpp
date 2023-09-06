/*
Problem: LeetCode 242 - Valid Anagram

Description:
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Intuition:
To determine if two strings are valid anagrams, we can compare the counts of each character in both strings. If the counts of all characters are equal, the strings are valid anagrams.

Approach:
1. If the lengths of the two input strings s and t are not equal, return false.
2. Initialize an array of size 26 to store the counts of each character.
3. Iterate through each character in string s and increment its count in the array.
4. Iterate through each character in string t and decrement its count in the array.
5. If any count in the array is not zero, return false as the characters do not match.
6. Return true if all counts in the array are zero.

Time Complexity:
The time complexity of this approach is O(n), where n is the length of the input strings s and t. This is because we iterate through both strings once to update the counts of each character.

Space Complexity:
The space complexity is O(1), as we use a fixed-size array of size 26 to store the counts.
*/

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}
();

class Solution {
  public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        int count[26] = {0};

        for (char ch : s) {
            count[ch - 'a']++;
        }

        for (char ch : t) {
            count[ch - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }

        return true;
    }
};

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.size() != t.size())
//                 return false;

//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());

//         return s == t;
//     }
// };
