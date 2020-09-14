class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.size() == 0) {
            return res;
        }
        // sort by increasing value of first element
        sort(intervals.begin(), intervals.end(), [](const vector<int> f_pair, const vector<int> s_pair) {
            if (f_pair[0] != s_pair[0]) {
                return f_pair[0] < s_pair[0];
            }
            return f_pair[1] < s_pair[1];
        }) ;
        
        res.push_back(intervals[0]);
        int idx = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= res[idx][1]) {
                res[idx][1] = max(intervals[i][1], res[idx][1]);
            }
           
            else {
                res.push_back(intervals[i]);
                idx++;
            }   
        }
        return res;
    }
};