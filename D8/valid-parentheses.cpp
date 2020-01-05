#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<int> openings;
        for(auto& i : s) {
            if (i == '(' || i == '{' || i == '[') {
                openings.push(i);
                continue;
            }
            else if (openings.empty())
                return false;
            else if (i == ')' && openings.top() != '(')
                return false;
            else if (i == '}' && openings.top() != '{')
                return false;
            else if (i == ']' && openings.top() != '[')
                return false;
            openings.pop();
        }
        if(!openings.empty())
            return false;
        return true;
    }
};