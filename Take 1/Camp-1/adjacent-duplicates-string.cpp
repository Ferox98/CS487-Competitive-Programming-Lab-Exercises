class Solution {
public:
    int getKDuplicates(string& s, int k) {
        char prev = s[0];
        int count = 0, start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == prev) {
                count++;
                if (count == k) {
                    return start;
                }
            }
            else {
                start = i;
                count = 1;
                prev = s[i];
            }
        }
        return -1;
    }
    string removeDuplicates(string s, int k) {
        while(true) {
             int start_idx = getKDuplicates(s, k);
            if (start_idx == -1) break;
             s = s.substr(0, start_idx) + s.substr(start_idx + k);
        }
        return s;
    }
};