class Solution {

public:    
    int arr[100000];
    
    Solution() 
    { 
        arr[0] = 1;
        for (int i = 1; i < 100000; i++) arr[i] = -1;
    }
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.empty() || target < 0) return 0;
        if(target == 0) return 1;
        if(arr[target] != -1) return arr[target];
        long count = 0;
        for(int i = 0; i < nums.size(); i++)
            count += combinationSum4(nums, target - nums[i]);
        return arr[target] = count;
    }
};