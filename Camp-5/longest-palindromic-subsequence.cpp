class Solution {
public:
    
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> sub_length(s.size(), vector<int>(s.size(), 0));
        for(int i = s.size() - 1; i >= 0; i--) {
            sub_length[i][i] = 1;
            for(int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j])
                    sub_length[i][j] = sub_length[i + 1][j - 1] + 2;
                else
                    sub_length[i][j] = max(sub_length[i + 1][j], sub_length[i][j - 1]);
            }
        }
        return sub_length[0][s.size() - 1];
    }
};