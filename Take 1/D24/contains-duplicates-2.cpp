class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> pos;
        for(int i = 0; i < nums.size(); i++) {
            if (pos[nums[i]] == 0 && (nums[0] != nums[i] || i == 0)) pos[nums[i]] = i;
            else {
                if (i - pos[nums[i]] <= k) {
                    return true;
                }
                pos[nums[i]] = i;
            }
        }
        return false;
    }
};