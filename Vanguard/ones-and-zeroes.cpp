class Solution {
public:
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> count(strs.size(), pair<int, int>(0, 0));
        for (int i = 0; i < strs.size(); i++) { 
            int zeros = 0, ones = 0;
            for (auto& c : strs[i]) {
                if (c == '0') zeros++;
                else ones++;
            }
            count[i] = pair<int, int>(zeros, ones);
        }
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1)));
        for (int i = 0; i < strs.size(); i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    int zeros = count[i].first, ones = count[i].second;
                    if (zeros > j || ones > k) {
                        dp[i][j][k] = i == 0 ? 0 : dp[i - 1][j][k];
                       // cout << i << " , " << j << " , " << k << " , " << dp[i][j][k] << endl;
                        
                        continue;
                    }
                    dp[i][j][k] = i == 0 ? 1 : max(dp[i - 1][j][k], dp[i - 1][j - zeros][k - ones] + 1);
                    //cout << i << " , " << j << " , " << k << " ,, " << dp[i][j][k] << endl;
                }
            }
        }
        return dp[strs.size() - 1][m][n];
    }
};