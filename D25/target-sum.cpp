class Solution {
public:
    int dfs(vector<int>& nums, int v, int sum, int target, vector<vector<int>>& memo) {
        if(v == nums.size()) {
            if (sum == target) 
                return 1;
            return 0;
        }
        if(memo[v][sum + 1000] != INT_MIN)
            return memo[v][sum + 1000];
        int add = dfs(nums, v + 1, sum + nums[v], target, memo);
        int sub = dfs(nums, v + 1, sum - nums[v], target, memo);
        memo[v][sum + 1000] = add + sub;
        return memo[v][sum + 1000];
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<vector<int>> memo(nums.size(), vector<int>(2001, INT_MIN));
        if(nums.size() == 0) 
            return 0;
        int count = dfs(nums, 0, 0, S, memo);
        return count;
    }
};