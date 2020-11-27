class Solution {
public:
    string thousandSeparator(int n) {
        string str = to_string(n);
        for (int i = str.size() - 4; i >= 0; i -= 3) {
            str.insert(i + 1, ".");
        }
        return str;
    }
};