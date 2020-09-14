class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        for (auto& c : s) {
            if (t.find(c) == string::npos)
                return false;
            else
                t[t.find(c)] = '#';
        }
        return true;
    }
};