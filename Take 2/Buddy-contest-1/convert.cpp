class Solution {
public:
    
    
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int, int> dp;
        int total_operations = 0;
        int max_multiplications = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int number = nums[i];
            if (nums[i] == 0) continue;
            else if (nums[i] == 1) {
                total_operations++;
                continue;
            }
            int cur_operations = 0;
            int multiplications = 0;
            while(nums[i] > 1) {
                if (nums[i] % 2 == 1) {
                    nums[i]--;
                    cur_operations++;
                    continue;
                }
                nums[i] /= 2;
                if (max_multiplications == 0) {
                    multiplications++;
                }
            }
            if (max_multiplications == 0) {
                max_multiplications = multiplications;
                cur_operations += max_multiplications;
            }
            if (nums[i] >= 1) cur_operations++;
            dp[number] = cur_operations;
            total_operations += cur_operations;
        }
        return total_operations;
    }
};