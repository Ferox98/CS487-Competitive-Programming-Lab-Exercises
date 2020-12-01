class Solution {
public:
    
    void permuteHelper(vector<int>& nums, vector<int> cur, vector<bool> discovered, vector<vector<int>>& permutations) {
        if (cur.size() == nums.size()) {
            permutations.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!discovered[i]) {
                cur.push_back(nums[i]);
                discovered[i] = true;
                permuteHelper(nums, cur, discovered, permutations);
                discovered[i] = false;
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<int> cur;
        vector<bool> discovered(nums.size(), false);
        permuteHelper(nums, cur, discovered, permutations);
        return permutations;
    }
};