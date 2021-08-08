class Solution {
public:
    
    int helper(int num_chars, int clipboard, int n, int cur_steps, vector<int>& dp) {
        if (num_chars > n) return INT_MAX;
        if (dp[num_chars] != INT_MAX) return dp[num_chars];
        if (num_chars == n) return cur_steps;
        dp[num_chars] = min(helper(num_chars * 2, num_chars, n, cur_steps + 2, dp), helper(num_chars + clipboard, clipboard, n, cur_steps + 1, dp));
        return dp[num_chars];
    }
    
    int minSteps(int n) {
        vector<int> dp(n + 1, INT_MAX);
        return helper(1, n, n, 0, dp);
    }
};