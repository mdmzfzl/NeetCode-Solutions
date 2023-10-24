/*
Problem: LeetCode 17 - Letter Combinations of a Phone Number

Description:
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
Return the answer in any order.

Intuition:
To find all possible letter combinations of a given phone number, we can use a backtracking approach. The idea is to generate all possible combinations by trying out different letters at each step, based on the digit mapping on a phone keypad.

Approach:
1. Define a mapping from each digit to the corresponding letters on a phone keypad.
2. Initialize an empty vector `combinations` to store the current combination.
3. Initialize an empty vector `result` to store all valid combinations.
4. Define a helper function `backtrack`:
   - If the index is equal to the length of the input digits, add the current combination to the `result` vector.
   - Otherwise:
     - Get the letters corresponding to the current digit.
     - Iterate through the letters:
       - Include the current letter in the combination.
       - Recursively call `backtrack` with the updated index.
       - Exclude the current letter from the combination (backtrack).
5. Call the `backtrack` function with the initial index of 0.
6. Return the `result` vector containing all valid combinations.

Time Complexity:
The time complexity is O(3^N * 4^M), where N is the number of digits that map to 3 letters (e.g., 2, 3, 4, 5, 6, 8) and M is the number of digits that map to 4 letters (e.g., 7, 9). For each digit, there can be up to 3 mappings (3^N) or 4 mappings (4^M), and we generate all possible combinations.

Space Complexity:
The space complexity is O(N + M), where N is the number of digits that map to 3 letters and M is the number of digits that map to 4 letters. This is the space used to store the combinations.
*/

class Solution {
  public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;

        if (digits.empty()) {
            return result;  // If the input is empty, return an empty result
        }

        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        string combination;  // Store the current combination
        backtrack(digits, mapping, 0, combination, result);  // Call the backtrack function to generate all valid combinations
        return result;
    }

  private:
    // Depth First Search (DFS) Backtracking function
    void backtrack(const string &digits, const vector<string> &mapping, int index, string &combination, vector<string> &result) {
        if (index == digits.length()) {
            result.push_back(combination);  // Add the current combination to the result
            return;
        }

        string letters = mapping[digits[index] - '0'];  // Get the corresponding letters for the current digit

        for (char letter : letters) {
            combination.push_back(letter);  // Add the letter to the current combination
            backtrack(digits, mapping, index + 1, combination, result);  // Recursively call with the next index
            combination.pop_back();  // Remove the last added letter (backtrack)
        }
    }
};

/*
// Breadth First Search((BFS)
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }

        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        queue<string> combinations;
        combinations.push("");

        while (!combinations.empty()) {
            string curr = combinations.front();
            combinations.pop();

            if (curr.length() == digits.length()) {
                result.push_back(curr);
                continue;
            }

            string letters = mapping[digits[curr.length()] - '0'];
            for (char letter : letters) {
                combinations.push(curr + letter);
            }
        }

        return result;
    }
};
*/

/*
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return vector<string>{};
        vector<string> ans;
        string curr;
        backtrack(curr, 0, digits, ans);
        return ans;
    }

private:
    unordered_map<char, vector<char>> dig2char = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };

    void backtrack(string & curr, int index, string & digits, vector<string> & ans) {
        if(curr.size() == digits.size()) {
            ans.push_back(curr);
            return;
        }
        vector<char> possibleLetters = dig2char[digits[index]];
        for(char c: possibleLetters) {
            curr.push_back(c);
            backtrack(curr, index + 1, digits, ans);
            curr.pop_back();
        }
    }
};
*/