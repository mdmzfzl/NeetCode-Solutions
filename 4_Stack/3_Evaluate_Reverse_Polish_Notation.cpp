class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> stacc;

        for(int i = 0; i < tokens.size(); i++) {
            string Operator = tokens[i];

            if(Operator.size() >= 2 || isdigit(Operator[0])) {
                stacc.push(stoi(Operator));  // Pushing into stack if its not an operator 
                continue;
            }

            long long int Number_1, Number_2;
            Number_2 = stacc.top(); stacc.pop();
            Number_1 = stacc.top(); stacc.pop();
            
            if(Operator == "+") {
                stacc.push(Number_1 + Number_2);
            }
            else if(Operator == "-") {
                stacc.push(Number_1 - Number_2);
            }
            else if(Operator == "*") {
                stacc.push(Number_1 * Number_2);
            }
            else if(Operator == "/") {
                stacc.push(Number_1 / Number_2);
            }
        }

        return stacc.top();
    }
};

/*
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int num1, num2;
        for(auto i : tokens) {
            if(i == "+") ress(i);
            else if ( i == "-") ress(i);
            else if ( i == "*") ress(i);
            else if ( i == "/") ress(i);
            else st.push(stoi(i));
        }
        return st.top();
    }

private:
    stack<int> st;
    
    void ress(string op) {
        int num1 = st.top();
        st.pop();
        int num2 = st.top();
        st.pop();
        if(op == "+")
            st.push(num2+num1);
        else if(op == "-")
            st.push(num2-num1);
        else if(op == "*")
            st.push(num2*num1);
        else 
            st.push(num2/num1);
    }
};
*/