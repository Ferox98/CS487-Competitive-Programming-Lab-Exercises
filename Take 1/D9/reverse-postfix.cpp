class Solution {
public:
    int toInt(string s) {
        stringstream ss(s);
        int val;
        ss >> val;
        return val;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for(int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "*" || tokens[i] == "+" || tokens[i] == "/" || tokens[i] == "-")             
            {
                int op2 = toInt(s.top());
                s.pop();
                int op1 = toInt(s.top());
                s.pop();
                int res;
                if (tokens[i] == "*") res = op1 * op2;
                else if (tokens[i] == "+") res = op1 + op2;
                else if (tokens[i] == "/") res = op1 / op2;
                else res = op1 - op2;
                s.push(to_string(res));
            }
            else {
                s.push(tokens[i]);
            }
        }
        return toInt(s.top());
    }
};