class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> mp;
        vector<int> result(k, 0);
        for (auto& log : logs) {
            mp[log[0]].insert(log[1]);
        }
        
        for (auto& val: mp) {
            int n = val.second.size();
            if (n <= k) {
                result[n - 1]++;
            }
        }
        return result;
    }
};