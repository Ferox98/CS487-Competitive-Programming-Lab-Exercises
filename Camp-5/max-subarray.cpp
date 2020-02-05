class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best_sum = INT_MIN;
        int cur_sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            cur_sum = max(nums[i], cur_sum + nums[i]);
            best_sum = max(best_sum, cur_sum);
        }
        return best_sum;
    }
};