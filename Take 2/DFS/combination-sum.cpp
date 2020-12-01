class Solution {
public:
    
    void combine(vector<int>& candidates, vector<int> cur, int start, int target, vector<vector<int>>& combinations) {
        int cur_sum = 0;
        for(auto& num : cur) {
            cur_sum += num;
        }
        if (cur_sum == target) {
            combinations.push_back(cur);
            return;
        }
        else if (cur_sum > target) return;
        for (int i = start; i < candidates.size(); i++) {
            int num = candidates[i];
            int pushes = 0;
            while(cur_sum + num <= target) {
                cur.push_back(candidates[i]);
                pushes++;
                combine(candidates, cur, i + 1, target, combinations);
                num += candidates[i];
                
            }
            for (int i = 0; i < pushes; i++) cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        vector<vector<int>> combinations;
        combine(candidates, cur, 0, target, combinations);
        return combinations;
    }
};