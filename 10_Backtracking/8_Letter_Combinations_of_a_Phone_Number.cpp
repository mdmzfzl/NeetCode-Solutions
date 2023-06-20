class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) 
            return result;
        
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        string current;
        backtrack(digits, 0, current, mapping, result);
        return result;
    }
    
private:
    void backtrack(const string& digits, int index, string& current, const vector<string>& mapping, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        int digit = digits[index] - '0';
        string letters = mapping[digit];
        
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(digits, index + 1, current, mapping, result);
            current.pop_back();
        }
    }
};

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