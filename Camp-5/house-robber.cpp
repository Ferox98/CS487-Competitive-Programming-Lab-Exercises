class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> total_stolen = nums;
        int max_stolen = max(total_stolen[0], total_stolen[1]);
        for(int i = 2; i < nums.size(); i++) {
            if (i - 3 >= 0) {
                total_stolen[i] = max(total_stolen[i - 3], total_stolen[i - 2]) + nums[i];        
            } 
            else
                total_stolen[i] = nums[i - 2] + nums[i];
            if (total_stolen[i] > max_stolen) max_stolen = total_stolen[i];
        }
        return max_stolen;
    }
};