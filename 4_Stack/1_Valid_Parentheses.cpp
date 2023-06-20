class Solution {
public:
    bool isValid(string s) {
        stack<char> stag;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if(stag.empty())
                    return false;
                if(s[i] == ')' && stag.top() != '(')
                    return false;
                if(s[i] == '}' && stag.top() != '{')
                    return false;
                if(s[i] == ']' && stag.top() != '[')
                    return false;
                stag.pop();
            }
            else {
                stag.push(s[i]);
            }
        }

        if (!stag.empty()) {
            return false;
        }

        return true;
    }
};