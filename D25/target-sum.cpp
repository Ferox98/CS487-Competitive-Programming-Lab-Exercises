class Solution {
public:
    void dfs(vector<int>& nums, int v, int sum, int target, int& count) {
        if(v == nums.size() - 1) {
            sum += nums[v];
            if (sum == target) 
                count++;
            sum -= 2  * nums[v];
            if (sum == target)
                count++;
            return;
        }
        dfs(nums, v + 1, sum + nums[v], target, count);
        dfs(nums, v + 1, sum - nums[v], target, count);
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0) 
            return 0;
        int count = 0;
        dfs(nums, 0, 0, S, count);
        return count;
    }
};