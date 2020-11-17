class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child_idx = 0, cookie_idx = 0;
        int content = 0;
        while(child_idx < g.size() && cookie_idx < s.size()) {
            while(cookie_idx < s.size() && g[child_idx] > s[cookie_idx]) cookie_idx++;
            if (cookie_idx == s.size()) break;
            content++;
            child_idx++;
            cookie_idx++;
        }
        return content;
    }
};