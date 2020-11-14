class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() == 0) return false;
        vector<int> sums;
        sums.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            sums.push_back(nums[i] + sums[i - 1]);
        }
        for (int len = 2; len <= nums.size(); len++) {
            int i = 0, j = len - 1;
            while (j < nums.size()) {
                int sum = sums[j];
                int prev_sum = i > 0 ? sums[i - 1] : 0;
                sum -= prev_sum;
                if (k == 0 && sum == 0) return true;
                else if (k != 0 && sum % k == 0) return true;
                i++;
                j++;
            }
        }
        return false;
    }
};