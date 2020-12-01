class Solution {
public:
    
    bool isValid(string& s) {
        stack<char> st;
        for (auto& c : s) {
            if (c == '(') {
                st.push(c);
            }
            else if (st.empty()) {
                return false;
            }
            else {
                st.pop();
            }
        }
        return st.empty();
    }
    
    vector<string> generate(int n, string s) {
        if (s.size() == n * 2) {
            if (isValid(s)) {
                return {s};
            }
            return {};
        }
        vector<string> res;
        s += '(';
        vector<string> out = generate(n, s);
        if (out.size() > 0) {
            for (auto& str : out) res.push_back(str);
        }
        s.pop_back();
        s += ')';
        out = generate(n, s);
        if (out.size() > 0) {
            for (auto& str : out) res.push_back(str);
        }
        return res;
    }
    
    vector<string> generateParenthesis(int n) {
        string str = "(";
        vector<string> res = generate(n, str);
        return res;
    }
};