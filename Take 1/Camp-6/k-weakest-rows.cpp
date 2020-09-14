class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int, int> strength_count;       
        for(int i = 0; i < mat.size(); i++) {
            int soldier_count = 0;
            for(int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 0) break;
                soldier_count++;
            }
            strength_count[i] = soldier_count;
        }
        vector<pair<int, int>> pairs;
        for (auto itr = strength_count.begin(); itr != strength_count.end(); ++itr)
            pairs.push_back(*itr);

        sort(pairs.begin(), pairs.end(), [=](std::pair<int, int>& a, std::pair<int, int>& b)
        {
            if (a.second != b.second)
                return a.second < b.second;
            return a.first < b.first;
        }
        );
        vector<int> res(k);
        for(int i = 0; i < k; i++)
            res[i] = pairs[i].first;
        return res;
    }
};