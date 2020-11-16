class Solution {
public:
    
    vector<vector<int>> dp;
    
    int countWays(map<int, char> hash, string& s, int i, int j) {
        if (i > j) return 1;
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (i == j) {
            int idx = s[i] - '0';
            if ((int) hash[idx] == 0) return 0;
            return 1;
        }
        int idx = s[i] - '0';
        int count = 0;    
        if ((int) hash[idx] == 0) {
            dp[i][j] = 0;
            return count;
        }
        count += countWays(hash, s, i + 1, j);
        int num = stoi(string(s.begin() + i, s.begin() + i + 2));
        if ((int) hash[num] == 0) {
            dp[i][j] = count;
            return count;
        }
        count += countWays(hash, s, i + 2, j);
        dp[i][j] = count;
        return count;
    }
    
    int numDecodings(string s) {
        dp = vector<vector<int>>(101, vector<int>(101, -1));
        map<int, char> hash;
        char c = 'A';
        for (int i = 1; i <= 26; i++) {
            hash[i] = c;
            c++;
        }
        int counts = countWays(hash, s, 0, s.size() - 1);
        return counts;
    }
};